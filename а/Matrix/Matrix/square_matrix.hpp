#include <iostream>
#include <math.h>
#include <string.h>

class SquareMatrix : public Matrix
{
private:

public:
   SquareMatrix(int size_ = 0, double** data_ = nullptr) : Matrix(size_, size_, data_)
   {

   }
   ~SquareMatrix()
   {

   }
   void Print() override
   {
      for (int i = 0; i < rows; i++)
      {
         for (int j = 0; j < rows; j++)
            printf("%f ", data[i][j]);
         printf("\n");
      }
   }
   SquareMatrix(const SquareMatrix& other_)
   {
      rows = other_.rows;
      columns = other_.columns;

      data = new double* [rows];
      for (int i = 0; i < rows; ++i)
      {
         data[i] = new double[rows];
         for (int j = 0; j < rows; ++j)
            data[i][j] = other_.data[i][j];
      }
   }
   SquareMatrix& operator=(const SquareMatrix& other_)
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
         data[i] = new double[rows];
         for (int j = 0; j < rows; ++j)
            data[i][j] = other_.data[i][j];
      }

      return *this;
   }

   SquareMatrix operator+(const SquareMatrix& other_) const
   {
      SquareMatrix matrix(rows);

      for (int i = 0; i < rows; ++i)
      {
         for (int j = 0; j < rows; ++j)
            matrix.data[i][j] = data[i][j] + other_.data[i][j];
      }
      return matrix;
   }
   /*
   template <typename T>
   SquareMatrix operator+(const T num_) const
   {
      SquareMatrix matrix(size);

      for (int i = 0; i < size; ++i)
      {
         for (int j = 0; j < size; ++j)
            matrix.data[i][j] = data[i][j] + num_;
      }
      return matrix;
   }
   */

   SquareMatrix operator-(const SquareMatrix& other_) const
   {
      SquareMatrix matrix(rows);

      for (int i = 0; i < rows; ++i)
      {
         for (int j = 0; j < columns; ++j)
            matrix.data[i][j] = data[i][j] - other_.data[i][j];
      }
      return matrix;
   }

   /*
   template <typename T>
   SquareMatrix operator-(const T num_) const
   {
      SquareMatrix matrix(size);

      for (int i = 0; i < rows; ++i)
      {
         for (int j = 0; j < columns; ++j)
            matrix.data[i][j] = data[i][j] - num_;
      }
      return matrix;
   }
   */
   /**/
   SquareMatrix operator*(const SquareMatrix& other_) const
   {
      SquareMatrix matrix(rows);

      double result = 0;

      for (int i = 0; i < rows; ++i)
      {
         for (int j = 0; j < columns; ++j)
         {
            result = 0;
            for (int m = 0; m < columns; ++m)
               result += (data[i][m] * other_.data[m][j]);
            matrix.data[i][j] = result;
         }
      }
      return matrix;
   }

   SquareMatrix operator*(const double num_) const
   {
      SquareMatrix matrix(rows);

      for (int i = 0; i < rows; ++i)
         for (int j = 0; j < columns; ++j)
               matrix.data[i][j] = (data[i][j] * num_);

      return matrix;
   }
   

   SquareMatrix operator/(const SquareMatrix& other_) const
   {
      SquareMatrix matrix(rows);

      SquareMatrix matrix2 = other_;
      matrix2.InverseMatrix();

      matrix = *this * matrix2;

      return matrix;
   }

   SquareMatrix operator/(const double num_) const
   {
      SquareMatrix matrix(rows);

      for (int i = 0; i < rows; ++i)
         for (int j = 0; j < columns; ++j)
               matrix.data[i][j] = (data[i][j] / num_);

      return matrix;
   }

   SquareMatrix& operator+=(const SquareMatrix& other_)
   {
      for (int i = 0; i < rows; ++i)
      {
         for (int j = 0; j < columns; ++j)
            data[i][j] += other_.data[i][j];
      }

      return *this;
   }

   SquareMatrix& operator-=(const SquareMatrix& other_)
   {
      for (int i = 0; i < rows; ++i)
      {
         for (int j = 0; j < columns; ++j)
            data[i][j] -= other_.data[i][j];
      }

      return *this;
   }

   SquareMatrix& operator*=(const SquareMatrix& other_)
   {
      SquareMatrix matrix = *this;

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

   SquareMatrix& operator*=(const double num_)
   {
      double result = 0;

      for (int i = 0; i < rows; ++i)
      {
         for (int j = 0; j < columns; ++j)
         {
             data[i][j] *= num_;
         }
      }
      return *this;
   }

   SquareMatrix operator/=(const SquareMatrix& other_)
   {
      SquareMatrix matrix2 = other_;
      matrix2.InverseMatrix();
      *this *= matrix2;

      return *this;
   }

   SquareMatrix& operator/=(const double num_)
   {
      for (int i = 0; i < rows; ++i)
      {
         for (int j = 0; j < columns; ++j)
         {
            data[i][j] /= num_;
         }
      }
      return *this;
   }

   bool operator==(SquareMatrix& other_)
   {
      if (rows != other_.rows || columns != other_.columns)
         return false;

      for (int i = 0; i < rows; ++i)
         for (int j = 0; j < columns; ++j)
            if (data[i][j] != other_.data[i][j])
               return false;

      return true;
   }
   bool operator!=(SquareMatrix& other_)
   {
      return !(*this == other_);
   }

   double Determinant();

   void InverseMatrix();

   void Power(int power_);

   /*
   void MatrixTranspose() override {}

   double FirstMatrixNorm() override {}

   double SecondMatrixNorm() override {}

   double ThirdMatrixNorm() override {}

   bool IsSquareMatrix() override {}

   bool IsDiagonalMatrix() override {}

   bool IsNullMatrix() override {}

   bool IsIdentityMatrix() override {}

   bool IsSymmetricMatrix() override {}

   bool IsUpperTriangularMatrix() override {}

   bool IsLowerTriangularMatrix() override {}
   */

   SquareMatrix* MatrixWithoutOneRowAndColumn(SquareMatrix& matrix, const int row_, const int column_);

   double AlgebraicAddition(SquareMatrix& matrix, int row_, int column_);

   SquareMatrix* MatrixWithAlgebAddits(SquareMatrix& matrix);

};