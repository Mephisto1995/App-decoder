#include "PhonebookDetailsDataExtraction.h"

PhonebookDetailsDataExtraction::PhonebookDetailsDataExtraction(const std::string& filePath) :
	mFilePath(filePath)
	, mFileHandler(mFilePath, std::ios::in | std::ios::beg)
{
	if (!mFileHandler.is_open())
	{
		std::cout << "PhonebookDetailsDataExtraction::PhonebookDetailsDataExtraction(): error on opening file at filePath: " + mFilePath << std::endl;
	}
}

PhonebookDetailsDataExtraction::~PhonebookDetailsDataExtraction()
{
	mFileHandler.close();
}

void PhonebookDetailsDataExtraction::ProcessDataExtraction(std::shared_ptr<IData> outputObject, const int nextItemOffset)
{
	if (outputObject == nullptr)
	{
		return;
	}

	std::shared_ptr<Phonebook> phonebookObject = std::dynamic_pointer_cast<Phonebook>(outputObject);

	if (phonebookObject == nullptr)
	{
		return;
	}

	ExtractHomeNumber(phonebookObject, nextItemOffset);
	ExtractOrganization(phonebookObject, nextItemOffset);
	ExtractEmail(phonebookObject, nextItemOffset);
	ExtractWorkPhone(phonebookObject, nextItemOffset);
	ExtractFax(phonebookObject, nextItemOffset);
}

void PhonebookDetailsDataExtraction::ExtractHomeNumber(std::shared_ptr<Phonebook>& phonebookObject, const int nextItemOffset)
{
	mFileHandler.seekg(Utils::Constants::Decoding::Phonebook::STARTING_BYTE_OFFSET_HOME_PHONE_NUMBER + nextItemOffset, std::ios::beg);
	const size_t bufferSize = 14;
	char buffer[bufferSize];
	char cleanBuffer[bufferSize + 1];
	int j = 0;

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

		cleanBuffer[((sizeof(buffer) == 0) ? 0 : bufferSize)] = Utils::Constants::Decoding::Tokens::NULL_TERMINATED_STRING;
		std::string outputString(cleanBuffer);
		phonebookObject->SetHomeNumber(outputString);
	}

	mFileHandler.seekg(Utils::Constants::RESET_FILE_POINTER, std::ios::beg);
}

void PhonebookDetailsDataExtraction::ExtractOrganization(std::shared_ptr<Phonebook>& phonebookObject, const int nextItemOffset)
{
	mFileHandler.seekg(Utils::Constants::Decoding::Phonebook::STARTING_BYTE_OFFSET_ORGANIZATION + nextItemOffset, std::ios::beg);
	const size_t bufferSize = 19;
	char buffer[bufferSize];
	char cleanBuffer[bufferSize + 1];
	int j = 0;

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

		cleanBuffer[((sizeof(buffer) == 0) ? 0 : bufferSize)] = Utils::Constants::Decoding::Tokens::NULL_TERMINATED_STRING;
		std::string outputString(cleanBuffer);
		phonebookObject->SetOrganization(outputString);
	}

	mFileHandler.seekg(Utils::Constants::RESET_FILE_POINTER, std::ios::beg);
}

void PhonebookDetailsDataExtraction::ExtractEmail(std::shared_ptr<Phonebook>& phonebookObject, const int nextItemOffset)
{
	mFileHandler.seekg(Utils::Constants::Decoding::Phonebook::STARTING_BYTE_OFFSET_EMAIL + nextItemOffset, std::ios::beg);
	const size_t bufferSize = 17;
	char buffer[bufferSize];
	char cleanBuffer[bufferSize + 1];
	int j = 0;

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

		cleanBuffer[((sizeof(buffer) == 0) ? 0 : bufferSize)] = Utils::Constants::Decoding::Tokens::NULL_TERMINATED_STRING;
		std::string outputString(cleanBuffer);
		phonebookObject->SetEmail(outputString);
	}

	mFileHandler.seekg(Utils::Constants::RESET_FILE_POINTER, std::ios::beg);
}

void PhonebookDetailsDataExtraction::ExtractWorkPhone(std::shared_ptr<Phonebook>& phonebookObject, const int nextItemOffset)
{
	mFileHandler.seekg(Utils::Constants::Decoding::Phonebook::STARTING_BYTE_OFFSET_WORK_PHONE_NUMBER + nextItemOffset, std::ios::beg);
	const size_t bufferSize = 8;
	char buffer[bufferSize];
	char cleanBuffer[bufferSize + 1];
	int j = 0;

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

		cleanBuffer[((sizeof(buffer) == 0) ? 0 : bufferSize)] = Utils::Constants::Decoding::Tokens::NULL_TERMINATED_STRING;
		std::string outputString(cleanBuffer);
		phonebookObject->SetWorkNumber(outputString);
	}

	mFileHandler.seekg(Utils::Constants::RESET_FILE_POINTER, std::ios::beg);
}

void PhonebookDetailsDataExtraction::ExtractFax(std::shared_ptr<Phonebook>& phonebookObject, const int nextItemOffset)
{
	mFileHandler.seekg(Utils::Constants::Decoding::Phonebook::STARTING_BYTE_OFFSET_FAX + nextItemOffset, std::ios::beg);
	const size_t bufferSize = 14;
	char buffer[bufferSize];
	char cleanBuffer[bufferSize + 1];
	int j = 0;

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

		cleanBuffer[((sizeof(buffer) == 0) ? 0 : bufferSize)] = Utils::Constants::Decoding::Tokens::NULL_TERMINATED_STRING;
		std::string outputString(cleanBuffer);
		phonebookObject->SetFaxNumber(outputString);
	}

	mFileHandler.seekg(Utils::Constants::RESET_FILE_POINTER, std::ios::beg);
}