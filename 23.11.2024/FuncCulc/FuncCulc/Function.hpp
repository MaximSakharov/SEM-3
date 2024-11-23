#ifndef FUNCTION_HPP
#define FUNCTION_HPP

class Function {
public:
   virtual ~Function() {}
   virtual void SetCoeff() = 0;
   virtual double GetVal() const = 0;
   virtual const char* GetName() const = 0;  // ���������� C-������
   void SetArg(double arg) { x = arg; }

protected:
   double x;  // ��������
};

#endif // FUNCTION_HPP