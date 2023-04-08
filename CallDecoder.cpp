#include "CallDecoder.h"

using namespace Utils::Constants;

CallDecoder::CallDecoder(const std::string& filePath) :
	mFilePath(filePath)
{}

void CallDecoder::DecodeData(Call& objectOutput, const int nextItemOffset)
{
	std::ifstream fileManager(mFilePath, std::ios::in | std::ios::binary);

	if (!fileManager.is_open())
	{
		std::cerr << "Failed to open file!" << std::endl;
		return;
	}

	// Calculating the type of call (Dialed/Missed/Received)
	{
		fileManager.seekg(Decoding::Calls::STARTING_BYTE_OFFSET_TYPE_CALL + nextItemOffset, std::ios::beg);
		char byte;

		if (fileManager.read(&byte, sizeof(byte)))
		{
			Utils::Enums::ECallType callType;

			switch (byte)
			{
			case Decoding::Tokens::DIAL_TYPE:
				callType = Utils::Enums::CALL_TYPE_DIALED;
				break;
			case Decoding::Tokens::MISSED_TYPE:
				callType = Utils::Enums::CALL_TYPE_MISSED;
				break;
			case Decoding::Tokens::RECEIVED_TYPE:
				callType = Utils::Enums::CALL_TYPE_RECEIVED;
				break;
			default:
				std::cerr << "Unkown type: " << byte << std::endl;
				callType = Utils::Enums::CALL_TYPE_INVALID;
				break;
			}

			objectOutput.SetCallType(callType);
		}
		else
		{
			std::cout << "Unkown format, please investigate, format: " << byte << std::endl;
			return;
		}

		fileManager.seekg(RESET_FILE_POINTER, std::ios::beg);
	}

	// Calculating the date of the call and the time;
	{
		fileManager.seekg(Decoding::Calls::STARTING_BYTE_OFFSET_DATE_CALL + nextItemOffset, std::ios::beg);

		std::time_t timeStamp = 0;
		const size_t bufferSize = 4;
		char buffer[bufferSize];
		std::memset(buffer, 0, bufferSize);
		if (fileManager.read(buffer, bufferSize))
		{
			std::memcpy(&timeStamp, buffer, sizeof(buffer));
		}

		// Convert to GMT
		std::tm* timeInfo = std::gmtime(&timeStamp);

		// Format the date and time as a string
		const char* format = "%d-%b-%y %H:%M:%S %p";
		char outputBuffer[256];
		std::strftime(outputBuffer, 256, format, timeInfo);

		std::string outputString(outputBuffer);
		objectOutput.SetDateInfoData(outputString);

		fileManager.seekg(RESET_FILE_POINTER, std::ios::beg);
	}

	// Calculating the number of the phone and if it's a tel from or tel to type of call;
	{
		fileManager.seekg(Decoding::Calls::STARTING_BYTE_OFFSET_PHONE_NUMBER + nextItemOffset, std::ios::beg);
		const size_t bufferSize = 11;
		char buffer[bufferSize];
		std::memset(buffer, 0, bufferSize);
		if (fileManager.read(buffer, bufferSize))
		{
			std::string outputString(buffer);

			auto callType = objectOutput.GetCallType();

			if (callType != Utils::Enums::CALL_TYPE_INVALID)
			{
				switch (callType)
				{
				case Utils::Enums::CALL_TYPE_DIALED:
					objectOutput.SetTelTo(outputString);
					break;
				case Utils::Enums::CALL_TYPE_MISSED:
				case Utils::Enums::CALL_TYPE_RECEIVED:
					objectOutput.SetTelFrom(outputString);
					break;
				default:
					break;
				}
			}
		}
	}

	// Calculating the sim data
	{
		fileManager.seekg(Decoding::Calls::STARTING_BYTE_OFFSET_SIM_DATA + nextItemOffset, std::ios::beg);

		if (fileManager.peek() == Decoding::Tokens::SIM_TOKEN)
		{
			const size_t bufferSize = 15;
			int j = 0;
			char buffer[bufferSize];
			char cleanBuffer[bufferSize + 1];

			// TODO spl: transform this kind of processing into a function and add it into Helpers class

			std::memset(buffer, 0, bufferSize);
			std::memset(cleanBuffer, 0, bufferSize + 1);

			if (fileManager.read(buffer, bufferSize))
			{
				for (int i = 0; i < bufferSize; ++i)
				{
					if (buffer[i] != '\0')
					{
						cleanBuffer[j++] = buffer[i];
					}
				}

				cleanBuffer[bufferSize] = '\0';

				std::string outputString(cleanBuffer);
				objectOutput.SetSim(outputString);
			}
		}
	}

	fileManager.close();
}