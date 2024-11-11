#include "HashTable1.hpp"

#include <locale.h>
using namespace std;

int main()
{
   setlocale(LC_ALL, "Rus");

   HashTable1 table1(7);

   //table1.Print();
   table1.Insert(2);
   table1.Print();
   cout << "\n";
   table1.Insert(6);
   table1.Print(); cout << "\n";
   table1.Insert(9);
   table1.Print(); cout << "\n";
   table1.Insert(14);
   table1.Print(); cout << "\n";
   table1.Insert(12);
   table1.Print(); cout << "\n";
   table1.Insert(16);
   table1.Print(); cout << "\n";
   table1.Insert(23);
   table1.Print(); cout << "\n";


   return 0;
}