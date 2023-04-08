#include "Phonebook.h"

Phonebook::Phonebook() :
	mIsDeleted(Utils::Constants::DEF_BOOL_VAL)
	, mName(Utils::Constants::DEF_STRING_VAL)
	, mTelNumber(Utils::Constants::DEF_STRING_VAL)
	, mFaxNumber(Utils::Constants::DEF_STRING_VAL)
	, mHomeNumber(Utils::Constants::DEF_STRING_VAL)
	, mWorkNumber(Utils::Constants::DEF_STRING_VAL)
	, mEmail(Utils::Constants::DEF_STRING_VAL)
	, mOrganization(Utils::Constants::DEF_STRING_VAL)
{}

Phonebook::~Phonebook() {}

Phonebook::Phonebook(const Phonebook& other) :
	mIsDeleted(other.mIsDeleted)
	, mName(other.mName)
	, mTelNumber(other.mTelNumber)
	, mFaxNumber(other.mFaxNumber)
	, mHomeNumber(other.mHomeNumber)
	, mWorkNumber(other.mWorkNumber)
	, mEmail(other.mEmail)
	, mOrganization(other.mOrganization)
{}

Phonebook::Phonebook(Phonebook&& other) noexcept :
	mIsDeleted(std::move(other.mIsDeleted))
	, mName(std::move(other.mName))
	, mTelNumber(std::move(other.mTelNumber))
	, mFaxNumber(std::move(other.mFaxNumber))
	, mHomeNumber(std::move(other.mHomeNumber))
	, mWorkNumber(std::move(other.mWorkNumber))
	, mEmail(std::move(other.mEmail))
	, mOrganization(std::move(other.mOrganization))
{}

Phonebook& Phonebook::operator=(const Phonebook& other)
{
	if (this == &other)
	{
		return *this;
	}

	mIsDeleted = other.mIsDeleted;
	mName = other.mName;
	mTelNumber = other.mTelNumber;
	mFaxNumber = other.mFaxNumber;
	mHomeNumber = other.mHomeNumber;
	mWorkNumber = other.mWorkNumber;
	mEmail = other.mEmail;
	mOrganization = other.mOrganization;

	return *this;
}

Phonebook& Phonebook::operator=(Phonebook&& other) noexcept
{
	if (this == &other)
	{
		return *this;
	}

	mIsDeleted = std::move(other.mIsDeleted);
	mName = std::move(other.mName);
	mTelNumber = std::move(other.mTelNumber);
	mFaxNumber = std::move(other.mFaxNumber);
	mHomeNumber = std::move(other.mHomeNumber);
	mWorkNumber = std::move(other.mWorkNumber);
	mEmail = std::move(other.mEmail);
	mOrganization = std::move(other.mOrganization);

	return *this;
}

bool Phonebook::GetIsDeleted() const { return mIsDeleted; }
std::string Phonebook::GetName() const { return mName; }
std::string Phonebook::GetTelNumber() const { return mTelNumber; }
std::string Phonebook::GetFaxNumber() const { return mFaxNumber; }
std::string Phonebook::GetHomeNumber() const { return mHomeNumber; }
std::string Phonebook::GetWorkNumber() const { return mWorkNumber; }
std::string Phonebook::GetEmail() const { return mEmail; }
std::string Phonebook::GetOrganization() const { return mOrganization; }

void Phonebook::SetIsDeleted(const bool isDeleted) { mIsDeleted = isDeleted; }
void Phonebook::SetName(const std::string& name) { mName = name; }
void Phonebook::SetTelNumber(const std::string& telNumber) { mTelNumber = telNumber; }
void Phonebook::SetFaxNumber(const std::string& faxNumber) { mFaxNumber = faxNumber; }
void Phonebook::SetHomeNumber(const std::string& homeNumber) { mHomeNumber = homeNumber; }
void Phonebook::SetWorkNumber(const std::string& workNumber) { mWorkNumber = workNumber; }
void Phonebook::SetEmail(const std::string& email) { mEmail = email; }
void Phonebook::SetOrganization(const std::string& organization) { mOrganization = organization; }