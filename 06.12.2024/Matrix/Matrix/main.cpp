#include <iostream>
#include <math.h>
#include <string.h>
#include <fstream>
#include <vector>

#include "matrix.hpp"
#include "square_matrix.hpp"
#include "functions.hpp"

using namespace std;

   int main() 
   {
      /*
      try {
         // 1. Тест на выход за пределы индекса
         cout << "Testing access out of range:" << endl;
         Matrix mat(3, 3);
         cout << mat[5][5] << endl;  // Попытка доступа к недопустимому индексу
      }
      catch (const MatrixIndexOutOfRangeException& e) {
         e.Print();
      }

      try {
         // 2. Тест на несовпадение размеров матриц при сложении
         cout << "\nTesting matrix addition with size mismatch:" << endl;
         Matrix mat1(2, 3);
         Matrix mat2(3, 3); // Разные размеры
         Matrix result = mat1 + mat2; // Попытка сложения матриц разных размеров
      }
      catch (const MatrixSizeMismatchException& e) {
         e.Print();
      }

      try {
         // 3. Тест на невозможность умножения матриц с несоответствующими размерами
         cout << "\nTesting matrix multiplication with size mismatch:" << endl;
         Matrix mat1(2, 3);
         Matrix mat2(4, 3); // Невозможно умножить
         Matrix result = mat1 * mat2;
      }
      catch (const MatrixMultiplicationException& e) {
         e.Print();
      }

      try {
         // 4. Тест на деление на ноль
         cout << "\nTesting division by zero:" << endl;
         Matrix mat(3, 3);
         Matrix result = mat / 0; // Попытка деления на ноль
      }
      catch (const MatrixDivisionByZeroException& e) {
         e.Print();
      }

      try {
         // 5. Тест на некорректный ввод (например, отрицательные размеры матрицы)
         cout << "\nTesting invalid matrix input:" << endl;
         Matrix mat;
         cin >> mat; // Попытка ввода матрицы с неправильными размерами
      }
      catch (const MatrixInputFormatException& e) {
         e.Print();
      }

      try {
         // 6. Тест на транспонирование пустой матрицы (с нулевыми размерами)
         cout << "\nTesting matrix transpose on empty matrix:" << endl;
         Matrix mat(0, 0);
         mat.MatrixTranspose();  // Попытка транспонировать пустую матрицу
      }
      catch (const MatrixEmptyException& e) {
         e.Print();
      }
      */

      try
      {
         Matrix matrix1;
         SquareMatrix matrix2;

         ifstream file1("matrix.txt");
         ifstream file2("square_matrix.txt");

         if (!file1.is_open() || !file2.is_open())
         {
            std::cerr << "Не удалось открыть файл!" << std::endl;
            return 1;
         }

         file1 >> matrix1;
         file2 >> matrix2;

         std::cout << "Матрица из файла:" << std::endl;
         std::cout << matrix1 << endl;
         std::cout << matrix2 << endl;

         vector<double> vect = matrix2.PathToVector(3);
         for (int i = 0; i < vect.size(); ++i)
            cout << vect[i] << " ";

         file1.close();
         file2.close();
      }
      catch (const MatrixException& e)
      {
         e.Print();
      }
      
      return 0;
   }
   /*
    Matrix* arr1 = new Matrix[2];
    SquareMatrix* arr2 = new SquareMatrix[2];

    int variant = 0;

    printf("What type of matrix do you want to work with?\n");
   
    printf("1 - Ordinary matrices.\n");
    printf("2 - Square matrices.\n");
    printf("3 -  Max Diagonal Elements in square matrix int vector.\n");
    variant = get_variant(3);

    if (variant == 1)
        WorkWithMatrix(arr1);
    else if (variant == 2)
        WorkWithSquareMatrix(arr2);
    else if (variant == 3)
    {
       printf("Insert size:\n");
       int size = 0;
       scanf_s("%d", &size);

       double** arr4 = new double* [size];
       for (int i = 0; i < size; ++i)
       {
          arr4[i] = new double[size];
       }

       printf("Insert matrix:\n");
    
       SquareMatrix matr(size, arr4);

       cin >> matr;
       cout << matr;

       printf("\n");

       Vector b = MaxDiagonalElements(matr);
       b.Print();
    }
   */



/*
* double** data1;

   data1 = new double* [2];

   for (int j = 0; j < 2; ++j)
      data1[j] = new double[2];

   data1[0][0] = 1;
   data1[0][1] = 2;
   data1[1][0] = 3;
   data1[1][1] = 4;

   SquareMatrix matrix(2, data1);

   double** data2;

   data2 = new double* [2];

   for (int j = 0; j < 2; ++j)
      data2[j] = new double[2];

   data2[0][0] = 5;
   data2[0][1] = 6;
   data2[1][0] = 7;
   data2[1][1] = 8;

   SquareMatrix matrix2(2, data2);

   matrix.Print();

   
   SquareMatrix matrix3(2);

   matrix3 = matrix + matrix2;

   printf("\n");
   //matrix3.MatrixTranspose();
   matrix3.Print();

   printf("\n");
   matrix3.Power(1);
   matrix3.Print();
   printf("\n");
   matrix3 /= 4;
   matrix3.Print();
   //matrix3.Print();

   /*
   printf("\n");
   matrix3.InverseMatrix();
   matrix3.Print();
   */
   //printf("\n%lf\n", matrix3.Determinant());

   /*
   double** data1;

   data1 = new double* [2];

   for (int j = 0; j < 2; ++j)
      data1[j] = new double[2];

   data1[0][0] = 1;
   data1[0][1] = 2;
   data1[1][0] = 3;
   data1[1][1] = 4;

   double** data2;

   data2 = new double* [2];

   for (int j = 0; j < 2; ++j)
      data2[j] = new double[2];

   data2[0][0] = 5;
   data2[0][1] = 6;
   data2[1][0] = 7;
   data2[1][1] = 8;

   Matrix matrix(2, 2, data1);
   Matrix matrix2(2, 2, data2);

   matrix.Print();
   printf("\n");
   matrix2.Print();
   /*
   Matrix matrix3(2, 2);

   matrix3 = matrix * matrix2;

   printf("\n");
   matrix3.Print();
   */

   /*
   matrix *= matrix2;

   printf("\n");
   matrix.Print();
   */

   /*
   printf("\n");
   printf("%d", (matrix != matrix2));
   */

   /*
   printf("\n");
   matrix.MatrixTranspose();
   matrix.Print();
   */
   /*
   double** data4;

   data4 = new double* [3];

   for (int j = 0; j < 3; ++j)
      data4[j] = new double[2];

   data4[0][0] = 8;
   data4[0][1] = 8;
   data4[1][0] = 3;
   data4[1][1] = -2;
   data4[2][0] = 8;
   data4[2][1] = -8;

   printf("\n");

   Matrix matrix4(3, 2, data4);
   */

   /*
   matrix4.Print();

   printf("\n");
   printf("%lf\n", matrix4.FirstMatrixNorm());
   printf("%lf\n", matrix4.SecondMatrixNorm());
   printf("%lf\n", matrix4.ThirdMatrixNorm());
   */

   /*
   matrix4.MatrixTranspose();
   matrix4.Print();
   */

   /*
   double** data5;

   data5 = new double* [2];

   for (int j = 0; j < 2; ++j)
      data5[j] = new double[2];

   data5[0][0] = 1;
   data5[0][1] = 0;
   data5[1][0] = 3;
   data5[1][1] = 4;

   Matrix matrix5(2, 2, data5);

   printf("\n%d\n", matrix5.IsLowerTriangularMatrix());

   */
