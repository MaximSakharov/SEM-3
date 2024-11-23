#include <cmath>
#include "Function.hpp"

class Exp : public Function {
public:
   Exp() {
      // Устанавливаем строку как C-строку
      name = "e^x";
   }

   const char* GetName() const { return name; }  // Возвращаем C-строку

   void SetCoeff() {}

   double GetVal() const { return exp(x); }

private:
   const char* name;  // Математическое обозначение функции
};

extern Exp f_exp;