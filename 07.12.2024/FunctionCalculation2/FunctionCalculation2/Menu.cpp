#include <iostream>
#include "Menu.hpp"
using namespace std;

/*
// Конструктор
Menu::Menu(Function** functions_, int size_) : size(size_) 
{
   // Дополнительная ячейка для "Exit"
   size++;
   
   functions = new Function*[size];

   for (int i = 0; i < size - 1; ++i)
      functions[i] = functions_[i];

   functions[size - 1] = nullptr;

}

// Метод для выбора объекта
Function* Menu::SelectObject() const 
{
   //cout << "\n============================\n";
   cout << "\nSelect one of the following function:\n";

   // Печать меню с функциями
   for (int i = 0; i < size; ++i) {
      cout << i + 1 << ". ";
      if (functions[i]) 
         cout << functions[i]->GetName() << endl;
      else 
         cout << "Exit" << endl;
   }

   // Выбор пункта
   int item = SelectItem(size);
   return functions[item - 1];
}

// Метод для выбора пункта меню
int Menu::SelectItem(int nItem) const 
{
   cout << "\n";
   int item;
   while (true) // пока не встретит break будут выполнятся всегда
   {
      cin >> item;
      if ((item > 0) && (item <= nItem) && (cin.peek() == '\n')) 
      {
         //cin.get(); // Чтение остаточного символа новой строки
         break;
      }
      else 
      {
         cout << "Incorrect input (must be number from 1 to " << nItem << "): " << endl;
         //cin.clear();
         //while (cin.get() != '\n') {}; // Сброс буфера ввода
      }
   }
   return item;
}
*/