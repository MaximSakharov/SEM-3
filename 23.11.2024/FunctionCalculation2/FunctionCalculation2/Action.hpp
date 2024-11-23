#ifndef ACTION_HPP
#define ACTION_HPP

#include "Function.hpp"

class Action 
{
public:
   virtual ~Action() {} 
   virtual void Operate(Function* function_) = 0;
   virtual const char* GetName() const = 0; 
};

#endif /* ACTION_HPP */