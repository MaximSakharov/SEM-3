#include <iostream>
#include <math.h>
#include <string.h>

#include "MatrixException.hpp"

using namespace std;

class Matrix
{
protected:
   int rows;
   int columns;
   double** data;
public:
   Matrix(int rows_ = 2, int columns_ = 3, double** data_ = nullptr)
      : rows(rows_), columns(columns_)
   {
      data = new double* [rows];
      for (int i = 0; i < rows; ++i)
      {
         data[i] = new double[columns];
         for (int j = 0; j < columns; ++j)
            data[i][j] = (data_ ? data_[i][j] : 0);

      }
   }
   virtual ~Matrix()
   {
      for (int i = 0; i < rows; ++i)
         delete[] data[i];

      delete[] data;
   }
   virtual void Delete()
   {
      for (int i = 0; i < rows; ++i)
         delete[] data[i];

      delete[] data;

      rows = columns = 0;
   }

   double* operator[](int i) const
   {
      if (i < 0 || i >= rows)
         throw MatrixIndexOutOfRangeException();
      return data[i];
   }

   double* operator[](int i)
   {
      if (i < 0 || i >= rows)
         throw MatrixIndexOutOfRangeException();
      return data[i];
   }

   virtual void Print()
   {
      for (int i = 0; i < rows; i++)
      {
         for (int j = 0; j < columns; j++)
            printf("%f ", data[i][j]);
         printf("\n");
      }
   }
   Matrix(const Matrix& other_)
      : rows(other_.rows), columns(other_.columns) 
   {
      data = new double* [rows];
      for (int i = 0; i < rows; ++i) 
      {
         data[i] = new double[columns];
         for (int j = 0; j < columns; ++j) 
            data[i][j] = other_.data[i][j];
      }
   }
   int GetRows() { return rows; }

   int GetColumns() { return columns; }

   double GetElement(int row_, int column_) const
   {
       return data[row_][column_];
   }

   void Insert(int row_, int column_)
   {
      double element = 0;
      scanf_s("%lf", &element);
      data[row_][column_] = element;
   }
   Matrix& operator=(const Matrix& other_) 
   {
      if (this == &other_)
         return *this;

      for (int i = 0; i < rows; ++i) 
         delete[] data[i];
      
      delete[] data;

      rows = other_.rows;
      columns = other_.columns;
      data = new double* [rows];
      for (int i = 0; i < rows; ++i) 
      {
         data[i] = new double[columns];
         for (int j = 0; j < columns; ++j) 
            data[i][j] = other_.data[i][j];
      }

      return *this;
   }

   Matrix operator+(const Matrix& other_) const 
   {
      if (rows != other_.rows || columns != other_.columns)
         throw MatrixSizeMismatchException();

      Matrix matrix(rows, columns);

      for (int i = 0; i < rows; ++i) 
      {
         for (int j = 0; j < columns; ++j) 
            matrix.data[i][j] = data[i][j] + other_.data[i][j];
      }
      return matrix;
   }

   Matrix operator-(const Matrix& other_) const
   {
      if (rows != other_.rows || columns != other_.columns)
         throw MatrixSizeMismatchException();

      Matrix matrix(rows, columns);

      for (int i = 0; i < rows; ++i)
      {
         for (int j = 0; j < columns; ++j)
            matrix.data[i][j] = data[i][j] - other_.data[i][j];
      }
      return matrix;
   }
   
   Matrix operator*(const Matrix& other_) const
   {
      if (columns != other_.rows)
         throw MatrixMultiplicationException();

      Matrix matrix(rows, other_.columns);

      double result = 0;

      for (int i = 0; i < rows; ++i)
      {
         for (int j = 0; j < other_.columns; ++j)
         {
            result = 0;
            for (int m = 0; m < columns; ++m)
               result += (data[i][m] * other_.data[m][j]);
            matrix.data[i][j] = result;
         }
      }
      return matrix;
   }

   Matrix operator*(const double num_) const
   {
      Matrix matrix(rows, columns);

      for (int i = 0; i < rows; ++i)
      {
         for (int j = 0; j < columns; ++j)
         {
            matrix.data[i][j] = data[i][j] * num_;
         }
      }
      return matrix;
   }

   Matrix operator/(const double num_) const
   {
      if (num_ == 0)
         throw MatrixDivisionByZeroException();

      Matrix matrix(rows);

      for (int i = 0; i < rows; ++i)
         for (int j = 0; j < columns; ++j)
            matrix.data[i][j] = (data[i][j] / num_);

      return matrix;
   }

   Matrix& operator+=(const Matrix& other_)
   {
      if (rows != other_.rows || columns != other_.columns)
         throw MatrixSizeMismatchException();

      for (int i = 0; i < rows; ++i)
      {
         for (int j = 0; j < columns; ++j)
            data[i][j] += other_.data[i][j];
      }

      return *this;
   }

   Matrix& operator-=(const Matrix& other_)
   {
      if (rows != other_.rows || columns != other_.columns)
         throw MatrixSizeMismatchException();

      for (int i = 0; i < rows; ++i)
      {
         for (int j = 0; j < columns; ++j)
            data[i][j] -= other_.data[i][j];
      }

      return *this;
   }

