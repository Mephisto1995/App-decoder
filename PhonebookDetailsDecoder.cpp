#include "PhonebookDetailsDecoder.h"

using namespace Utils::Constants;

PhonebookDetailsDecoder::PhonebookDetailsDecoder(const std::string& filePath) :
	mFilePath(filePath)
{}

void PhonebookDetailsDecoder::DecodeData(Phonebook& outputObject, const int nextItemOffset)
{
	std::ifstream fileManager(mFilePath, std::ios::in | std::ios::binary);

	if (!fileManager.is_open())
	{
		std::cerr << "Failed to open file!" << std::endl;
		return;
	}

	// Finding the home phone number
	{
		fileManager.seekg(Decoding::Phonebook::STARTING_BYTE_OFFSET_HOME_PHONE_NUMBER + nextItemOffset, std::ios::beg);
		const size_t bufferSize = 14;
		char buffer[bufferSize];
		char cleanBuffer[bufferSize + 1];
		int j = 0;

		std::memset(buffer, 0, bufferSize);
		std::memset(cleanBuffer, 0, bufferSize + 1);

		if (fileManager.read(buffer, bufferSize))
		{
			for (int i = 0; i < bufferSize; ++i)
			{
				if (buffer[i] != Utils::Constants::Decoding::Tokens::NULL_TERMINATED_STRING)
				{
					cleanBuffer[j++] = buffer[i];
				}
			}

			cleanBuffer[((sizeof(buffer) == 0) ? 0 : bufferSize)] = Decoding::Tokens::NULL_TERMINATED_STRING;
			std::string outputString(cleanBuffer);
			outputObject.SetHomeNumber(outputString);
		}

		fileManager.seekg(RESET_FILE_POINTER, std::ios::beg);
	}

	// Finding the organization
	{
		fileManager.seekg(Decoding::Phonebook::STARTING_BYTE_OFFSET_ORGANIZATION + nextItemOffset, std::ios::beg);
		const size_t bufferSize = 19;
		char buffer[bufferSize];
		char cleanBuffer[bufferSize + 1];
		int j = 0;

		std::memset(buffer, 0, bufferSize);
		std::memset(cleanBuffer, 0, bufferSize + 1);

		if (fileManager.read(buffer, bufferSize))
		{
			for (int i = 0; i < bufferSize; ++i)
			{
				if (buffer[i] != Utils::Constants::Decoding::Tokens::NULL_TERMINATED_STRING)
				{
					cleanBuffer[j++] = buffer[i];
				}
			}

			cleanBuffer[((sizeof(buffer) == 0) ? 0 : bufferSize)] = Decoding::Tokens::NULL_TERMINATED_STRING;
			std::string outputString(cleanBuffer);
			outputObject.SetOrganization(outputString);
		}

		fileManager.seekg(RESET_FILE_POINTER, std::ios::beg);
	}

	// Finding the email
	{
		fileManager.seekg(Decoding::Phonebook::STARTING_BYTE_OFFSET_EMAIL + nextItemOffset, std::ios::beg);
		const size_t bufferSize = 17;
		char buffer[bufferSize];
		char cleanBuffer[bufferSize + 1];
		int j = 0;

		std::memset(buffer, 0, bufferSize);
		std::memset(cleanBuffer, 0, bufferSize + 1);

		if (fileManager.read(buffer, bufferSize))
		{
			for (int i = 0; i < bufferSize; ++i)
			{
				if (buffer[i] != Utils::Constants::Decoding::Tokens::NULL_TERMINATED_STRING)
				{
					cleanBuffer[j++] = buffer[i];
				}
			}

			cleanBuffer[((sizeof(buffer) == 0) ? 0 : bufferSize)] = Decoding::Tokens::NULL_TERMINATED_STRING;
			std::string outputString(cleanBuffer);
			outputObject.SetEmail(outputString);
		}

		fileManager.seekg(RESET_FILE_POINTER, std::ios::beg);
	}

	// Finding the work phone
	{
		fileManager.seekg(Decoding::Phonebook::STARTING_BYTE_OFFSET_WORK_PHONE_NUMBER + nextItemOffset, std::ios::beg);
		const size_t bufferSize = 8;
		char buffer[bufferSize];
		char cleanBuffer[bufferSize + 1];
		int j = 0;

		std::memset(buffer, 0, bufferSize);
		std::memset(cleanBuffer, 0, bufferSize + 1);

		if (fileManager.read(buffer, bufferSize))
		{
			for (int i = 0; i < bufferSize; ++i)
			{
				if (buffer[i] != Utils::Constants::Decoding::Tokens::NULL_TERMINATED_STRING)
				{
					cleanBuffer[j++] = buffer[i];
				}
			}

			cleanBuffer[((sizeof(buffer) == 0) ? 0 : bufferSize)] = Decoding::Tokens::NULL_TERMINATED_STRING;
			std::string outputString(cleanBuffer);
			outputObject.SetWorkNumber(outputString);
		}

		fileManager.seekg(RESET_FILE_POINTER, std::ios::beg);
	}

	// Finding the fax number
	{
		fileManager.seekg(Decoding::Phonebook::STARTING_BYTE_OFFSET_FAX + nextItemOffset, std::ios::beg);
		const size_t bufferSize = 14;
		char buffer[bufferSize];
		char cleanBuffer[bufferSize + 1];
		int j = 0;

		std::memset(buffer, 0, bufferSize);
		std::memset(cleanBuffer, 0, bufferSize + 1);

		if (fileManager.read(buffer, bufferSize))
		{
			for (int i = 0; i < bufferSize; ++i)
			{
				if (buffer[i] != Utils::Constants::Decoding::Tokens::NULL_TERMINATED_STRING)
				{
					cleanBuffer[j++] = buffer[i];
				}
			}

			cleanBuffer[((sizeof(buffer) == 0) ? 0 : bufferSize)] = Decoding::Tokens::NULL_TERMINATED_STRING;
			std::string outputString(cleanBuffer);
			outputObject.SetFaxNumber(outputString);
		}

		fileManager.seekg(RESET_FILE_POINTER, std::ios::beg);
	}

	// Sanitize the data to find out if we have garbage or not.
	// If we have garbage in all of them, it means the data has been deleted.
	{
		bool isDataSanitized = Utils::Helpers::HelperClass::HasDataBeenDeletedFromDetails(outputObject);
		outputObject.SetIsDeleted(isDataSanitized);
	}
}