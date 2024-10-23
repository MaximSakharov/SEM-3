#include <iostream>
#include <math.h>
#include <string.h>

#include "matrix.hpp"
#include "square_matrix.hpp"
#include "functions.hpp"

int main()
{

    Matrix* arr = new Matrix[2];

    WorkWithMatrix(arr);

    return 0;
}



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
