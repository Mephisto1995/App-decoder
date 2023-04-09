#include "Phonebook.h"

Phonebook::Phonebook() :
	mId(HelperClass::GenerateRandomIds())
	, mIsDeleted(Constants::Defaults::DEF_BOOL_VAL)
	, mName(Constants::Defaults::DEF_STRING_VAL)
	, mTelNumber(Constants::Defaults::DEF_STRING_VAL)
	, mFaxNumber(Constants::Defaults::DEF_STRING_VAL)
	, mHomeNumber(Constants::Defaults::DEF_STRING_VAL)
	, mWorkNumber(Constants::Defaults::DEF_STRING_VAL)
	, mEmail(Constants::Defaults::DEF_STRING_VAL)
	, mOrganization(Constants::Defaults::DEF_STRING_VAL)
{}

Phonebook::~Phonebook() {}

Phonebook::Phonebook(const Phonebook& other) :
	mId(other.mId)
	, mIsDeleted(other.mIsDeleted)
	, mName(other.mName)
	, mTelNumber(other.mTelNumber)
	, mFaxNumber(other.mFaxNumber)
	, mHomeNumber(other.mHomeNumber)
	, mWorkNumber(other.mWorkNumber)
	, mEmail(other.mEmail)
	, mOrganization(other.mOrganization)
{}

Phonebook::Phonebook(Phonebook&& other) noexcept :
	mId(std::move(other.mId))
	, mIsDeleted(std::move(other.mIsDeleted))
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

	mId = other.mId;
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

	mId = std::move(other.mId);
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

int Phonebook::GetId() const { return mId; }
bool Phonebook::GetIsDeleted() const { return mIsDeleted; }
std::string Phonebook::GetName() const { return mName; }
std::string Phonebook::GetTelNumber() const { return mTelNumber; }
std::string Phonebook::GetFaxNumber() const { return mFaxNumber; }
std::string Phonebook::GetHomeNumber() const { return mHomeNumber; }
std::string Phonebook::GetWorkNumber() const { return mWorkNumber; }
std::string Phonebook::GetEmail() const { return mEmail; }
std::string Phonebook::GetOrganization() const { return mOrganization; }

void Phonebook::SetId(const int id) { mId = id; }
void Phonebook::SetIsDeleted(const bool isDeleted) { mIsDeleted = isDeleted; }
void Phonebook::SetName(const std::string& name) { mName = name; }
void Phonebook::SetTelNumber(const std::string& telNumber) { mTelNumber = telNumber; }
void Phonebook::SetFaxNumber(const std::string& faxNumber) { mFaxNumber = faxNumber; }
void Phonebook::SetHomeNumber(const std::string& homeNumber) { mHomeNumber = homeNumber; }
void Phonebook::SetWorkNumber(const std::string& workNumber) { mWorkNumber = workNumber; }
void Phonebook::SetEmail(const std::string& email) { mEmail = email; }
void Phonebook::SetOrganization(const std::string& organization) { mOrganization = organization; }