#include "Action.hpp"
#include <iostream>

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
      cout << "x         y" << endl;
      while (x <= end) 
      {
         function_->SetArgument(x);
         cout << x << "   " << function_->GetValue() << endl;
         x += step;
      }
   }
};
#endif