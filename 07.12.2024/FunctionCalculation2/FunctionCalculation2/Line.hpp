#include "Function.hpp"

using namespace std;

class Line : public Function
{
protected:
   //char* name;
   double a;
   double b;
public:
   Line()
   {
      name = new char[12];

      strcpy_s(name, 12, "a * x + b");
   }
   ~Line()
   {
      delete[] name;
   }
   const char* GetName() const
   {
      return name;
   }
   void SetParametrs() 
   {
      cout << "Enter a = "; cin >> a;
      cout << "Enter b = "; cin >> b;
   }
   double GetValue() const { return a * x + b; }
};