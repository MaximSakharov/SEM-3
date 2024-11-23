#include "Action.hpp"
#include <iostream>

#ifndef TABULATION_HPP
#define TABULATION_HPP


class Tabulation : public Action {
public:
   Tabulation() : name("Tabulation") {}

   const char* GetName() const { return name; }

   void Operate(Function* pFunc) {
      std::cout << "Tabulation for function y = " << pFunc->GetName() << std::endl;
      pFunc->SetCoeff();
      double x_beg, x_end, x_step;
      std::cout << "Enter x_beg = "; std::cin >> x_beg;
      std::cout << "Enter x_end = "; std::cin >> x_end;
      std::cout << "Enter x_step = "; std::cin >> x_step;

      double x = x_beg;
      std::cout << " X        y" << std::endl;
      while (x <= x_end) {
         pFunc->SetArg(x);
         std::cout << x << "   " << pFunc->GetVal() << std::endl;
         x += x_step;
      }
   }

private:
   const char* name;  // Обозначение операции
};

extern Tabulation tabulation;

#endif