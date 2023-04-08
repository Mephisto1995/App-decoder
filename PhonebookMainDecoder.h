#ifndef PHONEBOOK_MAIN_DECODER_H
#define PHONEBOOK_MAIN_DECODER_H

#include "Phonebook.h"

class PhonebookMainDecoder
{
public:
	PhonebookMainDecoder(const std::string& filePath);

	void DecodeData(Phonebook& outputObject, const int nextItemOffset);

private:
	std::string mFilePath;
};

#endif // !PHONEBOOK_MAIN_DECODER_H