   Matrix& operator*=(const Matrix& other_)
   {
      if (rows != other_.columns)
         throw MatrixMultiplicationException();

      Matrix matrix = *this;

      double result = 0;

      for (int i = 0; i < rows; ++i)
      {
         for (int j = 0; j < columns; ++j)
         {
            result = 0;
            for (int m = 0; m < columns; ++m)
               result += (matrix.data[i][m] * other_.data[m][j]);
            data[i][j] = result;
         }
      }
      return *this;
   }

   Matrix& operator*=(const double num_)
   {
      for (int i = 0; i < rows; ++i)
      {
         for (int j = 0; j < columns; ++j)
         {
            data[i][j] *= num_;
         }
      }
      return *this;
   }

   Matrix& operator/=(const double num_)
   {
      if (num_ == 0)
         throw MatrixDivisionByZeroException();

      Matrix matrix(rows);

      for (int i = 0; i < rows; ++i)
         for (int j = 0; j < columns; ++j)
            data[i][j] = (data[i][j] / num_);

      return *this;
   }

   bool operator==(Matrix& other_)
   {
      if (rows != other_.rows || columns != other_.columns)
         return false;

      for (int i = 0; i < rows; ++i)
         for (int j = 0; j < columns; ++j)
            if (data[i][j] != other_.data[i][j])
               return false;

      return true;
   }
   bool operator!=(Matrix& other_)
   {
      return !(*this == other_);
   }
   virtual void MatrixTranspose()
   {
      if (rows == 0 || columns == 0)
         throw MatrixEmptyException();

      Matrix matrix(columns, rows);

      for (int i = 0; i < rows; ++i)
         for (int j = 0; j < columns; ++j)
            matrix.data[j][i] = data[i][j];

      *this = matrix;
   }
   double FirstMatrixNorm()
   {
      double result = 0;
      double test = 0;

      for (int j = 0; j < columns; ++j)
      {
         for (int i = 0; i < rows; ++i)
         {
            test += abs(data[i][j]);
         }
         if (test > result)
            result = test;
         test = 0;
      }

      return result;
   }
   double SecondMatrixNorm()
   {
      double result = 0;

      for (int j = 0; j < columns; ++j)
      {
         for (int i = 0; i < rows; ++i)
         {
            result += pow(data[i][j],2);
         }
      }

      return sqrt(result);
   }
   double ThirdMatrixNorm()
   {
      double result = 0;
      double test = 0;

      for (int i = 0; i < rows; ++i)
      {
         for (int j = 0; j < columns; ++j)
         {
            test += abs(data[i][j]);
         }
         if (test > result)
            result = test;
         test = 0;
      }

      return result;
   }
   bool IsSquareMatrix()
   {
      return (rows == columns);
   }
   bool IsDiagonalMatrix()
   {
      if (!IsSquareMatrix())
         return false;

      for (int i = 0; i < rows; ++i)
         for (int j = 0; j < columns; ++j)
         {
            if (i != j && (data[i][j] != 0 || data[j][i] != 0))
               return false;
         }

      return true;
   }
   bool IsNullMatrix()
   {
      for (int i = 0; i < rows; ++i)
         for (int j = 0; j < columns; ++j)
         {
            if (data[i][j] != 0 || data[j][i] != 0)
               return false;
         }

      return true;
   }
   bool IsIdentityMatrix()
   {
      if (!IsDiagonalMatrix())
         return false;

      for (int i = 0; i < rows; ++i)
         if (data[i][i] != 1)
            return false;

      return true;
   }
   bool IsSymmetricMatrix()
   {
      if (!IsSquareMatrix())
         return false;

      for (int i = 0; i < rows; ++i)
         for (int j = 0; j < columns; ++j)
         {
            if (i != j && data[i][j] != data[j][i] )
               return false;
         }

      return true;
   }
   bool IsUpperTriangularMatrix()
   {
      if (!IsSquareMatrix())
         return false;

      for (int j = 0; j < columns; ++j)
         for (int i = j + 1; i < rows; ++i)
         {
            if (data[i][j] != 0)
               return false;
         }

      return true;
   }
   bool IsLowerTriangularMatrix()
   {
      if (!IsSquareMatrix())
         return false;

      for (int i = 0; i < rows; ++i)
         for (int j = i + 1; j < columns; ++j)
         {
            if (data[i][j] != 0)
               return false;
         }

      return true;
   }
   friend ostream& operator<<(ostream& stream, const Matrix& matrix);

   friend istream& operator>>(istream& stream, Matrix& matrix);
};

inline ostream& operator<<(ostream& stream, const Matrix& matrix_)
{
    for (int i = 0; i < matrix_.rows; i++)
    {
        for (int j = 0; j < matrix_.columns; j++)
            stream << matrix_[i][j] << " ";
        stream << endl;
    }
    
    return stream;
}

inline istream& operator>>(istream& stream, Matrix& matrix_)
{
   int new_rows = 0;
   int new_columns = 0;

   stream >> new_rows >> new_columns;

   if (new_rows <= 0 || new_columns <= 0)
      throw MatrixInputFormatException();

   matrix_.Delete();

   matrix_.rows = new_rows;
   matrix_.columns = new_columns;

   matrix_.data = new double* [matrix_.rows];
   for (int i = 0; i < matrix_.rows; ++i)
      matrix_.data[i] = new double[matrix_.columns];

    for (int i = 0; i < matrix_.rows; i++)
    {
        for (int j = 0; j < matrix_.columns; j++)
            stream >> matrix_[i][j];
    }

    return stream;
}