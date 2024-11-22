#include <cmath>
#include "Function.hpp"

class Exp : public Function {
public:
   Exp() {
      // ������������� ������ ��� C-������
      name = "e^x";
   }

   const char* GetName() const { return name; }  // ���������� C-������

   void SetCoeff() {}

   double GetVal() const { return exp(x); }

private:
   const char* name;  // �������������� ����������� �������
};

extern Exp f_exp;