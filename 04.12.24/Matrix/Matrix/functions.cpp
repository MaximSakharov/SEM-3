#include <iostream>
#include <math.h>
#include <string.h>

#include "matrix.hpp"
#include "square_matrix.hpp"
#include "functions.hpp"

void Print_Menu()
{
   system("cls");
   printf("What do you want to do?\n");
   printf("1. Insert first matrix.\n");
   printf("2. Insert second matrix.\n");
   printf("3. Using operators.\n");
   printf("4. Using comparison operations.\n");
   printf("5. Find the transposed matrix.\n");
   printf("6. Find norms.\n");
   printf("7. Determine the type of matrix.\n");
   printf("8. Print matrices.\n");
   printf("9. Exit\n");
   printf(">");
}

void PrintOperatorsMenu()
{
    system("cls");
    printf("What do you want to do?\n");
    printf("1. Operator +.\n");
    printf("2. Operator -.\n");
    printf("3. Operator * (with other matrix).\n");
    printf("4. Operator * (with constant).\n");
    printf("5. Operator / (with constant)\n");
    printf("6. Return.\n");
    printf(">");
}

void PrintSaveResultMenu()
{
    //system("cls");
    printf("You want to save matrix?\n");
    printf("1. Yes!\n");
    printf("2. No\n");
    printf(">");
}

void PrintWhereSaveResultMenu()
{
    system("cls");
    printf("Where you want to save matrix?\n");
    printf("1. Position 1\n");
    printf("2. Position 2\n");
    printf(">");
}

int get_variant(int count)
{
   int variant;

   while (scanf_s("%d", &variant) != 1 || variant < 1 || variant > count) {
      printf("Incorrect input. Try again: ");
   }

   return variant;
}

void WorkWithMatrix(Matrix* matrix_)
{
   int variant = 0;

   int rows = 0;
   int columns = 0;

   int choose = 0;

   Matrix result;

   while (variant != 9)
   {
      Print_Menu();

      variant = get_variant(9);

      switch (variant)
      {
      case 1:
         printf("Insert rows: ");
         scanf_s("%d", &rows);
         printf("Insert columns: ");
         scanf_s("%d", &columns);

         matrix_[0] = Matrix(rows, columns);

         printf("Insert matrix:\n");
         cin >> matrix_[0];
         /*
         for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
               scanf_s("%lf", &matrix_[0][i][j]);
            }
         }
         */
         break;
      case 2:
          printf("Insert rows: ");
          scanf_s("%d", &rows);
          printf("Insert columns: ");
          scanf_s("%d", &columns);
          matrix_[1] = Matrix(rows, columns);
          printf("Insert matrix: ");
          cin >> matrix_[1];
          /*
          for (int i = 0; i < rows; ++i)
              for (int j = 0; j < columns; ++j)
                  scanf_s("%lf", &matrix_[1][i][j]);
          */
         break;
      case 3:
         WorkWithOperators(matrix_);
         break;
      case 4:
         if (matrix_[0] == matrix_[1])
            printf("Matrices are equal.");
         else if (matrix_[0] != matrix_[1])
            printf("Matrices are not equal.");
         break;
      case 5:
         printf("Which matrix you want to transpose?\n");
         printf("> ");
         choose = get_variant(2);
         result = matrix_[choose - 1];
         result.MatrixTranspose();
         result.Print();
         WorkWithSaving(matrix_, result);
         break;
      case 6:
         printf("What matrix to find the norm for?\n");
         printf("> ");
         choose = get_variant(2);
         printf("First norm: %lf\n", matrix_[choose - 1].FirstMatrixNorm());
         printf("Second norm: %lf\n", matrix_[choose - 1].SecondMatrixNorm());
         printf("Third norm: %lf\n", matrix_[choose - 1].ThirdMatrixNorm());
         break;
      case 7:
         printf("Which matrix you want to check types?\n");
         printf("> ");
         choose = get_variant(2);

         printf("Is Square matrix: ");
         YesNo(matrix_[choose - 1].IsSquareMatrix());
         printf("\n"); 
         
         printf("Is Diagonal matrix: ");
         YesNo(matrix_[choose - 1].IsDiagonalMatrix());
         printf("\n");

         printf("Is Null matrix: ");
         YesNo(matrix_[choose - 1].IsNullMatrix());
         printf("\n");

         printf("Is Identity matrix: ");
         YesNo(matrix_[choose - 1].IsIdentityMatrix());
         printf("\n");

         printf("Is Symmetric matrix: ");
         YesNo(matrix_[choose - 1].IsSymmetricMatrix());
         printf("\n");

         printf("Is Upper Triangular matrix: ");
         YesNo(matrix_[choose - 1].IsUpperTriangularMatrix());
         printf("\n");

         printf("Is Lower Triangular matrix: ");
         YesNo(matrix_[choose - 1].IsLowerTriangularMatrix());
         printf("\n");
         break;
      case 8:
          printf("Print matrices:\n ");
          for (int i = 0; i < 2; ++i)
          {
              cout << matrix_[i] << endl;
              /*
             matrix_[i].Print();
             printf("\n");
              */
          }
          printf("\n");
          break;
      }

      if (variant != 9)
         system("pause");
   }
}

