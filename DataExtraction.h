#ifndef DATA_EXTRACTION_H
#define DATA_EXTRACTION_H

/*#include "Manager.h"
#include "IDataExtraction.h"

#include "Call.h"
#include "Phonebook.h"

#include "SanitizeManager.h"

class DataExtraction : public IDataExtraction
{
public:
	DataExtraction(const std::string& filePath);

	void ProcessDataExtraction(std::shared_ptr<IData> outputObject, const int nextItemOffset) override;
	void ChangeFilePath(const std::string& filePath);

private:
	void DataExtractionCallObject(std::shared_ptr<Call>& callObject, const int nextItemOffset);
	void DataExtractionPhonebookObject(std::shared_ptr<Phonebook>& phonebookObject, const int nextItemOffset);

	// Calls.bin
	void ExtractCallType(std::shared_ptr<Call>& callObject, const int nextItemOffset);
	void ExtractDateOfCall(std::shared_ptr<Call>& callObject, const int nextItemOffset);
	void ExtractPhoneNumber(std::shared_ptr<Call>& callObject, const int nextItemOffset);
	void ExtractPhoneNumberInformationStatus(std::shared_ptr<Call>& callObject, const int nextItemOffset); // tel from / tel to (spent 10 minutes and I'm not proud of it)
	void ExtractSimData(std::shared_ptr<Call>& callObject, const int nextItemOffset);
	
	// Phonebook_Main.bin
	void ExtractPhonebookNameEntry(std::shared_ptr<Phonebook>& phonebookObject, const int nextItemOffset);
	void ExtractTelNumber(std::shared_ptr<Phonebook>& phonebookObject, const int nextItemOffset);

	// Phonebook_Details.bin
	void ExtractHomeNumber(std::shared_ptr<Phonebook>& phonebookObject, const int nextItemOffset);
	void ExtractOrganization(std::shared_ptr<Phonebook>& phonebookObject, const int nextItemOffset);
	void ExtractEmail(std::shared_ptr<Phonebook>& phonebookObject, const int nextItemOffset);
	void ExtractWorkPhone(std::shared_ptr<Phonebook>& phonebookObject, const int nextItemOffset);
	void ExtractFax(std::shared_ptr<Phonebook>& phonebookObject, const int nextItemOffset);

	void SanitizeData(std::shared_ptr<IData>& outputObject); // if data was deleted, set IsDeleted() to true;

private:
	std::string mFilePath;
	std::ifstream mFileHandler;
};*/

#endif // !DATA_EXTRACTION_H