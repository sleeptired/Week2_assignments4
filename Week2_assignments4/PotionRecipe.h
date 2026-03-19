#pragma once
#include <vector>
#include <string>
// PotionRecipe 클래스: 재료 목록을 vector<string>으로 변경
class PotionRecipe {
private:
    std::string potionName;
    std::vector<std::string> ingredients; // 단일 재료에서 재료 '목록'으로 변경
public:
    // 생성자: 재료 목록을 받아 초기화하도록 수정
    PotionRecipe(const std::string& name, const std::vector<std::string>& ingredients);

    //ingredients get함수
    std::vector<std::string> Getingredients() const;

    //string potionName get함수
    std::string GetpotionName() const;

};