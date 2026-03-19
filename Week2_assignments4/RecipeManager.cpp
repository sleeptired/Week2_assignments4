#include "RecipeManager.h"
#include"PotionRecipe.h"

PotionRecipe* RecipeManager::AddRecipe(const PotionRecipe& cpy)
{
    if (FindRecipeByName(cpy.GetpotionName()))//nullptr은 거짓, 주소가 들어오면 참
    {
        return nullptr; //중복은 불가능하게 
    }
    else
    {
        recipes_.push_back(cpy);
        return &recipes_.back();//왜 마지막 녀석을 빼지?
    }
}

PotionRecipe* RecipeManager::FindRecipeByName(const std::string& name)
{
     for (size_t i = 0; i < recipes_.size(); ++i) 
     {
         if (name == recipes_[i].GetpotionName()) 
         {
             return &recipes_[i];//중복된 이름이 있음
         }
     }

     return nullptr;//중복된 이름이 없음
}

const std::vector<PotionRecipe>& RecipeManager::GetAllRecipes() const
{
    return recipes_;
}



