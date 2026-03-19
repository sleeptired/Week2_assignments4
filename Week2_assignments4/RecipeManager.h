#pragma once
#include<vector>
#include<string>

class PotionRecipe;

class RecipeManager
{
public:
    // 레시피 추가 후, 내부에 저장된 레시피의 포인터를 반환(없으면 nullptr)
    // - 예외처리 : 이미 있는 Recipe을 추가할 때, 자유롭게 처리
    //PotionRecipe* AddRecipe(const std::string& name, const std::vector<std::string>& ingredients);

    PotionRecipe* AddRecipe(const PotionRecipe& cpy);

    // 이름으로 1개 찾기(없으면 nullptr)
    PotionRecipe* FindRecipeByName(const std::string& name);

    // 재료로 여러 개 찾기(결과 복사본 반환)
    std::vector<PotionRecipe> FindRecipesByIngredient(const std::string& ingredient) const;

    //도전 기능 재료 및 이름 통합 검색
    std::vector<PotionRecipe> SearchRecipes(const std::string& name) const;

    // 전체 레시피(읽기 전용 참조)
    const std::vector<PotionRecipe>& GetAllRecipes() const;

    bool Has_Recipe(const std::string& name) const;
private:
    std::vector<PotionRecipe> recipes_;
};