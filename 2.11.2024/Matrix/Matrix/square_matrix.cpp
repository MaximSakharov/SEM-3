#include <iostream>
#include <math.h>
#include <string.h>

#include "matrix.hpp"
#include "square_matrix.hpp"

SquareMatrix* SquareMatrix::MatrixWithoutOneRowAndColumn(SquareMatrix& matrix, const int row_, const int column_)
{
   if (row_ < 0 || row_ >= matrix.rows || column_ < 0 || column_ >= matrix.rows) {
      return nullptr;
   }

   SquareMatrix* newMatrix = new SquareMatrix(matrix.rows - 1);
   int newRow = 0;

   for (int i = 0; i < matrix.rows; i++)
   {
      if (i == row_) continue;

      int newCol = 0;
      for (int j = 0; j < matrix.rows; j++)
      {
         if (j == column_) continue;

         newMatrix->data[newRow][newCol] = matrix.data[i][j];
         newCol++;
      }
      newRow++;
   }

   return newMatrix;
}

double SquareMatrix::Determinant()
{
   if (columns == 1) {
      return data[0][0];
   }

   double sum_ = 0.0;

   for (int i = 0; i < columns; i++) {
      SquareMatrix* newMatrix = MatrixWithoutOneRowAndColumn(*this, 0, i);
      double element = data[0][i];
      sum_ += pow(-1, i) * element * newMatrix->Determinant();
      delete newMatrix;
   }

   return sum_;
}

double SquareMatrix::AlgebraicAddition(SquareMatrix& matrix, int row_, int column_)
{
   SquareMatrix* newMatrix = MatrixWithoutOneRowAndColumn(matrix, row_, column_);

   double addition = pow(-1, row_ + column_) * newMatrix->Determinant();

   delete newMatrix;

   return addition;
}

SquareMatrix* SquareMatrix::MatrixWithAlgebAddits(SquareMatrix& matrix)
{
   SquareMatrix* newMatrix = new SquareMatrix(matrix.rows);

   for (int i = 0; i < matrix.rows; i++)
      for (int j = 0; j < matrix.columns; j++)
         newMatrix->data[i][j] = AlgebraicAddition(matrix, i, j);

   return newMatrix;
}

void SquareMatrix::InverseMatrix()
{
   SquareMatrix* AlMatrix = MatrixWithAlgebAddits(*this);

   AlMatrix->MatrixTranspose();

   SquareMatrix* newMatrix = new SquareMatrix(rows);
   double deter = Determinant();
   for (int i = 0; i < rows; i++)
      for (int j = 0; j < columns; j++)
         newMatrix->data[i][j] = (1.0 / deter) * AlMatrix->data[i][j];

   *this = *newMatrix;

   delete AlMatrix;
   delete newMatrix;
}

void SquareMatrix::Power(int power_)
{
   SquareMatrix identity(rows);
   for (int i = 0; i < rows; ++i) {
      identity.data[i][i] = 1;
   }

   if (power_ == 0) {
      *this = identity;
      return;
   }

   if (power_ < 0) {
      this->InverseMatrix();
      power_ *= -1;
   }

   SquareMatrix result = identity; 
   SquareMatrix base = *this; 

   for (size_t i = 0; i < power_; ++i) {
      result *= base;
   }

   *this = result;
}
