#include <iostream>
#include "matrix.hpp"

using namespace std;

//template ostream& operator<<(ostream& os, const TemplateMatrix<int>& matrix);
//template ostream& operator<<(ostream& os, const TemplateMatrix<double>& matrix);
//template istream& operator>>(istream& os, TemplateMatrix<double>& matrix);

int main()
{
   try
   {
      int arr1[2][3] = { {1, 2, 3},{ 4,5,6} };
      int arr2[2][3] = { {4, 5, 6},{ 7, 8, 9} };

      // Создание матриц
      TemplateMatrix<int> matrix1(arr1);
      TemplateMatrix<int> matrix2(arr2);

      // Вывод матриц
      cout << "Matrix1:" << endl << matrix1;
      cout << "Matrix2:" << endl << matrix2;

      // Сложение матриц
      TemplateMatrix<int> sum = matrix1 + matrix2;
      cout << "Sum of matrix1 and matrix2:" << endl << sum;

      // Вычитание матриц
      TemplateMatrix<int> diff = matrix1 - matrix2;
      cout << "Difference of matrix1 and matrix2:" << endl << diff;

      // Умножение матрицы на число
      TemplateMatrix<int> scaled = matrix1 * 2;
      cout << "Matrix1 scaled by 2:" << endl << scaled;

      // Умножение матриц (если возможно)
      TemplateMatrix<int> matrix3(3, 2); // Матрица для умножения
      cout << "Enter elements for matrix3 (3x2):" << endl;
      cin >> matrix3;
      TemplateMatrix<int> product = matrix1 * matrix3;
      cout << "Product of matrix1 and matrix3:" << endl << product;

      // Транспонирование
      cout << "Matrix1 before transpose:" << endl << matrix1;
      matrix1.MatrixTranspose();
      cout << "Matrix1 after transpose:" << endl << matrix1;

      // Проверка на равенство
      cout << "Are matrix1 and matrix2 equal? " << (matrix1 == matrix2 ? "Yes" : "No") << endl;

      // Ввод элемента
      cout << "Inserting new value into matrix2 at (0, 0):" << endl;
      matrix2.Insert(0, 0, 10);
      cout << "Updated matrix2:" << endl << matrix2;

      // Проверка метода GetElement
      cout << "Element at (0, 0) in matrix2: " << matrix2.GetElement(0, 0) << endl;

      // Проверка исключений
      cout << "Attempting to access out-of-bounds element in matrix2:" << endl;
      cout << matrix2.GetElement(10, 10) << endl; // Это должно вызвать исключение

   }
   catch (const MatrixException& ex)
   {
      ex.Print();
   }

   return 0;
}


/*
int main()
{
   TemplateMatrix<double> m1(3, 3);
   TemplateMatrix<double> m2(3, 3);

   cin >> m1;
   cin >> m2;

   cout << "Matrix 1:" << endl;
   cout << m1;
   cout << "Matrix 2:" << endl;
   cout << m2;

   TemplateMatrix<double> m3 = m1 + m2;
   cout << "Matrix 1 + Matrix 2:" << endl;
   cout << m3;

   return 0;
}
*/