void WorkWithOperators(Matrix* matrix_)
{
    int variant = 0;

    Matrix result;

    double param = 1;
    int choose = 0;

    while (variant != -1)
    {
        PrintOperatorsMenu();

        variant = get_variant(6);

        switch (variant)
        {
        case 1:
           try
           {
              result = matrix_[0] + matrix_[1];
              printf("\nResult of summation:\n");
              cout << result << endl;
              //result.Print();
              //printf("\n");
              WorkWithSaving(matrix_, result);
           }
           catch (const MatrixException& e) 
           {
              e.Print();
           }
           break;
        case 2:
           try
           {
              result = matrix_[0] - matrix_[1];
              printf("\nResult of subtraction:\n");
              cout << result << endl;
              /*
              result.Print();
              printf("\n");
              */
              WorkWithSaving(matrix_, result);
           }
           catch (const MatrixException& e)
           {
              e.Print();
           }
           break;
        case 3:
           try
           {
              printf("Which matrix you want to multiplicate?\n");
              printf("1. The first matrix is multiplied by the second\n");
              printf("2. The second matrix is multiplied by the first\n");
              printf("> ");
              choose = get_variant(2);
              if (choose == 1)
                 result = matrix_[0] * matrix_[1];
              else if (choose == 2)
                 result = matrix_[1] * matrix_[0];
              printf("\nResult of multiplication:\n");
              cout << result << endl;
              /*
              result.Print();
              printf("\n");
              */
              WorkWithSaving(matrix_, result);
           }
           catch (const MatrixException& e)
           {
              e.Print();
           }
           break;
        case 4:
           printf("Which matrix you want to multiplicate?\n");
           printf("> ");
           choose = get_variant(2);
           printf("Insert constant.\n");
           printf("> ");
           scanf_s("%lf", &param);
           result = matrix_[choose - 1] * param;
           printf("\nResult of multiplication by a constant:\n");
           cout << result << endl;
           /*
           result.Print();
           printf("\n");
           */
           WorkWithSaving(matrix_, result);
            break;
        case 5:
           printf("Which matrix you want to division\n");
           printf("> ");
           choose = get_variant(2);
           printf("Insert constant.\n");
           printf("> ");
           scanf_s("%lf", &param);
           result = matrix_[choose - 1] / param;
           printf("\nResult of division by a constant:\n");
           cout << result << endl;
           /*
           result.Print();
           printf("\n");
           */
           WorkWithSaving(matrix_, result);
            break;
        case 6:
           WorkWithMatrix(matrix_);
        }
        if (variant != 6)
           system("pause");
    }
}

void WorkWithSaving(Matrix* matrix_, Matrix& matrixSave_)
{
   int variant = 0;

   while (variant != -1)
   {
      PrintSaveResultMenu();

      variant = get_variant(2);

      switch (variant)
      {
      case 1:
         WorkWhereSaving(matrix_, matrixSave_);
         break;
      case 2:
         WorkWithMatrix(matrix_);
         break;
      }
   }
}

void WorkWhereSaving(Matrix* matrix_, Matrix& matrixSave_)
{
   int variant = 0;

   while (variant != -1)
   {
      PrintWhereSaveResultMenu();

      variant = get_variant(2);

      switch (variant)
      {
      case 1:
         matrix_[0] = matrixSave_;
         WorkWithMatrix(matrix_);
         break;
      case 2:
         matrix_[1] = matrixSave_;
         WorkWithMatrix(matrix_);
         break;
      }
   }
}

void YesNo(bool res_)
{
   if (res_ == true)
      printf("Yes.");
   else
      printf("No.");
}

void PrintMenuSquare()
{
    system("cls");
    printf("What do you want to do?\n");
    printf("1. Insert first matrix.\n");
    printf("2. Insert second matrix.\n");
    printf("3. Using operators.\n");
    printf("4. Using comparison operations.\n");
    printf("5. Find the inverse matrix.\n");
    printf("6. Find the transposed matrix.\n");
    printf("7. Find the degree of the matrix.\n");
    printf("8. Find norms.\n");
    printf("9. Find the determinant of the matrix.\n");
    printf("10. Determine the type of matrix.\n");
    printf("11. Print matrices.\n");
    printf("12. Exit\n");
    printf(">");
}

