#include <iostream>
#include <vector>
#include <string>
#include <crtdbg.h>
#include"PotionRecipe.h"
#include"AlchemyWorkshop.h"


int main() 
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    AlchemyWorkshop myWorkshop;

    while (true) {
        std::cout << "연금술 공방 관리 시스템" << std::endl;
        std::cout << "1. 레시피 추가" << std::endl;
        std::cout << "2. 모든 레시피 출력" << std::endl;
        std::cout << "3. 종료" << std::endl;
        std::cout << "4. 레시피 통합 검색 (이름/재료)" << std::endl;
        std::cout << "5. 물약 재고 확인" << std::endl;
        std::cout << "6. 물약 지급 받기" << std::endl;
        std::cout << "7. 물약 공병 반환하기" << std::endl;
        std::cout << "선택: ";

        int choice;
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cout << "잘못된 입력입니다. 숫자를 입력해주세요." << std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue;
        }

        if (choice == 1) {
            std::string name;
            //std::cout << "물약 이름: ";
            std::cin.ignore(10000, '\n');//// 이전에 메뉴 선택에서 입력한 숫자의 엔터(\n) 찌꺼기를 지워줍니다.
            //std::getline(std::cin, name);
            while (true)
            {
                std::cout << "물약 이름: ";
                std::getline(std::cin, name);
                if (name.empty())
                {
                    std::cout << ">> 잘못된 입력입니다. 물약 이름을 입력해주세요." << std::endl;
                    continue; // 다시 입력을 받음
                }
                break; // 정상적으로 입력되었으면 루프를 탈출
            }

            // 여러 재료를 입력받기 위한 로직
            std::vector<std::string> ingredients_input;
            std::string ingredient;
            std::cout << "필요한 재료들을 입력하세요. (입력 완료 시 '끝' 입력)" << std::endl;

            while (true)
            {
                std::cout << "재료 입력: ";
                std::getline(std::cin, ingredient);

                // 사용자가 '끝'을 입력하면 재료 입력 종료
                if (ingredient == "끝")
                {
                    break;
                }

                if (ingredient.empty())
                {
                    std::cout << ">> 잘못된 입력입니다. 재료 이름 입력해주세요." << std::endl;
                    continue; // 아무것도 추가하지 않고 다시 입력을 받음
                }
                ingredients_input.push_back(ingredient);
            }

            // 입력받은 재료가 하나 이상 있을 때만 레시피 추가
            if (!ingredients_input.empty())
            {

                //myWorkshop.addRecipe(name, ingredients_input);
                myWorkshop.addRecipe(PotionRecipe(name, ingredients_input)); //객체를 넘겨주는데 임시 객체로 넘겨버리자 만들고 하는것도 비용낭비

            }
            else
            {
                std::cout << ">> 재료가 입력되지 않아 레시피 추가를 취소합니다." << std::endl;
            }

        }
        else if (choice == 2)
        {
            myWorkshop.displayAllRecipes();

        }
        else if (choice == 3)
        {
            std::cout << "공방 문을 닫습니다..." << std::endl;
            break;

        }
        else if (choice == 4)
        {
            std::string name;
            std::cout << "찾으시는 물약 이름이나 재료를 입력하세요: ";
            std::cin.ignore(10000, '\n');
            std::getline(std::cin, name);
            std::vector<PotionRecipe> OutputRecipes = myWorkshop.Get_SearchRecipes(name);
            if (OutputRecipes.empty())
            {
                std::cout << "'" << name << "'에 대한 검색 결과가 없습니다." << std::endl;
            }
            else
            {
                std::cout << "총 " << OutputRecipes.size() << "개의 레시피를 찾았습니다!" << std::endl;
                for (int i = 0; i < OutputRecipes.size(); i++)
                {
                    std::cout << "레시피: '" << OutputRecipes[i].GetpotionName() << "'" << std::endl;
                }
            }
        }
        else if (choice == 5)
        {
            std::string name;
            std::cout << "재고를 찾으시는 물약 이름을 입력하세요: ";
            std::cin.ignore(10000, '\n');
            std::getline(std::cin, name);
            int stock = myWorkshop.GetStockByName(name);
            if (stock == -1) 
            {
                std::cout << "'" << name << "' 는 없는 물약입니다." << std::endl;
            }
            else 
            {
                std::cout << "'" << name << "' 의 현재 재고는 " << stock << "개 입니다." << std::endl;
            }
        }
        else if (choice == 6) 
        {
            std::cout << "1.물약 이름으로 지급받기 | 2. 특정 재료가 포함된 물약 지급받기: ";
            int subchoice;
            std::cin >> subchoice;
            if (std::cin.fail()) {
                std::cout << "잘못된 입력입니다. 숫자를 입력해주세요." << std::endl;
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                continue;
            }

            if (subchoice == 1)
            {
                std::string name;
                std::cout << "지급받을 물약 이름을 입력하세요: ";
                std::cin.ignore(10000, '\n');
                std::getline(std::cin, name);
                int stock = myWorkshop.GetStockByName(name);
                if (stock == -1)
                {
                    // 상태 1: 애초에 없는 물약
                    std::cout << "'" << name << "' 는 없는 물약입니다." << std::endl;
                }
                else
                {
                    if (myWorkshop.DispensePotionByName(name))
                    {
                        std::cout << ">> '" << name << "' 물약이 1개 지급되었습니다." << std::endl;
                    }
                    else
                    {
                        std::cout << ">> '" << name << "' 물약 재고가 없습니다." << std::endl;
                    }
                }

            }
            else if (subchoice == 2)
            {
                std::string name;
                std::cout << "재료를 입력해주세요(입력된 재료에 포함된 모든 물약을 지급합니다): ";
                std::cin.ignore(10000, '\n');
                std::getline(std::cin, name);
                std::vector<std::string> Ingredients_for_potion = myWorkshop.DispensePotionsByIngredient(name);//무조건 재료가 포함된 포션의 모음
                if (Ingredients_for_potion.empty()) 
                {
                    std::cout << "'" << name << "' 재료가 포함된 물약은 없습니다." << std::endl;
                }
                else 
                {
                    for (int i = 0; i < Ingredients_for_potion.size(); i++)
                    {
                        if (myWorkshop.DispensePotionByName(Ingredients_for_potion[i]))
                        {
                            std::cout << ">> '" << Ingredients_for_potion[i] << "' 물약이 1개 지급되었습니다." << std::endl;
                        }
                        else
                        {
                            std::cout << ">> '" << Ingredients_for_potion[i] << "' 물약 재고가 없습니다." << std::endl;
                        }

                    }
                }
            }
            else 
            {
                std::cout << "잘못된 선택입니다. 공방으로 돌아갑니다." << std::endl;
                continue;
            }
        }
        else if (choice == 7) 
        {

        }
