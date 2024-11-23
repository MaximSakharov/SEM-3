#include "Action.hpp"
#include <iostream>

using namespace std;

class Calculation : public Action {
public:
   Calculation() : name("Calculation") {}

   const char* GetName() const { return name; }

   void Operate(Function* pFunc) {
      std::cout << "Calculation for function y = " << pFunc->GetName() << std::endl;
      pFunc->SetCoeff();
      double x;
      std::cout << "Enter X = "; std::cin >> x;
      pFunc->SetArg(x);
      std::cout << "y = " << pFunc->GetVal() << std::endl;
   }

private:
   const char* name;  // Обозначение операции
};

extern Calculation calculation;