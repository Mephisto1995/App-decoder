#ifndef SANITIZE_MANAGER_H
#define SANITIZE_MANAGER_H

#include <iostream>
#include <memory>
#include "IData.h"

class SanitizeManager
{
public:
	static SanitizeManager& GetInstance();

	bool IsDataSanitized(const std::shared_ptr<IData>& data);

	SanitizeManager(const SanitizeManager&) = delete;
	SanitizeManager(SanitizeManager&&) = delete;

	SanitizeManager& operator=(const SanitizeManager&) = delete;
	SanitizeManager& operator=(SanitizeManager&&) = delete;

private:
	SanitizeManager();
};

#endif // !SANITIZE_MANAGER_H