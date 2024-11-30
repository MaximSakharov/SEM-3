#include <iostream>
#include "Function.hpp"
#include "Exp.hpp"
#include "Line.hpp"
#include "Pow3.hpp"
#include "Polynomial.hpp"
#include "Menu.hpp"
using namespace std;

int main() {
   // ������ �������� ��������
   Exp f1;
   Line f2;
   Polynomial f3;
   Pow3 f4;

   // ������� ������ ����������
   Function* functions[] = { &f1, &f2, &f3, &f4 };

   int size = sizeof(functions) / sizeof(Function*);

   // ������� ������ ����
   Menu menu(functions, size);

   // �������� ������� �� ����
   while (Function* selected = menu.SelectObject())
   {
      selected->Calculate();
      system("pause");
      cout << '\n' << "\033[2J\033[1;1H" << endl;
   }

   return 0;
}