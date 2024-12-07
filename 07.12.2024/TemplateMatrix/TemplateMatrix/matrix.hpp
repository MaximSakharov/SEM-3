#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <iostream>
#include "MatrixException.hpp"

using namespace std;

template <typename T>
class TemplateMatrix
{
protected:
   int rows;
   int columns;
   T** data;
public:
   TemplateMatrix(int rows_ = 2, int columns_ = 3, T** data_ = nullptr)
      : rows(rows_), columns(columns_)
   {
      data = new T * [rows];
      for (int i = 0; i < rows; ++i)
      {
         data[i] = new T[columns];
         for (int j = 0; j < columns; ++j)
            data[i][j] = (data_ ? data_[i][j] : T{});

      }
   }

   virtual ~TemplateMatrix()
   {
      for (int i = 0; i < rows; ++i)
         delete[] data[i];

      delete[] data;
   }

   void Delete()
   {
      for (int i = 0; i < rows; ++i)
         delete[] data[i];

      delete[] data;

      rows = columns = 0;
   }

   T* operator[](int i) const
   {
      if (i < 0 || i >= rows)
         throw TemplateMatrix;
      return data[i];
   }

   T* operator[](int i)
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
            cout << data[i][j] << " ";
         cout << endl;
      }
   }

   TemplateMatrix(const TemplateMatrix& other_)
      : rows(other_.rows), columns(other_.columns)
   {
      data = new T * [rows];
      for (int i = 0; i < rows; ++i)
      {
         data[i] = new T[columns];
         for (int j = 0; j < columns; ++j)
            data[i][j] = other_.data[i][j];
      }
   }

   int GetRows() { return rows; }

   int GetColumns() { return columns; }

   T GetElement(int row_, int column_) const
   {
      return data[row_][column_];
   }

   void Insert(int row_, int column_)
   {
      T element;
      cin >> element;
      data[row_][column_] = element;
   }

   TemplateMatrix& operator=(const TemplateMatrix& other_)
   {
      if (this == &other_)
         return *this;

      for (int i = 0; i < rows; ++i)
         delete[] data[i];

      delete[] data;

      rows = other_.rows;
      columns = other_.columns;
      data = new T * [rows];
      for (int i = 0; i < rows; ++i)
      {
         data[i] = new T[columns];
         for (int j = 0; j < columns; ++j)
            data[i][j] = other_.data[i][j];
      }

      return *this;
   }

   TemplateMatrix operator+(const TemplateMatrix& other_) const
   {
      if (rows != other_.rows || columns != other_.columns)
         throw MatrixSizeMismatchException();

      TemplateMatrix<T> matrix(rows, columns);

      for (int i = 0; i < rows; ++i)
      {
         for (int j = 0; j < columns; ++j)
            matrix.data[i][j] = data[i][j] + other_.data[i][j];
      }
      return matrix;
   }

   TemplateMatrix operator-(const TemplateMatrix& other_) const
   {
      if (rows != other_.rows || columns != other_.columns)
         throw MatrixSizeMismatchException();

      TemplateMatrix<T> matrix(rows, columns);

      for (int i = 0; i < rows; ++i)
      {
         for (int j = 0; j < columns; ++j)
            matrix.data[i][j] = data[i][j] - other_.data[i][j];
      }
      return matrix;
   }

   TemplateMatrix operator*(const TemplateMatrix& other_) const
   {
      if (columns != other_.rows)
         throw MatrixMultiplicationException();

      TemplateMatrix<T> matrix(rows, other_.columns);

      T result = 0;

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

   TemplateMatrix operator*(const T num_) const
   {
      TemplateMatrix<T> matrix(rows, columns);

      for (int i = 0; i < rows; ++i)
      {
         for (int j = 0; j < columns; ++j)
         {
            matrix.data[i][j] = data[i][j] * num_;
         }
      }
      return matrix;
   }

   TemplateMatrix operator/(const T num_) const
   {
      if (num_ == T{ 0 })
         throw MatrixDivisionByZeroException();

      TemplateMatrix<T> matrix(rows);

      for (int i = 0; i < rows; ++i)
         for (int j = 0; j < columns; ++j)
            matrix.data[i][j] = (data[i][j] / num_);

      return matrix;
   }

   TemplateMatrix& operator+=(const TemplateMatrix& other_)
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

   TemplateMatrix& operator-=(const TemplateMatrix& other_)
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

   TemplateMatrix& operator*=(const TemplateMatrix& other_)
   {
      if (columns != other_.rows)
         throw MatrixMultiplicationException();

      TemplateMatrix<T> matrix = *this;

      T result = 0;

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

   TemplateMatrix& operator*=(const T num_)
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

   TemplateMatrix& operator/=(const T num_)
   {
      if (num_ == T{ 0 })
         throw MatrixDivisionByZeroException();

      for (int i = 0; i < rows; ++i)
         for (int j = 0; j < columns; ++j)
            data[i][j] = (data[i][j] / num_);

      return *this;
   }

   bool operator==(TemplateMatrix& other_)
   {
      if (rows != other_.rows || columns != other_.columns)
         return false;

      for (int i = 0; i < rows; ++i)
         for (int j = 0; j < columns; ++j)
            if (data[i][j] != other_.data[i][j])
               return false;

      return true;
   }

   bool operator!=(TemplateMatrix& other_)
   {
      return !(*this == other_);
   }

   virtual void MatrixTranspose()
   {
      if (rows == 0 || columns == 0)
         throw MatrixEmptyException();

      TemplateMatrix<T> matrix(columns, rows);

      for (int i = 0; i < rows; ++i)
         for (int j = 0; j < columns; ++j)
            matrix.data[j][i] = data[i][j];

      *this = matrix;
   }

    friend ostream& operator<<(ostream& stream, const TemplateMatrix<T>& matrix)
    {
       for (int i = 0; i < matrix.rows; ++i)
       {
          for (int j = 0; j < matrix.columns; ++j)
             stream << matrix.data[i][j] << " ";
          stream << endl;
       }
       return stream;
    }

    friend istream& operator>>(istream& stream, TemplateMatrix<T>& matrix)
    {
       for (int i = 0; i < matrix.rows; ++i)
       {
          for (int j = 0; j < matrix.columns; ++j)
             stream >> matrix.data[i][j];
       }
       return stream;
    }
};

#endif