#include "Function.hpp"

#include <iomanip>
#include <cmath>

using namespace std;


double Factorial(const double number_);

long double TaylorExp(const double x_, const double eps_);


class Exp : public Function
{
protected:
   //char* name;
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
   void SetParametrs() {}

   double GetValue() const { return TaylorExp(x, 0.000000001); }
};