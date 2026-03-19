#include "StockManager.h"

void StockManager::InitializeStock(const std::string& potionName)
{
	std::cout << potionName << " " << MAX_STOCK << "개가 입고되었습니다." << std::endl;
	this->potionStock_[potionName] = MAX_STOCK;
}

bool StockManager::DispensePotion(const std::string& potionName)
{
	return false;
}

void StockManager::ReturnPotion(const std::string& potionName)
{
}

int StockManager::GetStock(const std::string& potionName) const
{
	return 0;
}
