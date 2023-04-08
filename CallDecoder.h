#ifndef CALL_DECODER_H
#define CALL_DECODER_H

#include "Call.h"

class CallDecoder
{
public:
	CallDecoder(const std::string& filePath);

	void DecodeData(Call& objectOutput, const int nextItemOffset);

private:
	std::string mFilePath;
};

#endif