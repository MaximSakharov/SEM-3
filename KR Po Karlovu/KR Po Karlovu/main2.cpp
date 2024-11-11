#include <iostream>
#include "List.hpp"
#include "DoublyList.hpp"
#include <stack> 
#include "Stack.hpp"
#include "Queue.hpp"
#include "BinTree.hpp"

#include "HashTable1.hpp"

using namespace std;

Node* hash = new Node;

int main()
{
   HashTable1 table1(7);

   //table1.Print();
   table1.Incert(2);
   table1.Print();


   return 0;
}