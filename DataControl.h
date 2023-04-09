#ifndef DATA_CONTROL_H
#define DATA_CONTROL_H

#include <memory>
#include <vector>

#include "IData.h"

class DataControl
{
public:
	DataControl();
	void AddDataEntry(const std::shared_ptr<IData>& data);

private:
	std::vector<std::shared_ptr<IData>> mDataEntry;
};

#endif // !DATA_CONTROL_H