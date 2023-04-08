#ifndef DATA_CONTROL_H
#define DATA_CONTROL_H

#include "Call.h"
#include "Phonebook.h"

class DataControl
{
public:
	DataControl();

	void AddCallData(const Call& call);
	void AddPhonebookData(const Phonebook& phonebook);

	Phonebook& GetPhonebookAt(const int index);
	const int GetPhonebookSize() const;

private:
	std::list<Call> mCallData;
	std::vector<Phonebook> mPhonebookData;
};

#endif // !DATA_CONTROL_H