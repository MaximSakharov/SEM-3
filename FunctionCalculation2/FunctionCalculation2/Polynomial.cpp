#include "Function.hpp"
#include "Polynomial.hpp"

using namespace std;

/*
void Polynomial::Calculate()
{
   cout << "Enter the maximum degree of 'x' = "; cin >> degree;
   parameters = new double[degree + 1];
   cout << "Enter parameters before all x's: ";
   for (int i = 0; i < degree + 1; ++i)
      cin >> parameters[i];

   if (degree > 0)
   {
      cout << "Enter x = ";
      cin >> x;
   }
   else
      x = 1;

   double result = 0;

   for (int i = 0; i < degree + 1; ++i)
      result += parameters[i] * pow(x, degree - i);

   cout << "y = " << result << endl;
}
*/
