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

std::vector<PotionRecipe> RecipeManager::FindRecipesByIngredient(const std::string& ingredient) const
{
    std::vector<PotionRecipe> Ingerdient_Results;
    for (int i = 0; i < this->recipes_.size(); i++) 
    {
        for (int j = 0; j < this->recipes_[i].Getingredients().size(); j++) 
        {
            if (this->recipes_[i].Getingredients()[j] == ingredient)
            {
                Ingerdient_Results.push_back(recipes_[i]);
                break;
            }
        }
    }
    return Ingerdient_Results;
}

std::vector<PotionRecipe> RecipeManager::SearchRecipes(const std::string& name) const
{
    std::vector<PotionRecipe> Recipes_Results;
    for (int i = 0; i < this->recipes_.size(); i++) 
    {
        bool isMatch = false;
        if (name == recipes_[i].GetpotionName())
        {
            isMatch = true;
        }
        else 
        {
            for (int j = 0; j < this->recipes_[i].Getingredients().size(); j++)
            {
                if (this->recipes_[i].Getingredients()[j] == name)
                {

                    isMatch = true;
                    break;
                }
            }

        }

        if (isMatch) 
        {
            Recipes_Results.push_back(recipes_[i]);
        }
    }
    return Recipes_Results;
}

const std::vector<PotionRecipe>& RecipeManager::GetAllRecipes() const
{
    return recipes_;
}

bool RecipeManager::Has_Recipe(const std::string& name) const
{
    for (size_t i = 0; i < recipes_.size(); ++i)
    {
        if (name == recipes_[i].GetpotionName())
        {
            return true;
        }
    }

    return false;
}



