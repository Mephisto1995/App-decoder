#ifndef MANAGER_H
#define MANAGER_H

#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <algorithm>
#include <cctype>
#include <ctime>

#include "Phonebook.h"

#pragma warning(disable:4996)

class Phonebook;

namespace Utils
{
	namespace Constants
	{
		constexpr int DEF_INT_VAL = -1;
		constexpr char DEF_STRING_VAL[] = "Unkown";
		constexpr bool DEF_BOOL_VAL = false;

		constexpr int CALLS_NEXT_ITEM_OFFSET = 106;
		constexpr int PHONEBOOK_MAIN_NEXT_ITEM_OFFSET = 86;
		constexpr int PHONEBOOK_DETAILS_NEXT_ITEM_OFFSET = 232;

		constexpr int RESET_FILE_POINTER = 0;

		namespace Decoding
		{
			namespace Calls
			{
				constexpr int STARTING_BYTE_OFFSET_TYPE_CALL = 8; // Used to determine if it's missed/received/dial
				constexpr int STARTING_BYTE_OFFSET_DATE_CALL = 12;
				constexpr int STARTING_BYTE_OFFSET_PHONE_NUMBER = 58;
				constexpr int STARTING_BYTE_OFFSET_SIM_DATA = 16;
			}

			namespace Phonebook
			{
				// Phonebook Main
				constexpr int STARTING_BYTE_OFFSET_NAME = 0; // for phone nr... caching
				constexpr int STARTING_BYTE_OFFSET_TEL = 42;

				// Phonebook Details
				constexpr int STARTING_BYTE_OFFSET_HOME_PHONE_NUMBER = 0;
				constexpr int STARTING_BYTE_OFFSET_ORGANIZATION = 42;
				constexpr int STARTING_BYTE_OFFSET_EMAIL = 84;
				constexpr int STARTING_BYTE_OFFSET_WORK_PHONE_NUMBER = 145;
				constexpr int STARTING_BYTE_OFFSET_FAX = 187;
			}

			namespace Tokens
			{
				constexpr char DIAL_TYPE = '\0';
				constexpr char MISSED_TYPE = '@';
				constexpr char RECEIVED_TYPE = '€';

				constexpr char SIM_TOKEN = 's';
				constexpr char AT_TOKEN = '@';
				constexpr char DOT_TOKEN = '.';
				constexpr char NULL_TERMINATED_STRING = '\0';
				constexpr char SPACE_TOKEN = ' ';
			}
		}
	}

	namespace Helpers
	{
		class HelperClass
		{
		public:
			static bool AreAllCharactersDigits(const char* buffer, const int bufferSize);
			static bool AreAllCharactersAlphas(const char* buffer, const int bufferSize);
			static bool IsEmailValid(const char* buffer, const int bufferSize);
			static bool HasDataBeenDeletedFromDetails(const Phonebook& data);
			static bool IsDataSanitized(const char* buffer, const int bufferSize);
		};
	}

	namespace Enums
	{
		enum ECallType : int
		{
			CALL_TYPE_INVALID = -1,
			CALL_TYPE_DIALED,
			CALL_TYPE_MISSED,
			CALL_TYPE_RECEIVED,

			NUM_CALL_TYPES
		};
	}
}

#endif // !MANAGER_H