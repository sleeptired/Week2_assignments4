#include "StockManager.h"

void StockManager::InitializeStock(const std::string& potionName)
{
    std::cout << ">> '" << potionName << "' " << MAX_STOCK << "개가 입고되었습니다." << std::endl;
	this->potionStock_[potionName] = MAX_STOCK;
}

bool StockManager::DispensePotion(const std::string& potionName)
{
    auto it = potionStock_.find(potionName);
    if (it != potionStock_.end()) 
    {
        if (it->second > 0) 
        {
            
            it->second--;
            return true;
        }
        else 
        {
            return false;
        }
    }
    else //물약을 못찾았다는건데 이미 main에서 있는지 없는지 확인해서 의미없는 부분
    {
        return false;
    }
}

void StockManager::ReturnPotion(const std::string& potionName)
{
    auto it = potionStock_.find(potionName);
    if (it != potionStock_.end())
    {
        if (it->second == MAX_STOCK)
        {

        }
        else
        {
            it->second++;
        }
    }
    else 
    {

    }
}

int StockManager::GetStock(const std::string& potionName) const
{
    // 위치를 기억
    auto it = potionStock_.find(potionName);

    // 못 찾은 게 아니라면
    if (it != potionStock_.end())
    {
        // 아까 찾은 그 위치에서 second를 꺼냄 
        return it->second;
    }
    else
    {
        return 0; // shop에서 거르겠지만, 만약을 위한 안전장치
    }
}
