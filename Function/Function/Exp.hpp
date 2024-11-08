#include "Function.hpp"

class Exp : public Function
{
protected:
   char* name;
public:
   Exp()
   {
      name = new char[8];

      strcpy_s(name, 8, "e ^ x");
   }
   ~Exp()
   {
      delete[] name;
   }
   const char* GetName() const
   {
      return name;
   }
   void Calculate();
};