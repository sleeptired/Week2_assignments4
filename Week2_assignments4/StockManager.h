#pragma once
#include<string>
#include<map>

class StockManager
{
public:
    static constexpr int MAX_STOCK = 3;

    // 레시피 추가 시 자동으로 3개 재고 세팅
    void InitializeStock(const std::string& potionName);

    // 재고가 1개 이상이면 1개 지급(감소)하고 true, 아니면 false
    bool DispensePotion(const std::string& potionName);

    // 공병 반환(재고 +1).
    // - 예외처리 : 단, MAX_STOCK 초과 불가
    void ReturnPotion(const std::string& potionName);

    // 현재 재고 조회(없으면 0)
    int GetStock(const std::string& potionName) const;

private:
    std::map<std::string, int> potionStock_;//여기에 재고랑 포션 이름을 넣음
};
