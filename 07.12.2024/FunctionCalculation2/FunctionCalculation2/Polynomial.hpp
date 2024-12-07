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
      name = new char[50];

      strcpy_s(name, 50, "a[n] * x ^ n + a[n-1] * x ^ (n - 1) + ... + a[0]");
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
      double result = parameters[0];  // �������� � ������� ������������

      for (int i = 1; i < degree + 1; ++i)
         result = result * x + parameters[i];  // �������� �� x � ���������� ��������� �����������

      return result;
   }
};