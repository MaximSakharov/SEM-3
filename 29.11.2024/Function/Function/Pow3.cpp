#include "Function.hpp"
#include "Pow3.hpp"

using namespace std;

void Pow3::Calculate()
{
	cout << "Calculation for function y = " << name << endl;
	cout << "Enter x = ";
	cin >> x;
	cout << "y = " << x * x * x;
}