void PrintOperatorsMenuForSquareMatrix()
{
    system("cls");
    printf("What do you want to do?\n");
    printf("1. Operator +.\n");
    printf("2. Operator -.\n");
    printf("3. Operator * (with other matrix).\n");
    printf("4. Operator * (with constant).\n");
    printf("5. Operator / (with other matrix)\n");
    printf("6. Operator / (with constant)\n");
    printf("7. Return.\n");
    printf(">");
}

void WorkWithSavingForSquare(SquareMatrix* matrix_, SquareMatrix& matrixSave_)
{
    int variant = 0;

    while (variant != -1)
    {
        PrintSaveResultMenu();

        variant = get_variant(2);

        switch (variant)
        {
        case 1:
            WorkWhereSavingForSquare(matrix_, matrixSave_);
            break;
        case 2:
            WorkWithSquareMatrix(matrix_);
            break;
        }
    }
}

void WorkWhereSavingForSquare(SquareMatrix* matrix_, SquareMatrix& matrixSave_)
{
    int variant = 0;

    while (variant != -1)
    {
        PrintWhereSaveResultMenu();

        variant = get_variant(2);

        switch (variant)
        {
        case 1:
            matrix_[0] = matrixSave_;
            WorkWithSquareMatrix(matrix_);
            break;
        case 2:
            matrix_[1] = matrixSave_;
            WorkWithSquareMatrix(matrix_);
            break;
        }
    }
}

void WorkWithOperatorsOfSquareMatrix(SquareMatrix* matrix_)
{
    int variant = 0;

    SquareMatrix result;

    double param = 1;
    int choose = 0;

    while (variant != -1)
    {
        PrintOperatorsMenuForSquareMatrix();

        variant = get_variant(7);

        switch (variant)
        {
        case 1:
           try
           {
              result = matrix_[0] + matrix_[1];
              printf("\nResult of summation:\n");
              cout << result << endl;
              /*
              result.Print();
              printf("\n");
              */
              WorkWithSavingForSquare(matrix_, result);
           }
           catch (const MatrixException& e)
           {
              e.Print();
           }
           break;
        case 2:
           try
           {
              result = matrix_[0] - matrix_[1];
              printf("\nResult of subtraction:\n");
              cout << result << endl;
              /*
              result.Print();
              printf("\n");
              */
              WorkWithSavingForSquare(matrix_, result);
           }
           catch (const MatrixException& e)
           {
              e.Print();
           }
           break;
        case 3:
           try
           {
              printf("Which matrix you want to multiplicate?\n");
              printf("1. The first matrix is multiplied by the second\n");
              printf("2. The second matrix is multiplied by the first\n");
              printf("> ");
              choose = get_variant(2);
              if (choose == 1)
                 result = matrix_[0] * matrix_[1];
              else if (choose == 2)
                 result = matrix_[1] * matrix_[0];
              printf("\nResult of multiplication:\n");
              cout << result << endl;
              /*
              result.Print();
              printf("\n");
              */
              WorkWithSavingForSquare(matrix_, result);
           }
           catch (const MatrixException& e)
           {
              e.Print();
           }
            break;
        case 4:
            printf("Which matrix you want to multiplicate?\n");
            printf("> ");
            choose = get_variant(2);
            printf("Insert constant.\n");
            printf("> ");
            scanf_s("%lf", &param);
            result = matrix_[choose - 1] * param;
            printf("\nResult of multiplication by a constant:\n");
            cout << result << endl;
            /*
            result.Print();
            printf("\n");
            */
            WorkWithSavingForSquare(matrix_, result);
            break;
        case 5:
           try
           {
              printf("Which matrix you want division?\n");
              printf("1. The first matrix is divided by the second\n");
              printf("2. The second matrix is divided by the first\n");
              printf("> ");
              choose = get_variant(2);
              if (choose == 1)
                 result = matrix_[0] / matrix_[1];
              else if (choose == 2)
                 result = matrix_[1] / matrix_[0];
              printf("\nResult of division:\n");
              cout << result << endl;
              /*
              result.Print();
              printf("\n");
              */
              WorkWithSavingForSquare(matrix_, result);
           }
           catch (const MatrixException& e)
           {
              e.Print();
           }
            break;
        case 6:
            printf("Which matrix you want to division\n");
            printf("> ");
            choose = get_variant(2);
            printf("Insert constant.\n");
            printf("> ");
            scanf_s("%lf", &param);
            result = matrix_[choose - 1] / param;
            printf("\nResult of division by a constant:\n");
            cout << result << endl;
            /*
            result.Print();
            printf("\n");
            */
            WorkWithSavingForSquare(matrix_, result);
            break;
        case 7:
            WorkWithSquareMatrix(matrix_);
        }
        if (variant != 7)
           system("pause");
    }
}

