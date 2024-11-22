#include "Function.hpp"
#include "Polynomial.hpp"

using namespace std;

void Polynomial::Calculate()
{
   cout << "Enter the maximum degree of 'x' = "; cin >> degree;
   parameters = new double[degree + 1];
   cout << "Enter parameters before all x's: ";
   for (int i = 0; i < degree + 1; ++i)
      cin >> parameters[i];

   double result = parameters[0];

   for (int i = 1; i < degree + 1; ++i)
      result = result * x + parameters[i];

   cout << "y = " << result << endl;
}
