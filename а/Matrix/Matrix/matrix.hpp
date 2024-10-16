#include <iostream>
#include <math.h>
#include <string.h>

class Matrix
{
protected:
   int rows;
   int columns;
   double** data;
public:
   
   Matrix(int rows_ = 0, int columns_ = 0, double** data_ = nullptr)
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
   ~Matrix()
   {
      for (int i = 0; i < rows; ++i)
         delete[] data[i];

      delete[] data;
   }
   virtual void Print()
   {
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
      Matrix matrix(rows, columns);

      for (int i = 0; i < rows; ++i) 
      {
         for (int j = 0; j < columns; ++j) 
            matrix.data[i][j] = data[i][j] + other_.data[i][j];
      }
      return matrix;
   }

   /*
   template <typename T>
   Matrix operator+(const T num_) const
   {
      Matrix matrix(rows, columns);

      for (int i = 0; i < rows; ++i)
      {
         for (int j = 0; j < columns; ++j)
            matrix.data[i][j] = data[i][j] + num_;
      }
      return matrix;
   }
   */

   Matrix operator-(const Matrix& other_) const
   {
      Matrix matrix(rows, columns);

      for (int i = 0; i < rows; ++i)
      {
         for (int j = 0; j < columns; ++j)
            matrix.data[i][j] = data[i][j] - other_.data[i][j];
      }
      return matrix;
   }
   /*
   template <typename T>
   Matrix operator-(const T num_) const
   {
      Matrix matrix(rows, columns);

      for (int i = 0; i < rows; ++i)
      {
         for (int j = 0; j < columns; ++j)
            matrix.data[i][j] = data[i][j] - num_;
      }
      return matrix;
   }
   */
   
   Matrix operator*(const Matrix& other_) const
   {
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
      Matrix matrix(rows);

      for (int i = 0; i < rows; ++i)
         for (int j = 0; j < columns; ++j)
            matrix.data[i][j] = (data[i][j] / num_);

      return matrix;
   }

   /*
   Matrix operator/(const Matrix& other_) const
   {
      Matrix matrix(rows, columns);

      double result = 0;

      for (int i = 0; i < rows; ++i)
      {
         for (int j = 0; j < columns; ++j)
         {
            result = 0;
            for (int m = 0; m < columns; ++m)
               result += (data[i][m] / other_.data[m][j]);
            matrix.data[i][j] = result;
         }
      }
      return matrix;
   }
   */

   Matrix& operator+=(const Matrix& other_)
   {
      for (int i = 0; i < rows; ++i)
      {
         for (int j = 0; j < columns; ++j)
            data[i][j] += other_.data[i][j];
      }

      return *this;
   }

   Matrix& operator-=(const Matrix& other_)
   {
      for (int i = 0; i < rows; ++i)
      {
         for (int j = 0; j < columns; ++j)
            data[i][j] -= other_.data[i][j];
      }

      return *this;
   }

   Matrix& operator*=(const Matrix& other_)
   {
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
      Matrix matrix(columns, rows);

      for (int i = 0; i < rows; ++i)
         for (int j = 0; j < columns; ++j)
            matrix.data[j][i] = data[i][j];

      *this = matrix;
   }
   virtual double FirstMatrixNorm()
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
   virtual double SecondMatrixNorm()
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
   virtual double ThirdMatrixNorm()
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
   virtual bool IsSquareMatrix()
   {
      return (rows == columns);
   }
   virtual bool IsDiagonalMatrix()
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
   virtual bool IsNullMatrix()
   {
      for (int i = 0; i < rows; ++i)
         for (int j = 0; j < columns; ++j)
         {
            if (data[i][j] != 0 || data[j][i] != 0)
               return false;
         }

      return true;
   }
   virtual bool IsIdentityMatrix()
   {
      if (!IsDiagonalMatrix())
         return false;

      for (int i = 0; i < rows; ++i)
         if (data[i][i] != 1)
            return false;

      return true;
   }
   virtual bool IsSymmetricMatrix()
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
   virtual bool IsUpperTriangularMatrix()
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
   virtual bool IsLowerTriangularMatrix()
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
};