#include <iostream>
#include <string.h>

#include "Triangle.hpp"
#include "functions.hpp"

using namespace std;

int Triangle::count = 1;

int main()
{
   setlocale(LC_ALL, "RU");

   Triangle* triangle = Triangle::CreateTriangleArray(100);

   Work_Triangle(triangle);

   delete[] triangle;

   return 0;
}