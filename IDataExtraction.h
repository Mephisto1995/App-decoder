#ifndef IDATA_EXTRACTION_H
#define IDATA_EXTRACTION_H

#include <memory>
#include "IData.h"

class IDataExtraction
{
public:
	virtual ~IDataExtraction() {}

	virtual void ProcessDataExtraction(std::shared_ptr<IData> outputObject, const int nextItemOffset) = 0;
};

#endif // !IDATA_EXTRACTION_H