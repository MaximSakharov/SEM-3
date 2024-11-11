#include <iostream>

using namespace std;

class HashTable1
{
private:
   struct Node
   {
      int data;
      int link;

      Node() : link(0) {}
   };
   Node* hash;
   int size;
public:
   HashTable1(int size_ = 0)
   {
      size = size_;
      hash = new Node[size];
      for (int i = 0; i < size; ++i)
      {
         hash[i].data = NULL;
         hash[i].link = NULL;
      }
   }
   ~HashTable1()
   {
      delete[] hash;
   }
   void Incert(int value_)
   {
      int pos = value_ % size;
      int new_pos = size - 1;

      //Node* cur = hash[pos];
      //cur->data = value_;

      if (hash[pos].data == NULL)
      {
         hash[pos].data = value_;
         //hash[pos].link = NULL;
         return;
      }
      else
      {
         while (new_pos >= 0 && hash[new_pos].data != NULL)
         {
            --new_pos;
         }
         if (new_pos < 0)
         {
            printf("Hash is fully!");
            return;
         }
         hash[pos].link = new_pos;
         hash[new_pos].link = new_pos - 1;
         hash[new_pos].data = value_;
      }
   }
   void Print()
   {
      for (int i = 0; i < size; ++i)
      {
         cout << i << " " << hash[i].data << " " << hash[i].link << "\n";
      }
   }
};