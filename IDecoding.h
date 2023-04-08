#ifndef I_DECODING_H
#define I_DECODING_H

#include <memory>
#include "IData.h"

class IDecoding
{
public:
	virtual void DecodeData(std::shared_ptr<IData>& outputObject, const int nextItemOffset) = 0;
};

#endif // !I_DECODING_H