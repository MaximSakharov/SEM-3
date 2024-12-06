#pragma once

#include <iostream>
#include <math.h>
#include <string.h>
#include "vector.hpp"
#include <vector>

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

   SquareMatrix operator/(const SquareMatrix& other_) const
   {
      if (rows != other_.rows || columns != other_.columns)
         throw MatrixSizeMismatchException();

      SquareMatrix matrix(rows);

      SquareMatrix matrix2 = other_;
      matrix2.InverseMatrix();

      matrix = *this * matrix2;

      return matrix;
   }

   SquareMatrix operator/(const double num_) const
   {
      if (num_ == 0)
         throw MatrixDivisionByZeroException();

      SquareMatrix matrix(rows);

      for (int i = 0; i < rows; ++i)
         for (int j = 0; j < columns; ++j)
               matrix.data[i][j] = (data[i][j] / num_);

      return matrix;
   }

   SquareMatrix operator/=(const SquareMatrix& other_)
   {
      if (rows != other_.rows || columns != other_.columns)
         throw MatrixSizeMismatchException();

      SquareMatrix matrix2 = other_;
      matrix2.InverseMatrix();
      *this *= matrix2;

      return *this;
   }
   

   SquareMatrix& operator/=(const double num_)
   {
      if (num_ == 0)
         throw MatrixDivisionByZeroException();

      for (int i = 0; i < rows; ++i)
      {
         for (int j = 0; j < columns; ++j)
         {
            data[i][j] /= num_;
         }
      }
      return *this;
   }

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

   friend fstream& operator>>(fstream& stream, SquareMatrix& matrix_)
   {
      int new_rows = 0;
      int new_columns = 0;

      stream >> new_rows >> new_columns;

      if (stream.fail() || new_rows <= 0 || new_columns <= 0)
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
         {
            stream >> matrix_[i][j];
            if (stream.fail())
            {
               throw class MatrixIncorrectSupplyOfMatrixElementsException();
            }
         }
      }

      return stream;
   }

   vector<double> PathToVector(int m)
   {
      SquareMatrix new_matr;
      vector<double> vect;
      double path = 0;

      for (int i = 1; i <= m; ++i)
      {
         new_matr = *this;
         new_matr.Power(i);
         for (int i = 0; i < rows; ++i)
            path += new_matr[i][i];
         vect.push_back(path);
         path = 0;
      }
      return vect;
   }
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
   int new_rows = 0;

   stream >> new_rows;

   if (stream.fail() || new_rows <= 0)
      throw MatrixInputFormatException();

   matrix_.Delete();

   matrix_.rows = matrix_.columns = new_rows;

   matrix_.columns = matrix_.rows;

   matrix_.data = new double* [matrix_.rows];
   for (int i = 0; i < matrix_.rows; ++i)
      matrix_.data[i] = new double[matrix_.columns];
   

   for (int i = 0; i < matrix_.rows; i++)
   {
      for (int j = 0; j < matrix_.columns; j++)
      {
         stream >> matrix_[i][j];
         if (stream.fail())
         {
            throw class MatrixIncorrectSupplyOfMatrixElementsException();
         }
      }
   }

   return stream;
}

inline Vector MaxDiagonalElements(SquareMatrix matrix_) 
{
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