#pragma region (구) 필수 기능 4번 이름으로 물약 검색 main 파트
        //else if (choice == 4) 
        //{
        //    std::string name;
        //    std::cout << "검색 할 물약 이름: ";
        //    std::cin.ignore(10000, '\n');
        //    std::getline(std::cin, name);
        //
        //    if (myWorkshop.FindRecipeByname(name) != nullptr)
        //    {
        //        std::cout << "[물약 검색 완료] 물약 이름: " << myWorkshop.FindRecipeByname(name)->GetpotionName() << std::endl;
        //    }
        //    else
        //    {
        //        std::cout << "검색한 물약이 없습니다." << std::endl;
        //    }
        //
        //}
#pragma endregion
#pragma region (구) 필수 기능 5번 재료로 물약 검색 main 파트
        //else if (choice == 5) 
        //{
        //    std::string name;
        //    std::cout << "검색 할 재료 이름: ";
        //    std::cin.ignore(10000, '\n');
        //    std::getline(std::cin, name);
        //
        //    //검색 구현기능
        //    std::vector<PotionRecipe*> results = myWorkshop.FindRecipeByIngredient(name);
        //
        //    if (results.empty())//비어 있는지 확인
        //    {
        //        std::cout << "검색한 재료의 레시피가 없습니다." << std::endl;
        //    }
        //    else
        //    {
        //        for (int i = 0; i < results.size(); i++)
        //        {
        //
        //            std::cout << "[재료 검색 완료] 레시피: " << results[i]->GetpotionName() << std::endl;
        //
        //        }
        //    }
        //}
#pragma endregion
        else 
        {
            std::cout << "잘못된 선택입니다. 다시 시도하세요." << std::endl;
        }
    }

    return 0;
}