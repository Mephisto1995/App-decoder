#ifndef CALL_H
#define CALL_H

#include "Constants.h"
#include "Enums.h";
#include "IData.h"
#include <string>

class Call : public IData
{
public:
	Call();
	~Call();
	Call(const Call& other);
	Call(Call&& other) noexcept;

	Call& operator=(const Call& other);
	Call& operator=(Call&& other) noexcept;

	int GetId() const;
	Enums::ECallType GetCallType() const;
	std::string GetTelFrom() const;
	std::string GetTelTo() const;
	std::string GetSim() const;
	std::string GetDateInfoData() const;
	std::string GetDuration() const;

	void SetId(const int id);
	void SetCallType(const Enums::ECallType callType);
	void SetTelFrom(const std::string& telFrom);
	void SetTelTo(const std::string& telTo);
	void SetSim(const std::string& sim);
	void SetDateInfoData(const std::string& dateInfoData);
	void SetDuration(const std::string& duration);

private:
	int mId;
	Enums::ECallType mCallType;
	std::string mTelFrom;
	std::string mTelTo;
	std::string mSim;
	std::string mDateInfoData;
	std::string mDuration;
};

#endif // !CALL_H