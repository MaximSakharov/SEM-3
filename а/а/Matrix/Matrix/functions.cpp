#include <iostream>
#include <math.h>
#include <string.h>

#include "matrix.hpp"
#include "square_matrix.hpp"

void Print_Menu()
{
   system("cls");  // ??????? ?????
   printf("What do you want to do?\n");
   printf("1. Print Triangles.\n");
   printf("2. Insert Triangle.\n");
   printf("3. Move Triangle.\n");
   printf("4. ?alculate the area of a triangle.\n");
   printf("5. Compare Triagles.\n");
   printf("6. Determine the entry into the triangle.\n");
   printf("7. Delete triangle.\n");
   printf("8. Exit\n");
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

void WorkWithMatrix(Matrix& matrix_)
{
   int variant = 0;

   double x = 0;
   double y = 0;

   int num1 = 0;
   int num2 = 0;

   while (variant != 8)
   {
      Print_Menu();

      variant = get_variant(8);

      switch (variant)
      {
      case 1:

         break;
      case 2:
         printf("Insert points: ");
         break;
      case 3:
         printf("Insert number of triangle: ");

         break;
      case 4:
         printf("Insert number of triangle: ");
         break;
      case 5:
         printf("Insert number of first triangle: ");
         break;
      case 6:
         printf("Insert number of first triangle: ");
         break;
      case 7:
         printf("Insert number of triangle to delete: ");
         break;
      }
      if (variant != 8)
         system("pause");
   }
}