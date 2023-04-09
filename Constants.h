#ifndef CONSTANTS_H
#define CONSTANTS_H

namespace Constants
{
	namespace Defaults
	{
		constexpr int DEF_INT_VAL = -1;
		constexpr char DEF_STRING_VAL[] = "Unkown";
		constexpr bool DEF_BOOL_VAL = false;
	}

	namespace NextItemOffsets
	{
		constexpr int NEXT_ITEM_OFFSET_CALLS = 106;
		constexpr int NEXT_ITEM_OFFSET_PHONEBOOK_MAIN = 86;
		constexpr int NEXT_ITEM_OFFSET_PHONEBOOK_DETAILS = 232;
	}

	constexpr int RESET_FILE_POINTER = 0;

	namespace FilePaths
	{
		constexpr char FILE_PATH_CALLS[] = "Resources/Calls.bin";
		constexpr char FILE_PATH_PHONEBOOK_MAIN[] = "Resources/Phonebook_Main.bin";
		constexpr char FILE_PATH_PHONEBOOK_DETAILS[] = "Resources/Phonebook_Details.bin";
	}

	namespace BufferSize
	{
		namespace Calls
		{
			constexpr int BUFFER_SIZE_DATE = 4;
			constexpr int BUFFER_SIZE_PHONE_NUMBER = 11;
			constexpr int BUFFER_SIZE_SIM_DATA = 15;
		}

		namespace Phonebook
		{
			constexpr int BUFFER_SIZE_NAME_ENTRY = 15;
			constexpr int BUFFER_SIZE_TEL_NUMBER = 14;

			constexpr int BUFFER_SIZE_HOME_PHONE_NUMBER = 14;
			constexpr int BUFFER_SIZE_ORGANIZATION = 19;
			constexpr int BUFFER_SIZE_EMAIL = 17;
			constexpr int BUFFER_SIZE_WORK_PHONE_NUMBER = 8;
			constexpr int BUFFER_SIZE_FAX_NUMBER = 14;
		}
	}

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

#endif // !CONSTANTS_H