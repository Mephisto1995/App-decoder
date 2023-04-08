#include "PhonebookMainDataExtraction.h"

PhonebookMainDataExtraction::PhonebookMainDataExtraction(const std::string& filePath) :
	mFilePath(filePath)
	, mFileHandler(mFilePath, std::ios::in | std::ios::binary)
{
	if (!mFileHandler.is_open())
	{
		std::cout << "PhonebookMainDataExtraction::PhonebookMainDataExtraction(): error on opening file at filePath: " + mFilePath << std::endl;
	}
}

PhonebookMainDataExtraction::~PhonebookMainDataExtraction()
{
	mFileHandler.close();
}

void PhonebookMainDataExtraction::ProcessDataExtraction(std::shared_ptr<IData> outputObject, const int nextItemOffset)
{
	if (outputObject == nullptr)
	{
		return;
	}

	std::shared_ptr<Phonebook>phonebookObject = std::dynamic_pointer_cast<Phonebook>(outputObject);

	if (phonebookObject == nullptr)
	{
		return;
	}

	ExtractPhonebookNameEntry(phonebookObject, nextItemOffset);
	ExtractTelNumber(phonebookObject, nextItemOffset);
}

void PhonebookMainDataExtraction::ExtractPhonebookNameEntry(std::shared_ptr<Phonebook>& phonebookObject, const int nextItemOffset)
{
	mFileHandler.seekg(Utils::Constants::Decoding::Phonebook::STARTING_BYTE_OFFSET_NAME + nextItemOffset, std::ios::beg);
	const size_t bufferSize = 15;
	char buffer[bufferSize];
	char cleanBuffer[bufferSize + 1];
	int j = 0;

	// TODO spl: transform this kind of processing into a function and add it into Helpers class

	std::memset(buffer, 0, bufferSize);
	std::memset(cleanBuffer, 0, bufferSize + 1);

	if (mFileHandler.read(buffer, bufferSize))
	{
		for (int i = 0; i < bufferSize; ++i)
		{
			if (buffer[i] != Utils::Constants::Decoding::Tokens::NULL_TERMINATED_STRING)
			{
				cleanBuffer[j++] = buffer[i];
			}
		}

		cleanBuffer[bufferSize] = Utils::Constants::Decoding::Tokens::NULL_TERMINATED_STRING;

		std::string outputString(cleanBuffer);
		phonebookObject->SetName(outputString);
	}

	mFileHandler.seekg(Utils::Constants::RESET_FILE_POINTER, std::ios::beg);
}

void PhonebookMainDataExtraction::ExtractTelNumber(std::shared_ptr<Phonebook>& phonebookObject, const int nextItemOffset)
{
	mFileHandler.seekg(Utils::Constants::Decoding::Phonebook::STARTING_BYTE_OFFSET_TEL + nextItemOffset, std::ios::beg);

	// Check if first bit is Null Terminated String token.
	char byte = mFileHandler.peek();
	if (byte == Utils::Constants::Decoding::Tokens::NULL_TERMINATED_STRING)
	{
		// Go to the next bit.
		mFileHandler.seekg(Utils::Constants::Decoding::Phonebook::STARTING_BYTE_OFFSET_TEL + nextItemOffset + 1, std::ios::beg);
	}

	const size_t bufferSize = 14;
	char buffer[bufferSize];

	// TODO spl: transform this kind of processing into a function and add it into Helpers class

	std::memset(buffer, 0, bufferSize);

	if (mFileHandler.read(buffer, bufferSize))
	{
		std::string outputString(buffer);
		phonebookObject->SetTelNumber(outputString);
	}

	mFileHandler.seekg(Utils::Constants::RESET_FILE_POINTER, std::ios::beg);
}