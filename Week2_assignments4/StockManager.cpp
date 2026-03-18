#include "StockManager.h"

void StockManager::InitializeStock(const std::string& potionName)
{
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
