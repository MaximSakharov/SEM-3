#include "Function.hpp"

using namespace std;

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
   void SetParametrs() 
   {
      cout << "Enter the maximum degree of 'x' = "; cin >> degree;
      parameters = new double[degree + 1];
      cout << "Enter parameters before all x's: ";
      for (int i = 0; i < degree + 1; ++i)
         cin >> parameters[i];
   }

   double GetValue() const
   {
      double result = parameters[0];  // Начинаем с первого коэффициента

      for (int i = 1; i < degree + 1; ++i)
         result = result * x + parameters[i];  // Умножаем на x и прибавляем следующий коэффициент

      return result;
   }
};