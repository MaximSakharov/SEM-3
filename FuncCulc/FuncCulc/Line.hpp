#include "Function.hpp"
#include <iostream>

class Line : public Function {
public:
   Line() : name("a * x + b"), a(0), b(0) {}

   const char* GetName() const { return name; }  // Возвращаем C-строку

   void SetCoeff() {
      std::cout << "Enter a = "; std::cin >> a;
      std::cout << "Enter b = "; std::cin >> b;
   }

   double GetVal() const { return a * x + b; }

private:
   const char* name;  // Математическое обозначение функции
   double a, b;  // Коэффициенты прямой
};

extern Line f_line;