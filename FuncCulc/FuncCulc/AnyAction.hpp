#ifndef ANYACTION_HPP
#define ANYACTION_HPP

#include "Action.hpp"

class AnyAction : public Action {
public:
   AnyAction() : name("Any action") {}  // �����������, �������������� �������� ��������
   const char* GetName() const override { return name; }  // ���������� ��� ��������
   void Operate(Function* pFunc) override {  // ����� Operate, ����������� ��������
      std::cout << "Your advertising might be here!" << std::endl;  // �������� ��� �������
      std::cin.get();  // ������� ������� �������, ����� ����������
   }

private:
   const char* name;  // �������� ��������
};

extern AnyAction any_action;  // ���������� ������ ��� ������������� � ������ ������ ���������

#endif // ANYACTION_HPP