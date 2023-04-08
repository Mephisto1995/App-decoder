#include "Manager.h"

#include "Call.h";
#include "Phonebook.h"

#include "CallDecoder.h";
#include "PhonebookMainDecoder.h";
#include "PhonebookDetailsDecoder.h";
#include "DataControl.h"

#pragma warning(disable:4996)

void main()
{
    std::string callsFilePath = "Resources/Calls.bin";
    std::string phonebookMainPath = "Resources/Phonebook_Main.bin";
    std::string phonebookDetailsPath = "Resources/Phonebook_Details.bin";

    std::fstream fileManager(callsFilePath, std::ios::in | std::ios::binary);

    // TODO spl: try to find a way to use polymorphism for decoding and call/phonebook classes, 
    // so it can be more abstract.

    CallDecoder callDecoder(callsFilePath);
    DataControl dataControl;
    int indexOffset = 0;

    // TODO spl: find a way to clean the main function; maybe move this into some static helper functions

    while (!fileManager.eof())
    {
        // Peek the first character, if it's not null terminator, proceed to next item
        char byte = fileManager.peek();

        if (byte != Utils::Constants::Decoding::Tokens::NULL_TERMINATED_STRING)
        {
            Call callData;
            callDecoder.DecodeData(callData, indexOffset);
            dataControl.AddCallData(callData);

            indexOffset += Utils::Constants::CALLS_NEXT_ITEM_OFFSET;
            fileManager.seekg(indexOffset, std::ios::beg);
        }
        else
        {
            // Reached the end of our data, we can end the iteration process;
            break;
        }
    }

    fileManager.close();

    fileManager.open(phonebookMainPath, std::ios::in | std::ios::binary);
    indexOffset = 0;

    PhonebookMainDecoder phonebookMainDecoder(phonebookMainPath);

    while (!fileManager.eof())
    {
        const size_t bufferSize = 4;
        char buffer[bufferSize];
        bool isAlpha = false;

        if (fileManager.read(buffer, bufferSize) && Utils::Helpers::HelperClass::AreAllCharactersAlphas(buffer, bufferSize))
        {
            Phonebook phonebook;
            phonebookMainDecoder.DecodeData(phonebook, indexOffset);
            dataControl.AddPhonebookData(phonebook);
        }
        else
        {
            // Reached end of relevant info, we can break;
            break;
        }

        indexOffset += Utils::Constants::PHONEBOOK_MAIN_NEXT_ITEM_OFFSET;
        fileManager.seekg(indexOffset, std::ios::beg);
    }

    fileManager.close();

    fileManager.open(phonebookDetailsPath, std::ios::in | std::ios::binary);
    indexOffset = 0;

    PhonebookDetailsDecoder phonebookDetailsDecoder(phonebookDetailsPath);
    const int size = dataControl.GetPhonebookSize();

    for (int i = 0; i < size; ++i)
    {
        Phonebook& phonebook = dataControl.GetPhonebookAt(i);
        phonebookDetailsDecoder.DecodeData(phonebook, indexOffset);

        indexOffset += Utils::Constants::PHONEBOOK_DETAILS_NEXT_ITEM_OFFSET;
        fileManager.seekg(indexOffset, std::ios::beg);
    }

    fileManager.close();
}