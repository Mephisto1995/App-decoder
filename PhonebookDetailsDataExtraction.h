#ifndef PHONEBOOK_DETAILS_DATA_EXTRACTION_H
#define PHONEBOOK_DETAILS_DATA_EXTRACTION_H

#include "Manager.h"
#include "IDataExtraction.h"
#include "SanitizeManager.h"

class Phonebook;

class PhonebookDetailsDataExtraction : public IDataExtraction
{
public:
	PhonebookDetailsDataExtraction(const std::string& filePath);
	~PhonebookDetailsDataExtraction();
	void ProcessDataExtraction(std::shared_ptr<IData> outputObject, const int nextItemOffset);

private:
	void ExtractHomeNumber(std::shared_ptr<Phonebook>& phonebookObject, const int nextItemOffset);
	void ExtractOrganization(std::shared_ptr<Phonebook>& phonebookObject, const int nextItemOffset);
	void ExtractEmail(std::shared_ptr<Phonebook>& phonebookObject, const int nextItemOffset);
	void ExtractWorkPhone(std::shared_ptr<Phonebook>& phonebookObject, const int nextItemOffset);
	void ExtractFax(std::shared_ptr<Phonebook>& phonebookObject, const int nextItemOffset);

private:
	std::string mFilePath;
	std::fstream mFileHandler;
};

#endif // !PHONEBOOK_DETAILS_DATA_EXTRACTION_H