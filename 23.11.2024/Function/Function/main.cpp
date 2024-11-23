#include <iostream>
#include "Function.hpp"
#include "Exp.hpp"
#include "Line.hpp"
#include "Polynomial.hpp"
#include "Menu.hpp"
using namespace std;

int main() {
   // ������ �������� ��������
   Exp f1;
   Line f2;
   Polynomial f3;

   // ������� ������ ����������
   Function* functions[] = { &f1, &f2, &f3 };

   int size = sizeof(functions) / sizeof(Function*);

   // ������� ������ ����
   Menu menu(functions, size);

   // �������� ������� �� ����
   while (Function* selected = menu.SelectObject())
   {
      selected->Calculate();
   }

   return 0;
}