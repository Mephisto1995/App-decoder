#include "Call.h"

Call::Call() :
	mId(HelperClass::GenerateRandomIds())
	, mCallType(Enums::CALL_TYPE_INVALID)
	, mTelFrom(Constants::Defaults::DEF_STRING_VAL)
	, mTelTo(Constants::Defaults::DEF_STRING_VAL)
	, mSim(Constants::Defaults::DEF_STRING_VAL)
	, mDateInfoData(Constants::Defaults::DEF_STRING_VAL)
	, mDuration(Constants::Defaults::DEF_STRING_VAL)
{}

Call::~Call() {}

Call::Call(const Call& other) :
	mId(other.mId)
	, mCallType(other.mCallType)
	, mTelFrom(other.mTelFrom)
	, mTelTo(other.mTelTo)
	, mSim(other.mSim)
	, mDateInfoData(other.mDateInfoData)
	, mDuration(other.mDuration)
{}

Call::Call(Call&& other) noexcept :
	mId(std::move(other.mId))
	, mCallType(std::move(other.mCallType))
	, mTelFrom(std::move(other.mTelFrom))
	, mTelTo(std::move(other.mTelTo))
	, mSim(std::move(other.mSim))
	, mDateInfoData(std::move(other.mDateInfoData))
	, mDuration(std::move(other.mDuration))
{}

Call& Call::operator=(const Call& other)
{
	if (this == &other)
	{
		return *this;
	}

	mId = other.mId;
	mCallType = other.mCallType;
	mTelFrom = other.mTelFrom;
	mTelTo = other.mTelTo;
	mSim = other.mSim;
	mDateInfoData = other.mDateInfoData;
	mDuration = other.mDuration;

	return *this;
}

Call& Call::operator=(Call&& other) noexcept
{
	if (this == &other)
	{
		return *this;
	}

	mId = std::move(other.mId);
	mCallType = std::move(other.mCallType);
	mTelFrom = std::move(other.mTelFrom);
	mTelTo = std::move(other.mTelTo);
	mSim = std::move(other.mSim);
	mDateInfoData = std::move(other.mDateInfoData);
	mDuration = std::move(other.mDuration);

	return *this;
}

int Call::GetId() const { return mId; }
Enums::ECallType Call::GetCallType() const { return mCallType; }
std::string Call::GetTelFrom() const { return mTelFrom; }
std::string Call::GetTelTo() const { return mTelTo; }
std::string Call::GetSim() const { return mSim; }
std::string Call::GetDateInfoData() const { return mDateInfoData; }
std::string Call::GetDuration() const { return mDuration; }

void Call::SetId(const int id) { mId = id; }
void Call::SetCallType(const Enums::ECallType callType) { mCallType = callType; }
void Call::SetTelFrom(const std::string& telFrom) { mTelFrom = telFrom; }
void Call::SetTelTo(const std::string& telTo) { mTelTo = telTo; }
void Call::SetSim(const std::string& sim) { mSim = sim; }
void Call::SetDateInfoData(const std::string& dateInfoData) { mDateInfoData = dateInfoData; }
void Call::SetDuration(const std::string& duration) { mDuration = duration; }