#include <iostream>
#include <string.h>

#ifndef FUNCTION_HPP
#define FUNCTION_HPP

class Function
{
protected:
   double x;
   char* name;
public:
   virtual ~Function(){}
   virtual void SetParametrs() = 0;
   virtual double GetValue() const = 0;
   virtual const char* GetName() const = 0;
   void SetArgument(double arg) { x = arg; }
   //virtual void Calculate() = 0;
};
#endif /* FUNCTION_HPP */