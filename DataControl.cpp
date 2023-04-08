#include "DataControl.h"

DataControl::DataControl() :
	mCallData()
	, mPhonebookData()
{}

void DataControl::AddCallData(const Call& call)
{
	mCallData.push_back(call);
}

void DataControl::AddPhonebookData(const Phonebook& phonebook)
{
	mPhonebookData.push_back(phonebook);
}

Phonebook& DataControl::GetPhonebookAt(const int index)
{
	return mPhonebookData.at(index);
}

const int DataControl::GetPhonebookSize() const
{
	return mPhonebookData.size();
}