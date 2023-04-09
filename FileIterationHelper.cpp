#include "FileIterationHelper.h"

std::vector<std::shared_ptr<IData>> FileIterationHelper::mLocalPhonebookEntries;

void FileIterationHelper::IterateCallsFile(DataControl& dataControl)
{
	std::ifstream fileManager(Constants::FilePaths::FILE_PATH_CALLS, std::ios::in | std::ios::binary);
	std::unique_ptr<IDataExtraction> dataExtraction = std::make_unique<CallDataExtraction>(Constants::FilePaths::FILE_PATH_CALLS);
	int indexOffset = 0;

	if (!fileManager.is_open())
	{
		std::cout << "FileIterationHelper::IterateCallsFile() cannot open file: " << Constants::FilePaths::FILE_PATH_CALLS << "\n";
		return;
	}

	while (!fileManager.eof())
	{
		if (fileManager.peek() != Constants::Decoding::Tokens::NULL_TERMINATED_STRING)
		{
			std::shared_ptr<IData> callObject = std::make_shared<Call>();
			dataExtraction->ProcessDataExtraction(callObject, Constants::NextItemOffsets::NEXT_ITEM_OFFSET_CALLS);
			dataControl.AddDataEntry(callObject);

			indexOffset += Constants::NextItemOffsets::NEXT_ITEM_OFFSET_CALLS;
			fileManager.seekg(indexOffset, std::ios::beg);
		}
		else
		{
			fileManager.close();
			break;
		}
	}
}

void FileIterationHelper::IteratePhonebookFiles(DataControl& dataControl)
{
	std::ifstream fileManager(Constants::FilePaths::FILE_PATH_PHONEBOOK_MAIN, std::ios::in | std::ios::binary);
	std::unique_ptr<IDataExtraction> dataExtraction = std::make_unique<PhonebookMainDataExtraction>(Constants::FilePaths::FILE_PATH_CALLS);
	int indexOffset = 0;

	while (!fileManager.eof())
	{
		if (fileManager.peek() != Constants::Decoding::Tokens::NULL_TERMINATED_STRING)
		{
			std::shared_ptr<IData> phonebookObject = std::make_shared<Phonebook>();
			dataExtraction->ProcessDataExtraction(phonebookObject, indexOffset);
			mLocalPhonebookEntries.push_back(phonebookObject);

			indexOffset += Constants::NextItemOffsets::NEXT_ITEM_OFFSET_PHONEBOOK_MAIN;
			fileManager.seekg(indexOffset, std::ios::beg);
		}
		else
		{
			fileManager.close();
			break;
		}
	}

	fileManager.open(Constants::FilePaths::FILE_PATH_PHONEBOOK_MAIN, std::ios::in | std::ios::binary);
	dataExtraction = std::make_unique<PhonebookDetailsDataExtraction>(Constants::FilePaths::FILE_PATH_CALLS);
	indexOffset = 0;
	const int localPhonebookEntriesSize = mLocalPhonebookEntries.size();

	for (int phonebookEntriesIndex = 0; phonebookEntriesIndex < localPhonebookEntriesSize; ++phonebookEntriesIndex)
	{
		std::shared_ptr<Phonebook> phonebookObject = std::dynamic_pointer_cast<Phonebook>(mLocalPhonebookEntries.at(phonebookEntriesIndex));

		if (phonebookObject != nullptr)
		{
			dataExtraction->ProcessDataExtraction(phonebookObject, indexOffset);
			SanitizeManager& instance = SanitizeManager::GetInstance();
			bool isDataSanitized = instance.IsDataSanitized(phonebookObject);
			phonebookObject->SetIsDeleted(!isDataSanitized);
			dataControl.AddDataEntry(phonebookObject);
			indexOffset += Constants::NextItemOffsets::NEXT_ITEM_OFFSET_PHONEBOOK_DETAILS;
			fileManager.seekg(indexOffset, std::ios::beg);
		}
	}

	fileManager.close();
}