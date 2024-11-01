#include <iostream>
#include <string.h>
#include <math.h>

#include "Triangle.hpp"

double Pythag(Point v1_, Point v2_) 
{
   double deltaX = v1_.GetX() - v2_.GetX();
   double deltaY = v1_.GetY() - v2_.GetY();

   return sqrt(deltaX * deltaX + deltaY * deltaY);
}

double MaxByThree(double a, double b, double c)
{
   if (a >= b && a >= c)
      return a;
   else if (b >= a && b >= c)
      return b;
   else
      return c;
}

double MinByThree(double a, double b, double c)
{
   if (a <= b && a <= c)
      return a;
   else if (b <= a && b <= c)
      return b;
   else
      return c;
}

void Print_Menu()
{
   system("cls");  // î÷èùàåì ýêðàí
   printf("What do you want to do?\n");
   printf("1. Print Triangles.\n");
   printf("2. Insert Triangle.\n");
   printf("3. Move Triangle.\n");
   printf("4. Ñalculate the area of a triangle.\n");
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