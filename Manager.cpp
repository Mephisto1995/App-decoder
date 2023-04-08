#include "Manager.h"

namespace Utils
{
	namespace Helpers
	{
		bool HelperClass::AreAllCharactersDigits(const char* buffer, const int bufferSize)
		{
			bool areAllDigits = true;

			for (int i = 0; i < bufferSize; ++i)
			{
				if (buffer[i] != Utils::Constants::Decoding::Tokens::NULL_TERMINATED_STRING && buffer[i] != Utils::Constants::Decoding::Tokens::SPACE_TOKEN)
				{
					areAllDigits = std::isdigit(buffer[i]);

					if (!areAllDigits)
					{
						return areAllDigits;
					}
				}
			}

			return areAllDigits;
		}

		bool HelperClass::AreAllCharactersAlphas(const char* buffer, const int bufferSize)
		{
			bool areAllAlphas = false;

			for (int i = 0; i < bufferSize; ++i)
			{
				if (buffer[i] != Utils::Constants::Decoding::Tokens::NULL_TERMINATED_STRING && buffer[i] != buffer[i] != Utils::Constants::Decoding::Tokens::SPACE_TOKEN)
				{
					areAllAlphas = std::isalpha(buffer[i]);

					if (!areAllAlphas)
					{
						return areAllAlphas;
					}
				}
			}

			return areAllAlphas;
		}

		bool HelperClass::IsEmailValid(const char* buffer, const int bufferSize)
		{
			const char* result = std::strchr(buffer, Utils::Constants::Decoding::Tokens::AT_TOKEN);
			return result != nullptr;
		}

		bool HelperClass::IsDataSanitized(const char* buffer, const int bufferSize)
		{
			bool isDataSanitized = false;

			for (int i = 0; i < bufferSize; ++i)
			{
				if (std::isalpha(buffer[i]) || std::isdigit(buffer[i]))
				{
					isDataSanitized = true;
					return isDataSanitized;
				}
			}

			return isDataSanitized;
		}
		
		bool HelperClass::HasDataBeenDeletedFromDetails(const Phonebook& data)
		{
			bool retVal = true;

			retVal &= IsDataSanitized(data.GetFaxNumber().c_str(), data.GetFaxNumber().length());
			retVal &= IsDataSanitized(data.GetHomeNumber().c_str(), data.GetHomeNumber().length());
			retVal &= IsDataSanitized(data.GetWorkNumber().c_str(), data.GetWorkNumber().length());

			retVal &= IsDataSanitized(data.GetEmail().c_str(), data.GetWorkNumber().length());
			retVal &= IsDataSanitized(data.GetOrganization().c_str(), data.GetOrganization().length());

			return retVal;
		}
	}
}