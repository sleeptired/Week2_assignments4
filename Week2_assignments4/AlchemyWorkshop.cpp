#include "AlchemyWorkshop.h"
#include "PotionRecipe.h"
#include <iostream>

void AlchemyWorkshop::addRecipe(const std::string& name, const std::vector<std::string>& ingredients)
{
	recipes.push_back(PotionRecipe(name, ingredients));//구버전 필수기능
	std::cout << ">> 새로운 레시피 '" << name << "'이(가) 추가되었습니다." << std::endl;//구버전 필수기능
}

void AlchemyWorkshop::addRecipe(const PotionRecipe& cpy)//새로 추가한 부분
{
    //recipes.push_back(cpy);//구버전 필수기능
    //std::cout << ">> 새로운 레시피 '" << cpy.GetpotionName() << "'이(가) 추가되었습니다." << std::endl;//구버전 필수 기능

    //신버전 RecipeManager 변수를 불러와 매니저의 벡터에 add를 함.
    //std::cout << ">> 새로운 레시피 '" << cpy.GetpotionName() << "'이(가) 추가되었습니다." << std::endl;
    //this->stockManager_.InitializeStock(cpy.GetpotionName());// 스톡 매니저에 추가

    if (recipeManager_.AddRecipe(cpy))
    {
        std::cout << ">> 새로운 레시피 '" << cpy.GetpotionName() << "'이(가) 추가되었습니다." << std::endl;
        stockManager_.InitializeStock(cpy.GetpotionName());
    }
    else 
    {
        std::cout << ">> 레시피 '" << cpy.GetpotionName() << "'는 이미 있는 물약입니다." << std::endl;

    }

}

void AlchemyWorkshop::displayAllRecipes() const
{

    //이 부분을 const std::vector<PotionRecipe>& GetAllRecipes() const; 이걸 사용해서 
    //const로 복사본을 하나 만들어서 저 함수를 넣고 출력을 한다.
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

#pragma region 물약 이름으로 검색 구현파트 - (구) 필수 기능
//PotionRecipe* AlchemyWorkshop::FindRecipeByname(const std::string& name)
//{
//    for (size_t i = 0; i < recipes.size(); ++i) 
//    {
//        if (name == recipes[i].GetpotionName()) 
//        {
//            return &recipes[i];
//        }
//    }
//    return nullptr;
//}
#pragma endregion
#pragma region 단일 재료 검색 구현파트 - (구) 필수 기능
//std::vector<PotionRecipe*> AlchemyWorkshop::FindRecipeByIngredient(const std::string& name)//무조건 오류가 발생함
//{
//    std::vector<PotionRecipe*> Ingerdient_Results; //1. 검색된 레시피들을 담을 빈 벡터 준비
//    for (int i = 0; i < this->recipes.size(); i++)////2. recipes 벡터를 처음부터 끝까지 하나씩 확인 (인덱스 필요)
//    {
//
//        for (int j = 0; j < this->recipes[i].Getingredients().size(); j++)//3. 현재 확인 중인 레시피의 '재료 목록'을 가져온다.
//        {
//            if (this->recipes[i].Getingredients()[j] == name)
//            {
//                Ingerdient_Results.push_back(&recipes[i]);//3-1. 재료 목록을 하나씩 대조하며, 입력받은 이름(name)과 일치하는 재료가 있는지 확인
//                break;//4. 일치하는 재료를 찾았다면 해당 레시피 빈 벡터의 저장 및 다음 레시피로 넘어간다
//            }
//        }
//    }
//    return Ingerdient_Results;//5. 레시피를 저장한 벡터를 반환
//}
#pragma endregion
