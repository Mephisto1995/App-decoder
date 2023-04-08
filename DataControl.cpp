#include "DataControl.h"

DataControl::DataControl() :
	mDataEntry()
{}

void DataControl::AddDataEntry(const std::shared_ptr<IData>& data)
{
	mDataEntry.push_back(data);
}