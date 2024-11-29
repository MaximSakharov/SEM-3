#pragma once

#include <iostream>
#include <math.h>
#include <string.h>
#include "vector.hpp"

class Vector;

class SquareMatrix : public Matrix
{
private:

public:
   SquareMatrix(int size_ = 2, double** data_ = nullptr) : Matrix(size_, size_, data_)
   {

   }
   ~SquareMatrix() override
   {

   }
   /*
   void Print() override
   {
      
   }
   */
   
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

   using Matrix::operator=;
   using Matrix::operator+;
   using Matrix::operator+=;
   using Matrix::operator-;
   using Matrix::operator-=;
   using Matrix::operator*;
   using Matrix::operator*=;
   using Matrix::operator==;
   using Matrix::operator!=;

   /*
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

   /*
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
   /*
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
   
   */
   SquareMatrix operator/(const SquareMatrix& other_) const
   {
      if (rows != other_.rows || columns != other_.columns)
         throw 1;

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
   /*
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
   
   
   */

   SquareMatrix operator/=(const SquareMatrix& other_)
   {
      if (rows != other_.rows || columns != other_.columns)
         throw 1;

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
   
   /*
   /*
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
   */

   void Swap(double& a, double& b) 
   {
      double temp = a;
      a = b;
      b = temp;
   }

   void MatrixTranspose() override
   {
      for (int i = 0; i < rows; ++i) 
         for (int j = i + 1; j < columns; ++j) 
            Swap(data[i][j], data[j][i]);
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

   friend ostream& operator<<(ostream& stream, const SquareMatrix& matrix);

   friend istream& operator>>(istream& stream, SquareMatrix& matrix);
};

inline ostream& operator<<(ostream& stream, const SquareMatrix& matrix_)
{
   for (int i = 0; i < matrix_.rows; i++)
   {
      for (int j = 0; j < matrix_.columns; j++)
         stream << matrix_[i][j] << " ";
      stream << endl;
   }

   return stream;
}

inline istream& operator>>(istream& stream, SquareMatrix& matrix_)
{
   matrix_.Delete();

   stream >> matrix_.rows;

   matrix_.columns = matrix_.rows;

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

inline Vector MaxDiagonalElements(SquareMatrix matrix_) 
{
   /*
   int n = matrix_.GetRows();
   Vector result(nullptr, 2 * n - 1);

   for (int col = 0; col < n; ++col)
   {
      double maxElement = matrix_[n - 1][col];
      for (int i = n - 1, j = col; i >= 0 && j >= 0; --i, --j)
         maxElement = std::max(maxElement, matrix_[i][j]);
      result.PushBack(maxElement);
   }

   for (int row = n - 2; row >= 0; --row)
   {
      double maxElement = matrix_[row][n - 1];
      for (int i = row, j = n - 1; i >= 0 && j >= 0; --i, --j)
         maxElement = std::max(maxElement, matrix_[i][j]);
      result.PushBack(maxElement);
   }
   */

   int n = matrix_.GetRows();
   Vector result(nullptr, 2 * n - 1);

   int param = 2;

   for (int start = 0; start < 2 * n - 1; ++start)
   {
      double maxElement = -std::numeric_limits<double>::infinity(); // Начальное значение для максимума
      int i, j;
      
      if (start < n) {
         i = n - 1; // Начинаем с последней строки
         j = start; // Начинаем с текущего столбца
      }
      else {
         i = n - param; // Уменьшаем строку
         ++param;
         j = n - 1; // Начинаем с последнего столбца
      }

      while (i >= 0 && j >= 0)
      {
         maxElement = std::max(maxElement, matrix_[i][j]);
         i--;
         j--;
      }

      result.PushBack(maxElement);
   }

   return result;
}