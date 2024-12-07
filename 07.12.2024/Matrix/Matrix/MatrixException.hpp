#include <iostream>
using namespace std;

// Base exception class
class MatrixException
{
public:
   virtual ~MatrixException() { }
   virtual void Print() const
   {
      cout << "Unknown matrix error." << endl;
   }
};

class MatrixSizeMismatchException : public MatrixException
{
public:
   void Print() const override
   {
      cout << "Error: Matrix dimensions do not match for the operation." << endl;
   }
};

class MatrixIndexOutOfRangeException : public MatrixException
{
public:
   void Print() const override
   {
      cout << "Error: Index out of matrix bounds." << endl;
   }
};

class MatrixEmptyException : public MatrixException
{
public:
   void Print() const override
   {
      cout << "Error: Matrix is empty." << endl;
   }
};

class MatrixOperationException : public MatrixException
{
public:
   void Print() const override
   {
      cout << "Error: Unsupported matrix operation." << endl;
   }
};

class MatrixNotSquareException : public MatrixException
{
public:
   void Print() const override
   {
      cout << "Error: Matrix is not square." << endl;
   }
};

class MatrixInputFormatException : public MatrixException
{
public:
   void Print() const override
   {
      cout << "Error: Invalid matrix input format." << endl;
   }
};

class MatrixIncorrectSupplyOfMatrixElementsException : public MatrixException
{
public:
   void Print() const override
   {
      cout << "Error: Incorrect supply of matrix elements." << endl;
   }
};

// Исключение для попытки умножения матриц с несовпадающими размерами
class MatrixMultiplicationException : public MatrixException
{
public:
   void Print() const override
   {
      cout << "Error: Matrix multiplication is not possible due to size mismatch." << endl;
   }
};

// Исключение для деления на ноль в матрице
class MatrixDivisionByZeroException : public MatrixException
{
public:
   void Print() const override
   {
      cout << "Error: Division by zero in matrix." << endl;
   }
};