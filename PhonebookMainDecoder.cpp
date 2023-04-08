#include "PhonebookMainDecoder.h"

using namespace Utils::Constants;

PhonebookMainDecoder::PhonebookMainDecoder(const std::string& filePath) :
	mFilePath(filePath)
{}

void PhonebookMainDecoder::DecodeData(Phonebook& outputObject, const int nextItemOffset)
{
	std::ifstream fileManager(mFilePath, std::ios::in | std::ios::binary);

	if (!fileManager.is_open())
	{
		std::cerr << "Failed to open file!" << std::endl;
		return;
	}

	// Finding the name of the entry (ph.nr.1, ph.nr.2, etc.);
	{
		fileManager.seekg(Decoding::Phonebook::STARTING_BYTE_OFFSET_NAME + nextItemOffset, std::ios::beg);
		const size_t bufferSize = 15;
		char buffer[bufferSize];
		char cleanBuffer[bufferSize + 1];
		int j = 0;

		// TODO spl: transform this kind of processing into a function and add it into Helpers class

		std::memset(buffer, 0, bufferSize);
		std::memset(cleanBuffer, 0, bufferSize + 1);

		if (fileManager.read(buffer, bufferSize))
		{
			for (int i = 0; i < bufferSize; ++i)
			{
				if (buffer[i] != Decoding::Tokens::NULL_TERMINATED_STRING)
				{
					cleanBuffer[j++] = buffer[i];
				}
			}

			cleanBuffer[bufferSize] = Decoding::Tokens::NULL_TERMINATED_STRING;

			std::string outputString(cleanBuffer);
			outputObject.SetName(outputString);
		}

		fileManager.seekg(RESET_FILE_POINTER, std::ios::beg);
	}

	// Find the tel numbers
	{
		fileManager.seekg(Decoding::Phonebook::STARTING_BYTE_OFFSET_TEL + nextItemOffset, std::ios::beg);

		// Check if first bit is Null Terminated String token.
		char byte = fileManager.peek();
		if (byte == Decoding::Tokens::NULL_TERMINATED_STRING)
		{
			// Go to the next bit.
			fileManager.seekg(Decoding::Phonebook::STARTING_BYTE_OFFSET_TEL + nextItemOffset + 1, std::ios::beg);
		}

		const size_t bufferSize = 14;
		char buffer[bufferSize];

		// TODO spl: transform this kind of processing into a function and add it into Helpers class

		std::memset(buffer, 0, bufferSize);

		if (fileManager.read(buffer, bufferSize))
		{
			std::string outputString(buffer);
			outputObject.SetTelNumber(outputString);
		}

		fileManager.seekg(RESET_FILE_POINTER, std::ios::beg);
	}
}