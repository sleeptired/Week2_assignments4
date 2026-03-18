#pragma once
#include"RecipeManager.h"
#include"StockManager.h"

class PotionRecipe;
class RecipeManager;
class StockManager;

class AlchemyWorkshop {
private:
    std::vector<PotionRecipe> recipes;
    RecipeManager recipeManager_; 
    StockManager stockManager_;

public:
    // addRecipe 메서드: 재료 목록(vector)을 매개변수로 받도록 수정
    void addRecipe(const std::string& name, const std::vector<std::string>& ingredients);

    //PotionRecipe searchRecipeByname(const std::string& name); 포션이름으로 검색
    // 도전기능+ (중복 이름 처리 방식은 구현 자유: 덮어쓰기/거부/중복허용 등)
    void addRecipe(const PotionRecipe& cpy);

    // 모든 레시피 출력 메서드
    void displayAllRecipes() const;

    // 재고 조회 (이름)
    int GetStockByName(const std::string& potionName) const;

    // potionName으로 검색하여 재고 있으면 지급처리하고 true, 재고 없으면 false
    bool DispensePotionByName(const std::string& potionName);//포션 제공하는 부분

    // 해당 재료를 포함하는 레시피들 중, 재고 있는 것들을 지급처리
    // 반환: 실제로 지급된 물약 이름 목록(없으면 빈 벡터)
    std::vector<std::string> DispensePotionsByIngredient(const std::string& ingredient);

    // potionName에 공병을 반환 처리(최대 3개 제한)
    void ReturnPotionByName(const std::string& potionName);
    
#pragma region 물약 이름으로 검색 선언 부분- (구) 필수 기능
    //PotionRecipe* FindRecipeByname(const std::string& name);
#pragma endregion

#pragma region 단일 재료 검색 선언 부분 - (구) 필수 기능
    //std::vector<PotionRecipe*>FindRecipeByIngredient(const std::string& name);
#pragma endregion
};