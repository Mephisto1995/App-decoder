#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Constants.h"
#include "IData.h"
#include <string>

class Phonebook : public IData
{
public:
	Phonebook();
	~Phonebook();
	Phonebook(const Phonebook& other);
	Phonebook(Phonebook&& other) noexcept ;

	Phonebook& operator=(const Phonebook& other);
	Phonebook& operator=(Phonebook&& other) noexcept;

	int GetId() const;
	bool GetIsDeleted() const;
	std::string GetName() const;
	std::string GetTelNumber() const;
	std::string GetFaxNumber() const;
	std::string GetHomeNumber() const;
	std::string GetWorkNumber() const;
	std::string GetEmail() const;
	std::string GetOrganization() const;

	void SetId(const int id);
	void SetIsDeleted(const bool isDeleted);
	void SetName(const std::string& name);
	void SetTelNumber(const std::string& telNumber);
	void SetFaxNumber(const std::string& faxNumber);
	void SetHomeNumber(const std::string& homeNumber);
	void SetWorkNumber(const std::string& workNumber);
	void SetEmail(const std::string& email);
	void SetOrganization(const std::string& organization);

private:
	int mId;
	bool mIsDeleted;

	std::string mName;
	std::string mTelNumber;
	std::string mFaxNumber;
	std::string mHomeNumber;
	std::string mWorkNumber;
	std::string mEmail;
	std::string mOrganization;
};
#endif // !PHONEBOOK_H