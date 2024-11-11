#include <iostream>

using namespace std;

struct Node
{
   int data;
   Node* next;
};

class List
{
private:
   Node* head;
   size_t size;
public:
   List() { head = nullptr; size = 0; }
   List(int* arr_, int size_)
      :size(size_)
   {
      if (size == 0)
      {
         head = nullptr;
         return ;
      }
      head = new Node;
      head->data = arr_[0];
      Node* prev = head;
      Node* cur;
      for (int i = 1; i < size; ++i)
      {
         cur = new Node;
         cur->data = arr_[i];
         prev->next = cur;
         prev = cur;
      }
      prev->next = nullptr;
   }
   ~List()
   {
      Node* cur = head;
      while (cur)
      {
         Node* nextHead = cur->next;
         delete cur;
         cur = nextHead;
         //printf("Word dest!!");
      }
      head = nullptr;
   }
   void Clear()
   {
      Node* cur = head;
      while (cur)
      {
         Node* nextHead = cur->next;
         delete cur;
         cur = nextHead;
         //printf("Word dest!!");
      }
      size =  0;
      head = nullptr;
   }

   List& operator= (const List& other_)
   {
      if (this == &other_)
         return *this;

      delete head;
      size = other_.size;
      head = new Node;

      if (!other_.head && other_.size == 0)
      {
         return *this;
      }

      Node* prev = head;
      Node* cur1;
      Node* cur2 = other_.head->next;
      for (int i = 1; i < size; ++i)
      {
         cur1 = new Node;
         cur1->data = cur2->data;
         prev->next = cur1;
         prev = prev->next;
         cur2 = cur2->next;
      }
      prev->next = nullptr;

      return *this;
   }
   List (const List& other_)
   {
      delete head;
      size = other_.size;
      head = new Node;
      
      if (!other_.head && other_.size == 0)
      {
         return ;
      }

      Node* prev = head;
      Node* cur1;
      Node* cur2 = other_.head->next;
      for (int i = 1; i < size; ++i)
      {
         cur1 = new Node;
         cur1->data = cur2->data;
         prev->next = cur1;
         prev = prev->next;
         cur2 = cur2->next;
      }
      prev->next = nullptr;
   }
   void Print()
   {
      Node* cur = head;
      while (cur)
      {
         cout << cur->data << " ";
         cur = cur->next;
      }
   }

   friend ostream& operator<<(ostream& stream, List& list_);

   friend istream& operator>>(istream& stream, List& list_);
};

ostream& operator<<(ostream& stream, List& list_)
{
   stream << "(";

   if (list_.size == 0)
   {
      stream << ")";
      return stream;
   }
   Node* cur = list_.head;

   for (int i = 0; i < list_.size - 1; ++i)
   {
      stream << cur->data << ", ";
      cur = cur->next;
   }
   stream << cur->data << ")";

   return stream;
}


istream& operator>>(istream& stream, List& list_)
{
   char ch;
   int value;
   list_.Clear();

   try
   { 
      stream >> ch;
      if (ch != '(')
         throw 1;

      if (stream.peek() == ')')
      {
         stream.ignore();
         return stream;
      }

      stream >> value;
      if (!stream.good())
         throw 1;

      list_.head = new Node;
      list_.head->data = value;
      Node* cur = list_.head;
      list_.size++;

      while (stream.peek() == ',')
      {
         stream.ignore();
         stream >> value;
         if (!stream.good())
            throw 1;

         Node* newNode = new Node;
         newNode->data = value;
         cur->next = newNode;
         cur = newNode;
         ++list_.size;
      }
      cur->next = nullptr;
      if (stream.peek() == ')')
         stream.ignore();
      else
         throw 1;
   }
   catch(const int)
   {
      printf("HAHAHA!");
      return stream;
   }

   return stream;
}