#include <iostream>
#include "Function.hpp"
#include "Exp.hpp"
#include "Line.hpp"
#include "Action.hpp"
#include "Calculation.hpp"
#include "Tabulation.hpp"
#include "AnyAction.hpp"
#include "Menu.hpp"

Function* pObjs[] = { &f_exp, &f_line };
Action* pActs[] = { &calculation, &tabulation, &any_action };

int main() {
   Menu menu(pObjs, pActs, 2, 3);  // �� ����� 2 ������� � 3 ��������

   while (true) {
      Function* pObj = menu.SelectObject();
      if (!pObj) break;  // ���� ������ ���, �������
      Action* pAct = menu.SelectAction(pObj);
      pAct->Operate(pObj);
   }

   std::cout << "Bye!" << std::endl;
   return 0;
}