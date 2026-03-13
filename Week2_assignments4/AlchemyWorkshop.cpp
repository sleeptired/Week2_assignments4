#include "AlchemyWorkshop.h"
#include "PotionRecipe.h"
#include <iostream>

void AlchemyWorkshop::addRecipe(const std::string& name, const std::vector<std::string>& ingredients)
{
	recipes.push_back(PotionRecipe(name, ingredients));
	std::cout << ">> 새로운 레시피 '" << name << "'이(가) 추가되었습니다." << std::endl;
}

void AlchemyWorkshop::addRecipe(const PotionRecipe& cpy)//새로 추가한 부분
{
    recipes.push_back(cpy);
    std::cout << ">> 새로운 레시피 '" << cpy.GetpotionName() << "'이(가) 추가되었습니다." << std::endl;
}

void AlchemyWorkshop::displayAllRecipes() const
{
    if (recipes.empty()) {
        std::cout << "아직 등록된 레시피가 없습니다." << std::endl;
        return;
    }

    std::cout << "\n--- [ 전체 레시피 목록 ] ---" << std::endl;
    for (size_t i = 0; i < recipes.size(); ++i) {
        std::cout << "- 물약 이름: " << recipes[i].GetpotionName() << std::endl;
        std::cout << "  > 필요 재료: ";

        // 재료 목록을 순회하며 출력
        for (size_t j = 0; j < recipes[i].Getingredients().size(); ++j) {
            std::cout << recipes[i].Getingredients()[j];
            // 마지막 재료가 아니면 쉼표로 구분
            if (j < recipes[i].Getingredients().size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << std::endl;
    }
    std::cout << "---------------------------\n";
}

PotionRecipe* AlchemyWorkshop::FindRecipeByname(const std::string& name)
{
    for (size_t i = 0; i < recipes.size(); ++i) 
    {
        if (name == recipes[i].GetpotionName()) 
        {
            return &recipes[i];
        }
    }
    return nullptr;
}

std::vector<PotionRecipe*> AlchemyWorkshop::FindRecipeByIngredient(const std::string& name)
{
    for (int i = 0; i < this->recipes.size(); i++)//인덱스가 필요해서
    {

    }
    
    return std::vector<PotionRecipe*>();
}

