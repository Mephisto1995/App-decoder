#include "SanitizeManager.h"

SanitizeManager::SanitizeManager() {}

SanitizeManager& SanitizeManager::GetInstance()
{
	std::cout << "SanitizeManager::GetInstance()\n";

	static SanitizeManager Instance;
	return Instance;
}

bool SanitizeManager::IsDataSanitized(const std::shared_ptr<IData>& data)
{
	std::cout << "SanitizeManager::IsDataSanitized()\n";

	if (data == nullptr)
	{
		std::cout << "SanitizeManager::IsDataSanitized() data is nullptr!\n";
		return false;
	}

	return false;
}