#include <iostream>
#include "Function.hpp"
#include "Exp.hpp"
#include "Line.hpp"
#include "Menu.hpp"
using namespace std;

int main() {
   // ������ �������� ��������
   Exp f1;
   Line f2;

   // ������� ������ ����������
   Function* functions[] = { &f1, &f2, nullptr };

   // ������� ������ ����
   Menu menu(functions, 2); // 2 - ��� ���������� ��������� � ������� ��� ����� "Exit"

   // �������� ������� �� ����
   while (Function* selected = menu.SelectObject())
   {
      selected->Calculate();
   }

   return 0;
}