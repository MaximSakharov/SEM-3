#include <iostream>
#include <string.h>

#ifndef FUNCTION_H
#define FUNCTION_H

class Function
{
protected:
   double x;
public:
   virtual ~Function(){}
   virtual const char* GetName() const = 0;
   virtual void Calculate() = 0;
};
#endif /* FUNCTION_N */