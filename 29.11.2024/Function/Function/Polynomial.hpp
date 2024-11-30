#include "Function.hpp"

class Polynomial : public Function
{
private:
   double* parameters;
   size_t degree;
public:
   Polynomial()
   {
      name = new char[40];

      strcpy_s(name, 40, "a * x ^ n + b * x ^ (n - 1) + ... + z");
   }
   ~Polynomial()
   {
      delete[] name;
      delete[] parameters;
   }
   const char* GetName() const
   {
      return name;
   }
   void Calculate();
};