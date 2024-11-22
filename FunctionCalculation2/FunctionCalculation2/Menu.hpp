#include "Function.hpp"
#include "Action.hpp"
#include <iostream>

class Menu 
{
public:
   Menu(Function* _pObj[], Action* _pAct[], int objCount, int actCount)
      : pObj(_pObj), pAct(_pAct), objCount(objCount), actCount(actCount) {}

   Function* SelectObject() const {
      std::cout << "Select function:" << std::endl;
      for (int i = 0; i < objCount; ++i) {
         std::cout << i + 1 << ". " << pObj[i]->GetName() << std::endl;
      }
      int choice;
      std::cin >> choice;
      return pObj[choice - 1];
   }

   Action* SelectAction(Function* pObj) const {
      std::cout << "Select one of the following Actions for function " << pObj->GetName() << ":" << std::endl;
      for (int i = 0; i < actCount; ++i) {
         std::cout << i + 1 << ". " << pAct[i]->GetName() << std::endl;
      }
      int choice;
      std::cin >> choice;
      return pAct[choice - 1];
   }

private:
   Function** pObj;
   Action** pAct;
   int objCount;
   int actCount;
};