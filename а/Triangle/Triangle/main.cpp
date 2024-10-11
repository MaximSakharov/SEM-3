#include <iostream>
#include <string.h>

#include "Triangle.hpp"
#include "functions.hpp"

using namespace std;

int Triangle::count = 0;

int main()
{
   setlocale(LC_ALL, "RU");

   Triangle* triangle = new Triangle[100];

   Work_Triangle(triangle);

   return 0;
}