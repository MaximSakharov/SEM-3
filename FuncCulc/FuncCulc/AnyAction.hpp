#ifndef ANYACTION_HPP
#define ANYACTION_HPP

#include "Action.hpp"

class AnyAction : public Action {
public:
   AnyAction() : name("Any action") {}  // Конструктор, инициализирует название действия
   const char* GetName() const override { return name; }  // Возвращает имя действия
   void Operate(Function* pFunc) override {  // Метод Operate, выполняющий операцию
      std::cout << "Your advertising might be here!" << std::endl;  // Заглушка для рекламы
      std::cin.get();  // Ожидаем нажатия клавиши, чтобы продолжить
   }

private:
   const char* name;  // Название действия
};

extern AnyAction any_action;  // Глобальный объект для использования в других частях программы

#endif // ANYACTION_HPP