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
   virtual const char* GetName() const = 0;
   virtual void Calculate() = 0;
};
#endif /* FUNCTION_HPP */