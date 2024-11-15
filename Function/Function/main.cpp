#include <iostream>
#include "Function.hpp"
#include "Exp.hpp"
#include "Line.hpp"
#include "Polynomial.hpp"
#include "Menu.hpp"
using namespace std;

int main() {
   // Пример создания объектов
   Exp f1;
   Line f2;
   Polynomial f3;

   // Создаем массив указателей
   Function* functions[] = { &f1, &f2, &f3 };

   int size = sizeof(functions) / sizeof(Function*);

   // Создаем объект меню
   Menu menu(functions, size);

   // Выбираем функцию из меню
   while (Function* selected = menu.SelectObject())
   {
      selected->Calculate();
   }

   return 0;
}