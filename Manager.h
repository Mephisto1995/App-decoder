#ifndef MANAGER_H
#define MANAGER_H

#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <algorithm>
#include <cctype>
#include <ctime>
#include <memory>

#include "DataControl.h"
#include "Constants.h"

#include "CallDataExtraction.h"
#include "PhonebookMainDataExtraction.h"
#include "PhonebookDetailsDataExtraction.h"

#include "Call.h"
#include "Phonebook.h"

#pragma warning(disable:4996)

//class Phonebook;

namespace Utils
{
	namespace Helpers
	{
		class HelperClass
		{
		public:
			static bool AreAllCharactersAlphas(const char* buffer, const int bufferSize);
			/*static bool AreAllCharactersDigits(const char* buffer, const int bufferSize);
			static bool IsEmailValid(const char* buffer, const int bufferSize);
			static bool HasDataBeenDeletedFromDetails(const Phonebook& data);
			static bool IsDataSanitized(const char* buffer, const int bufferSize);*/

			static int GenerateRandomIds();

			static void InitApp();
		};

		class FileIterationHelper
		{
		public:
			static void IterateCallsFile(DataControl& dataControl);
			static void IteratePhonebookFiles(DataControl& dataControl);

		private:
			static std::vector<std::shared_ptr<IData>> mLocalPhonebookEntries;
		};

		class BufferContainerExtractionLogicHelper
		{
		public:
			//static void 
		};
	}
}

#endif // !MANAGER_H