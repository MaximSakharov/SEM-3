#include <iostream>
#include "Function.hpp"
#include "Exp.hpp"
#include "Line.hpp"
#include "Polynomial.hpp"
#include "Action.hpp"
#include "Calculation.hpp"
#include "Tabulation.hpp"
#include "Menu.hpp"
using namespace std;

int main() {
   // Пример создания объектов
   Exp f1;
   Line f2;
   Polynomial f3;

   Calculation act1;
   Tabulation act2;

   // Создаем массив указателей
   Function* functions[] = { &f1, &f2, &f3 };
   Action* actions[] = { &act1, &act2 };

   int sizeFuct = sizeof(functions) / sizeof(Function*);
   int sizeAct = sizeof(actions) / sizeof(Action*);

   // Создаем объект меню
   Menu menu(functions, actions, sizeFuct, sizeAct);

   // Выбираем функцию из меню
   /*
   while (Function* selected = menu.SelectObject())
   {
      //selected->Calculate();
   }
   */

   while (Function* object = menu.SelectObject())
   {
      Action* act = menu.SelectAction(object);
      if (act)
        act->Operate(object);
   }

   return 0;
}