#include<iostream>
#include "PotionRecipe.h"

PotionRecipe::PotionRecipe(const std::string& name, const std::vector<std::string>& ingredients) : potionName(name), ingredients(ingredients) 
{
}

std::vector<std::string> PotionRecipe::Getingredients() const
{
	return this->ingredients;
}

std::string PotionRecipe::GetpotionName() const
{
	return this->potionName;
}

