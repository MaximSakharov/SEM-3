#include <iostream>
#include "matrix.hpp"

using namespace std;

//template ostream& operator<<(ostream& os, const TemplateMatrix<int>& matrix);
//template ostream& operator<<(ostream& os, const TemplateMatrix<double>& matrix);
//template istream& operator>>(istream& os, TemplateMatrix<double>& matrix);

int main()
{
   TemplateMatrix<double> m1(3, 3);
   TemplateMatrix<double> m2(3, 3);

   cin >> m1;
   cin >> m2;

   cout << "Matrix 1:" << endl;
   cout << m1;
   cout << "Matrix 2:" << endl;
   cout << m2;

   TemplateMatrix<double> m3 = m1 + m2;
   cout << "Matrix 1 + Matrix 2:" << endl;
   cout << m3;
   

   return 0;
}