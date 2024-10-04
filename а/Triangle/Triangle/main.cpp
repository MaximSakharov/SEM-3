#include <iostream>
#include <string.h>

#include "Triangle.hpp"
#include "functions.hpp"

using namespace std;

int main()
{
   setlocale(LC_ALL, "RU");

   Triangle triangle[100];

   Work_Triangle(triangle);

   return 0;
}