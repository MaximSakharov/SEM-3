#include <iostream>
#include "Menu.hpp"
using namespace std;

/*
// �����������
Menu::Menu(Function** functions_, int size_) : size(size_) 
{
   // �������������� ������ ��� "Exit"
   size++;
   
   functions = new Function*[size];

   for (int i = 0; i < size - 1; ++i)
      functions[i] = functions_[i];

   functions[size - 1] = nullptr;

}

// ����� ��� ������ �������
Function* Menu::SelectObject() const 
{
   //cout << "\n============================\n";
   cout << "\nSelect one of the following function:\n";

   // ������ ���� � ���������
   for (int i = 0; i < size; ++i) {
      cout << i + 1 << ". ";
      if (functions[i]) 
         cout << functions[i]->GetName() << endl;
      else 
         cout << "Exit" << endl;
   }

   // ����� ������
   int item = SelectItem(size);
   return functions[item - 1];
}

// ����� ��� ������ ������ ����
int Menu::SelectItem(int nItem) const 
{
   cout << "\n";
   int item;
   while (true) // ���� �� �������� break ����� ���������� ������
   {
      cin >> item;
      if ((item > 0) && (item <= nItem) && (cin.peek() == '\n')) 
      {
         //cin.get(); // ������ ����������� ������� ����� ������
         break;
      }
      else 
      {
         cout << "Incorrect input (must be number from 1 to " << nItem << "): " << endl;
         //cin.clear();
         //while (cin.get() != '\n') {}; // ����� ������ �����
      }
   }
   return item;
}
*/