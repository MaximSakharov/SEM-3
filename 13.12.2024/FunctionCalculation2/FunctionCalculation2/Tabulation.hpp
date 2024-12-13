#include "Action.hpp"
#include <iostream>
#include <iomanip>

using namespace std;

#ifndef TABULATION_HPP
#define TABULATION_HPP

class Tabulation : public Action 
{
private:
   const char* name;
public:
   Tabulation() : name("Tabulation") {}

   const char* GetName() const { return name; }

   void Operate(Function* function_)
   {
      if (!function_)
         return;

      cout << "Tabulation for function y = " << function_->GetName() << endl;
      function_->SetParametrs();
      double begin, end, step;
      cout << "Enter begin x = "; cin >> begin;
      cout << "Enter end x = "; cin >> end;
      cout << "Enter step = "; cin >> step;

      double x = begin;
      cout << "|" << string(32, '-') << "|" << endl; // ������� ������� �������
      cout << "|" << internal << setw(15) << "x" << "|" << setw(16) << "y" << "|" << endl; // ��������� ��������
      cout << "|" << string(32, '-') << "|" << endl; // �������������� ����� ����� ����������� � �������

      cout << fixed << setprecision(4); // ������������� ������������� ���������� ������ ����� �������

      while (x <= end)
      {
         function_->SetArgument(x);
         cout << "|" << setw(15) << internal << x << "|" << setw(16) << internal << function_->GetValue() << "|" << endl; // ������
         cout << "|" << string(32, '-') << "|" << endl;
         x += step;
      }
   }
};
#endif