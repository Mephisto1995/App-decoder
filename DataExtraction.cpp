/*#include "DataExtraction.h"

DataExtraction::DataExtraction(const std::string& filePath) :
	mFilePath(filePath)
	, mFileHandler(mFilePath, std::ios::in | std::ios::binary)
{
	if (!mFileHandler.is_open())
	{
		std::cout << "DataExtraction::DataExtraction(): Cannot open file at path: " << mFilePath << "\n";
	}
}

void DataExtraction::ProcessDataExtraction(std::shared_ptr<IData> outputObject, const int nextItemOffset)
{
	std::cout << "DataExtraction::DecodeData(): " << nextItemOffset << "\n";
	SanitizeManager& sanitizeManager = SanitizeManager::GetInstance();

	if (outputObject == nullptr)
	{
		std::cout << "DataExtraction::DecodeData(): outputObject is nullptr\n";
		return;
	}

	if (std::shared_ptr<Call> callObj = std::dynamic_pointer_cast<Call>(outputObject))
	{
		DataExtractionCallObject(callObj, nextItemOffset);
		sanitizeManager.IsDataSanitized(callObj);
	}
	else if (std::shared_ptr<Phonebook> phonebookObj = std::dynamic_pointer_cast<Phonebook>(outputObject))
	{
		DataExtractionPhonebookObject(phonebookObj, nextItemOffset);
		sanitizeManager.IsDataSanitized(phonebookObj);
	}
	else
	{
		std::cout << "DataExtraction::DecodeData() error on outputObject: unrecognized child\n";
	}

	mFileHandler.close();
}

void DataExtraction::DataExtractionCallObject(std::shared_ptr<Call>& callObj, const int nextItemOffset)
{
	std::cout << "DataExtraction::DataExtractionCallObject()\n";

	ExtractCallType(callObj, nextItemOffset);
	ExtractDateOfCall(callObj, nextItemOffset);
	ExtractPhoneNumber(callObj, nextItemOffset);
	ExtractPhoneNumberInformationStatus(callObj, nextItemOffset);
	ExtractSimData(callObj, nextItemOffset);
}

void DataExtraction::DataExtractionPhonebookObject(std::shared_ptr<Phonebook>& phonebookObject, const int nextItemOffset)
{
	std::cout << "DataExtraction::DataExtractionPhonebookObject()\n";

	ExtractPhonebookNameEntry(phonebookObject, nextItemOffset);
	ExtractTelNumber(phonebookObject, nextItemOffset);
	ExtractHomeNumber(phonebookObject, nextItemOffset);
	ExtractOrganization(phonebookObject, nextItemOffset);
	ExtractEmail(phonebookObject, nextItemOffset);
	ExtractWorkPhone(phonebookObject, nextItemOffset);
	ExtractFax(phonebookObject, nextItemOffset);
}

void DataExtraction::ExtractCallType(std::shared_ptr<Call>& callObj, const int nextItemOffset)
{
	std::cout << "DataExtraction::ExtractCallType()\n";
}

void DataExtraction::ExtractDateOfCall(std::shared_ptr<Call>& callObj, const int nextItemOffset)
{
	std::cout << "DataExtraction::ExtractDateOfCall()\n";
}

void DataExtraction::ExtractPhoneNumber(std::shared_ptr<Call>& callObj, const int nextItemOffset)
{
	std::cout << "DataExtraction::ExtractPhoneNumber()\n";
}

void DataExtraction::ExtractPhoneNumberInformationStatus(std::shared_ptr<Call>& callObj, const int nextItemOffset)
{
	std::cout << "DataExtraction::ExtractPhoneNumberInformationStatus()\n";
}

void DataExtraction::ExtractSimData(std::shared_ptr<Call>& callObj, const int nextItemOffset)
{
	std::cout << "DataExtraction::ExtractSimData()\n";
}

void DataExtraction::ExtractPhonebookNameEntry(std::shared_ptr<Phonebook>& phonebookObject, const int nextItemOffset)
{
	std::cout << "DataExtraction::ExtractPhonebookNameEntry()\n";
}

void DataExtraction::ExtractTelNumber(std::shared_ptr<Phonebook>& phonebookObject, const int nextItemOffset)
{
	std::cout << "DataExtraction::ExtractTelNumber()\n";
}

void DataExtraction::ExtractHomeNumber(std::shared_ptr<Phonebook>& phonebookObject, const int nextItemOffset)
{
	std::cout << "DataExtraction::ExtractHomeNumber()\n";
}

void DataExtraction::ExtractOrganization(std::shared_ptr<Phonebook>& phonebookObject, const int nextItemOffset)
{
	std::cout << "DataExtraction::ExtractOrganization()\n";
}

void DataExtraction::ExtractEmail(std::shared_ptr<Phonebook>& phonebookObject, const int nextItemOffset)
{
	std::cout << "DataExtraction::ExtractEmail()\n";
}

void DataExtraction::ExtractWorkPhone(std::shared_ptr<Phonebook>& phonebookObject, const int nextItemOffset)
{
	std::cout << "DataExtraction::ExtractWorkPhone()\n";
}

void DataExtraction::ExtractFax(std::shared_ptr<Phonebook>& phonebookObject, const int nextItemOffset)
{
	std::cout << "DataExtraction::ExtractFax()\n";
}

void DataExtraction::SanitizeData(std::shared_ptr<IData>& outputObject)
{
	std::cout << "DataExtraction::SanitizeData()\n";
}*/