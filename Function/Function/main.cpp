#include <iostream>
#include "Function.hpp"
#include "Exp.hpp"
#include "Line.hpp"
#include "Menu.hpp"
using namespace std;

int main() {
   // Пример создания объектов
   Exp f1;
   Line f2;

   // Создаем массив указателей
   Function* functions[] = { &f1, &f2, nullptr };

   // Создаем объект меню
   Menu menu(functions, 2); // 2 - это количество элементов в массиве без учета "Exit"

   // Выбираем функцию из меню
   while (Function* selected = menu.SelectObject())
   {
      selected->Calculate();
   }

   return 0;
}