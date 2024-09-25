#include <iostream>
#include <string.h>
#include <stdlib.h>

//#include "sotrudnic.hpp" 
//#include "base.hpp"
//#include "functions.hpp"

void Print_Menu()
{
   system("cls");  // очищаем экран
   printf("What do you want to do?\n");
   printf("1. Create base with a text file\n");
   printf("2. Print base\n");
   printf("3. Insert new data in base\n");
   printf("4. Delete data from base\n");
   printf("5. Correct data in base\n");
   printf("6. Copy base\n");
   printf("7. Exit\n");
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