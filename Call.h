#ifndef CALL_H
#define CALL_H

#include "Manager.h"
#include "IData.h"

class Call : public IData
{
public:
	Call();
	~Call();
	Call(const Call& other);
	Call(Call&& other) noexcept;

	Call& operator=(const Call& other);
	Call& operator=(Call&& other) noexcept;

	Utils::Enums::ECallType GetCallType() const;
	std::string GetTelFrom() const;
	std::string GetTelTo() const;
	std::string GetSim() const;
	std::string GetDateInfoData() const;
	std::string GetDuration() const;

	void SetCallType(const Utils::Enums::ECallType callType);
	void SetTelFrom(const std::string& telFrom);
	void SetTelTo(const std::string& telTo);
	void SetSim(const std::string& sim);
	void SetDateInfoData(const std::string& dateInfoData);
	void SetDuration(const std::string& duration);

private:
	Utils::Enums::ECallType mCallType;
	std::string mTelFrom;
	std::string mTelTo;
	std::string mSim;
	std::string mDateInfoData;
	std::string mDuration;
};

#endif // !CALL_H