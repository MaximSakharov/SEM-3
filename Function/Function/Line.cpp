#include "Function.hpp"
#include "Line.hpp"

using namespace std;

void Line::Calculate()
{
   cout << "Calculation for function ó = " << name << endl;
   cout << "Enter a = "; 
   cin >> a;
   cout << "Enter b = "; 
   cin >> b;
   cout << "Enter x = "; 
   cin >> x;
   cout << "y = " << (a * x + b) << endl;
}
