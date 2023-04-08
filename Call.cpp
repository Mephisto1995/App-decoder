#include "Call.h"

Call::Call() :
	mCallType(Utils::Enums::CALL_TYPE_INVALID)
	, mTelFrom(Utils::Constants::DEF_STRING_VAL)
	, mTelTo(Utils::Constants::DEF_STRING_VAL)
	, mSim(Utils::Constants::DEF_STRING_VAL)
	, mDateInfoData(Utils::Constants::DEF_STRING_VAL)
	, mDuration(Utils::Constants::DEF_STRING_VAL)
{}

Call::~Call() {}

Call::Call(const Call& other) :
	mCallType(other.mCallType)
	, mTelFrom(other.mTelFrom)
	, mTelTo(other.mTelTo)
	, mSim(other.mSim)
	, mDateInfoData(other.mDateInfoData)
	, mDuration(other.mDuration)
{}

Call::Call(Call&& other) noexcept :
	mCallType(std::move(other.mCallType))
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

	mCallType = std::move(other.mCallType);
	mTelFrom = std::move(other.mTelFrom);
	mTelTo = std::move(other.mTelTo);
	mSim = std::move(other.mSim);
	mDateInfoData = std::move(other.mDateInfoData);
	mDuration = std::move(other.mDuration);

	return *this;
}

Utils::Enums::ECallType Call::GetCallType() const { return mCallType; }
std::string Call::GetTelFrom() const { return mTelFrom; }
std::string Call::GetTelTo() const { return mTelTo; }
std::string Call::GetSim() const { return mSim; }
std::string Call::GetDateInfoData() const { return mDateInfoData; }
std::string Call::GetDuration() const { return mDuration; }

void Call::SetCallType(const Utils::Enums::ECallType callType) { mCallType = callType; }
void Call::SetTelFrom(const std::string& telFrom) { mTelFrom = telFrom; }
void Call::SetTelTo(const std::string& telTo) { mTelTo = telTo; }
void Call::SetSim(const std::string& sim) { mSim = sim; }
void Call::SetDateInfoData(const std::string& dateInfoData) { mDateInfoData = dateInfoData; }
void Call::SetDuration(const std::string& duration) { mDuration = duration; }