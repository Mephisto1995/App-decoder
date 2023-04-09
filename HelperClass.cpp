#include "HelperClass.h"

int HelperClass::GenerateRandomIds()
{
	std::srand(std::time(nullptr));
	return std::rand();
}

void HelperClass::InitApp()
{
	DataControl dataControl;

	FileIterationHelper::IterateCallsFile(dataControl);
	FileIterationHelper::IteratePhonebookFiles(dataControl);
}