#ifndef CALL_DATA_EXTRACTION_H
#define CALL_DATA_EXTRACTION_H

#include <iostream>
#include <fstream>

#include "Constants.h"
#include "Enums.h"
#include "IDataExtraction.h"

class Call;

class CallDataExtraction : public IDataExtraction
{
public:
	CallDataExtraction(const std::string& filePath);
	~CallDataExtraction();

	void ProcessDataExtraction(std::shared_ptr<IData> outputObject, const int nextItemOffset) override;

private:
	void ExtractCallType(std::shared_ptr<Call>& callObject, const int nextItemOffset);
	void ExtractDateOfCall(std::shared_ptr<Call>& callObject, const int nextItemOffset);
	void ExtractPhoneNumberInformationStatus(std::shared_ptr<Call>& callObject, const int nextItemOffset); // tel from / tel to (spent 10 minutes and I'm not proud of it)
	void ExtractSimData(std::shared_ptr<Call>& callObject, const int nextItemOffset);

private:
	std::string mFilePath;
	std::fstream mFileHandler;
};

#endif // !CALL_DATA_EXTRACTION_H