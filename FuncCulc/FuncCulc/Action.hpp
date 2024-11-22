#ifndef ACTION_HPP
#define ACTION_HPP

#include "Function.hpp"

class Action {
public:
   virtual ~Action() {}  // Деструктор, так как это абстрактный класс
   virtual void Operate(Function* pFunc) = 0;  // Метод для выполнения действия над функцией
   virtual const char* GetName() const = 0;  // Метод для получения имени действия
};

#endif /* ACTION_HPP */