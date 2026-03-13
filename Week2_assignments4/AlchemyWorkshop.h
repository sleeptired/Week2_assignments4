#pragma once
#include <vector>
#include <string>

class PotionRecipe;

class AlchemyWorkshop {
private:
    std::vector<PotionRecipe> recipes;

public:
    // addRecipe 메서드: 재료 목록(vector)을 매개변수로 받도록 수정
    void addRecipe(const std::string& name, const std::vector<std::string>& ingredients);

    //PotionRecipe searchRecipeByname(const std::string& name); 포션이름으로 검색
    void addRecipe(const PotionRecipe& cpy);

    // 모든 레시피 출력 메서드
    void displayAllRecipes() const;
    
    //물약 이름으로 검색이 가능하게 하기
    PotionRecipe* FindRecipeByname(const std::string& name);


    //단일 재료 검색
    std::vector<PotionRecipe*>FindRecipeByIngredient(const std::string& name);

};