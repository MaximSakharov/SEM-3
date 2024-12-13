#include "Function.hpp"
#include "Exp.hpp"

#include <iomanip>
#include <cmath>

using namespace std;

double Factorial(const double number_)
{
   double result = 1;

   if (number_ == 0)
      return 1;

   for (double i = 1; i <= number_; i++)
      result = result * i;

   return result;
}

long double TaylorExp(const double x_)
{
   int n = 1;

   double result = 1;
   double cur = 1;

   while (cur >= 0.00000001)
   {
       cur = cur * (x_/ n++);
       //cur /= n++;
       result += cur;
   }

   return result;
}

/*
void Exp::Calculate()
{
   cout << "Calculation for function y = " << name << endl;
   cout << "Enter x = ";
   cin >> x;
   cout << "y = " << fixed << setprecision(8) << TaylorExp(x, 0.0000000001);
}
*/