#include "Function.hpp"
#include <iostream>

class Line : public Function {
public:
   Line() : name("a * x + b"), a(0), b(0) {}

   const char* GetName() const { return name; }  // ���������� C-������

   void SetCoeff() {
      std::cout << "Enter a = "; std::cin >> a;
      std::cout << "Enter b = "; std::cin >> b;
   }

   double GetVal() const { return a * x + b; }

private:
   const char* name;  // �������������� ����������� �������
   double a, b;  // ������������ ������
};

extern Line f_line;