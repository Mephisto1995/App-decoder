#ifndef PHONEBOOK_MAIN_DATA_EXTRACTION_H
#define PHONEBOOK_MAIN_DATA_EXTRACTION_H

#include "IDataExtraction.h"

class Phonebook;

class PhonebookMainDataExtraction : public IDataExtraction
{
public:
	PhonebookMainDataExtraction(const std::string& filePath);
	~PhonebookMainDataExtraction();
	void ProcessDataExtraction(std::shared_ptr<IData> outputObject, const int nextItemOffset);

private:
	void ExtractPhonebookNameEntry(std::shared_ptr<Phonebook>& phonebookObject, const int nextItemOffset);
	void ExtractTelNumber(std::shared_ptr<Phonebook>& phonebookObject, const int nextItemOffset);

private:
	std::string mFilePath;
	std::fstream mFileHandler;
};

#endif // !PHONEBOOK_MAIN_DATA_EXTRACTION_H