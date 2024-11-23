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
      cout << "Calculation for function y = " << function_->GetName() << endl;
      function_->SetParametrs();
      double x;
      cout << "Enter X = "; cin >> x;
      function_->SetArgument(x);
      cout << "y = " << function_->GetValue() << endl;
   }
};