void WorkWithSquareMatrix(SquareMatrix* matrix_)
{
    int variant = 0;

    int size = 0;

    int param = 0;
    int choose = 0;

    SquareMatrix result;

    while (variant != 12)
    {
        PrintMenuSquare();

        variant = get_variant(12);

        switch (variant)
        {
        case 1:
            printf("Insert size: ");
            scanf_s("%d", &size);

            matrix_[0] = SquareMatrix(size);

            printf("Insert matrix:\n");
            cin >> matrix_[0];
            /*
            for (int i = 0; i < size; ++i) {
                for (int j = 0; j < size; ++j) {
                    scanf_s("%lf", &matrix_[0][i][j]);
                }
            }
            */
            break;
        case 2:
            printf("Insert size: ");
            scanf_s("%d", &size);
            matrix_[1] = SquareMatrix(size);
            printf("Insert matrix:\n");
            cin >> matrix_[1];
            /*
            for (int i = 0; i < size; ++i)
                for (int j = 0; j < size; ++j)
                    scanf_s("%lf", &matrix_[1][i][j]);
            */
            break;
        case 3:
            WorkWithOperatorsOfSquareMatrix(matrix_);
            break;
        case 4:
            if (matrix_[0] == matrix_[1])
                printf("Matrices are equal.");
            else if (matrix_[0] != matrix_[1])
                printf("Matrices are not equal.");
            break;
        case 5:
            printf("Which matrix you want to inverse?\n");
            printf("> ");
            choose = get_variant(2);
            result = matrix_[choose - 1];
            result.InverseMatrix();
            result.Print();
            WorkWithSavingForSquare(matrix_, result);
            break;
        case 6:
            printf("Which matrix you want to transpose?\n");
            printf("> ");
            choose = get_variant(2);
            result = matrix_[choose - 1];
            result.MatrixTranspose();
            result.Print();
            WorkWithSavingForSquare(matrix_, result);
            break;
        case 7:
            printf("Which matrix you want to find degree?\n");
            printf("> ");
            choose = get_variant(2);
            result = matrix_[choose - 1];
            printf("Invert degree of matrix.\n");
            printf("> ");
            scanf_s("%d", &param);
            result.Power(param);
            result.Print();
            WorkWithSavingForSquare(matrix_, result);
            break;
        case 8:
            printf("What matrix to find the norm for?\n");
            printf("> ");
            choose = get_variant(2);
            printf("First norm: %lf\n", matrix_[choose - 1].FirstMatrixNorm());
            printf("Second norm: %lf\n", matrix_[choose - 1].SecondMatrixNorm());
            printf("Third norm: %lf\n", matrix_[choose - 1].ThirdMatrixNorm());
            break;
        case 9:
            printf("Which matrix you want to find determinant?\n");
            printf("> ");
            choose = get_variant(2);
            result = matrix_[choose - 1];
            printf("%lf\n", result.Determinant());
            break;
        case 10:
            printf("Which matrix you want to check types?\n");
            printf("> ");
            choose = get_variant(2);

            printf("Is Square matrix: ");
            YesNo(matrix_[choose - 1].IsSquareMatrix());
            printf("\n");

            printf("Is Diagonal matrix: ");
            YesNo(matrix_[choose - 1].IsDiagonalMatrix());
            printf("\n");

            printf("Is Null matrix: ");
            YesNo(matrix_[choose - 1].IsNullMatrix());
            printf("\n");

            printf("Is Identity matrix: ");
            YesNo(matrix_[choose - 1].IsIdentityMatrix());
            printf("\n");

            printf("Is Symmetric matrix: ");
            YesNo(matrix_[choose - 1].IsSymmetricMatrix());
            printf("\n");

            printf("Is Upper Triangular matrix: ");
            YesNo(matrix_[choose - 1].IsUpperTriangularMatrix());
            printf("\n");

            printf("Is Lower Triangular matrix: ");
            YesNo(matrix_[choose - 1].IsLowerTriangularMatrix());
            printf("\n");
            break;
        case 11:
            printf("Print matrices:\n ");
            for (int i = 0; i < 2; ++i)
            {
                cout << matrix_[i] << endl;
               // printf("\n");
            }
            printf("\n");
            break;
        }

        if (variant != 12)
            system("pause");
    }
}