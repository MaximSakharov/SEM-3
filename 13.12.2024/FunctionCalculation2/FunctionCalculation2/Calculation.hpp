#include "Action.hpp"
#include <iostream>

using namespace std;

class Calculation : public Action 
{
private:
   const char* name;
public:
   Calculation() : name("Calculation") {}

   const char* GetName() const { return name; }

   void Operate(Function* function_) 
   {
       if (!function_)
           return;
      cout << "Calculation for function y = " << function_->GetName() << endl;
      function_->SetParametrs();
      double x;
      cout << "Enter X = "; cin >> x;
      function_->SetArgument(x);
      cout << "|" << string(32, '-') << "|" << endl;
      cout << "|" << internal << setw(15) << "x" << "|" << setw(16) << "y" << "|" << endl;
      cout << "|" << string(32, '-') << "|" << endl;
      cout << "|" << setw(15) << internal << x << "|" << setw(16) << internal << function_->GetValue() << "|" << endl;
      cout << "|" << string(32, '-') << "|" << endl;
   }
};