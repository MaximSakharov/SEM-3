#include <iostream>

#include "BoolVector.hpp"

using namespace std;


int main()
{
   try
   {
      BoolVector a;

      cin >> a;

      //a.Print();
      //cout << endl;
      cout << a.Front();

      cout << a << endl;

      a.PopBack();
      cout << a << endl;

      /*
      BoolVector b(3);
      b.PushBack(0);
      b.PushBack(1);
      b.PushBack(0);
      b.PushBack(1);
      b.PushBack(0);

      b.Print();

      BoolVector c = a.OrOperation(b);
      BoolVector d = a.AndOperation(b);

      cout << endl;
      c.Print();
      cout << endl;
      d.Print();
      */

   }
   catch (const int)
   {
      printf("Error!");
   }
   /*
   bool* arr1 = new bool[3];
   arr1[0] = true;
   arr1[1] = false;
   arr1[2] = true;

   bool* arr2 = new bool[3];
   arr2[0] = false;
   arr2[1] = true;
   arr2[2] = false;

   BoolVector a(arr1, 3);
   BoolVector b(arr2, 3);

   a.Print();
   b.Print();

   BoolVector c = a >> 1;

   c.Print();
   */


      return 0;
   
}