#include "CallDataExtraction.h"

CallDataExtraction::CallDataExtraction(const std::string& filePath) :
	mFilePath(filePath)
	, mFileHandler(mFilePath, std::ios::in | std::ios::binary)
{
	if (!mFileHandler.is_open())
	{
		std::cout << "CallDataExtraction::CallDataExtraction(): error on opening file at filePath: " + mFilePath << std::endl;
	}
}

CallDataExtraction::~CallDataExtraction()
{
	mFileHandler.close();
}

void CallDataExtraction::ProcessDataExtraction(std::shared_ptr<IData> outputObject, const int nextItemOffset)
{
	if (outputObject == nullptr)
	{
		return;
	}

	std::shared_ptr<Call> callObject = std::dynamic_pointer_cast<Call>(outputObject);

	if (callObject == nullptr)
	{
		return;
	}

	ExtractCallType(callObject, nextItemOffset);
	ExtractDateOfCall(callObject, nextItemOffset);
	ExtractPhoneNumberInformationStatus(callObject, nextItemOffset);
	ExtractSimData(callObject, nextItemOffset);
}

void CallDataExtraction::ExtractCallType(std::shared_ptr<Call>& callObject, const int nextItemOffset)
{
	mFileHandler.seekg(Constants::Decoding::Calls::STARTING_BYTE_OFFSET_TYPE_CALL + nextItemOffset, std::ios::beg);
	char byte;

	if (mFileHandler.read(&byte, sizeof(byte)))
	{
		Enums::ECallType callType;

		switch (byte)
		{
		case Constants::Decoding::Tokens::DIAL_TYPE:
			callType = Enums::CALL_TYPE_DIALED;
			break;
		case Constants::Decoding::Tokens::MISSED_TYPE:
			callType = Enums::CALL_TYPE_MISSED;
			break;
		case Constants::Decoding::Tokens::RECEIVED_TYPE:
			callType = Enums::CALL_TYPE_RECEIVED;
			break;
		default:
			std::cerr << "Unkown type: " << byte << std::endl;
			callType = Enums::CALL_TYPE_INVALID;
			break;
		}

		callObject->SetCallType(callType);
	}
	else
	{
		std::cout << "Unkown format, please investigate, format: " << byte << std::endl;
		return;
	}

	mFileHandler.seekg(Constants::RESET_FILE_POINTER, std::ios::beg);
}

void CallDataExtraction::ExtractDateOfCall(std::shared_ptr<Call>& callObject, const int nextItemOffset)
{
	mFileHandler.seekg(Constants::Decoding::Calls::STARTING_BYTE_OFFSET_DATE_CALL + nextItemOffset, std::ios::beg);

	std::time_t timeStamp = 0;
	const size_t bufferSize = 4;
	char buffer[bufferSize];
	std::memset(buffer, 0, bufferSize);

	if (mFileHandler.read(buffer, bufferSize))
	{
		std::memcpy(&timeStamp, buffer, sizeof(buffer));
	}

	// Convert to GMT
	std::tm* timeInfo = std::gmtime(&timeStamp);
	std::tm timeInfoNew;

	// Format the date and time as a string
	const char* format = "%d-%b-%y %H:%M:%S %p";
	char outputBuffer[256];
	std::strftime(outputBuffer, 256, format, timeInfo);

	std::string outputString(outputBuffer);
	callObject->SetDateInfoData(outputString);

	mFileHandler.seekg(Constants::RESET_FILE_POINTER, std::ios::beg);
}

void CallDataExtraction::ExtractPhoneNumberInformationStatus(std::shared_ptr<Call>& callObject, const int nextItemOffset)
{
	mFileHandler.seekg(Constants::Decoding::Calls::STARTING_BYTE_OFFSET_PHONE_NUMBER + nextItemOffset, std::ios::beg);
	const size_t bufferSize = 11;
	char buffer[bufferSize];
	std::memset(buffer, 0, bufferSize);

	if (mFileHandler.read(buffer, bufferSize))
	{
		std::string outputString(buffer);

		Enums::ECallType callType = callObject->GetCallType();

		if (callType != Enums::CALL_TYPE_INVALID)
		{
			switch (callType)
			{
			case Enums::CALL_TYPE_DIALED:
				callObject->SetTelTo(outputString);
				break;
			case Enums::CALL_TYPE_MISSED:
			case Enums::CALL_TYPE_RECEIVED:
				callObject->SetTelFrom(outputString);
				break;
			default:
				break;
			}
		}
	}

	mFileHandler.seekg(Constants::RESET_FILE_POINTER, std::ios::beg);
}

void CallDataExtraction::ExtractSimData(std::shared_ptr<Call>& callObject, const int nextItemOffset)
{
	mFileHandler.seekg(Constants::Decoding::Calls::STARTING_BYTE_OFFSET_SIM_DATA + nextItemOffset, std::ios::beg);

	if (mFileHandler.peek() == Constants::Decoding::Tokens::SIM_TOKEN)
	{
		const size_t bufferSize = 15;
		int j = 0;
		char buffer[bufferSize];
		char cleanBuffer[bufferSize + 1];

		// TODO spl: transform this kind of processing into a function and add it into Helpers class

		std::memset(buffer, 0, bufferSize);
		std::memset(cleanBuffer, 0, bufferSize + 1);

		if (mFileHandler.read(buffer, bufferSize))
		{
			for (int i = 0; i < bufferSize; ++i)
			{
				if (buffer[i] != Constants::Decoding::Tokens::NULL_TERMINATED_STRING)
				{
					cleanBuffer[j++] = buffer[i];
				}
			}

			cleanBuffer[((sizeof(buffer) == 0) ? 0 : bufferSize + 1)] = Constants::Decoding::Tokens::NULL_TERMINATED_STRING;

			std::string outputString(cleanBuffer);
			callObject->SetSim(outputString);
		}
	}

	mFileHandler.seekg(Constants::RESET_FILE_POINTER, std::ios::beg);
}