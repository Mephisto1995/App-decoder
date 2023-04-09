#ifndef FILE_ITERATION_HELPER_H
#define FILE_ITERATION_HELPER_H

#include <iostream>
#include <vector>
#include <fstream>
#include <memory>

#include "Constants.h"
#include "DataControl.h"

#include "IDataExtraction.h"
#include "CallDataExtraction.h"
#include "PhonebookDetailsDataExtraction.h"
#include "PhonebookMainDataExtraction.h"

#include "Call.h"
#include "Phonebook.h"

class FileIterationHelper
{
public:
	static void IterateCallsFile(DataControl& dataControl);
	static void IteratePhonebookFiles(DataControl& dataControl);

private:
	static std::vector<std::shared_ptr<IData>> mLocalPhonebookEntries;
};

#endif // !FILE_ITERATION_HELPER_H