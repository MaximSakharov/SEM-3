#include <iostream>

using namespace std;

struct NodeD
{
   int data;
   NodeD* prev;
   NodeD* next;
};

class DoublyList
{
private:
   NodeD* head;
   NodeD* tail;
   int size;
public:
   DoublyList()
      : size(0)
   {
      head = nullptr;
      tail = nullptr;
   }
   DoublyList(int* arr, int size_)
      : size(size_)
   {
      if (size == 0)
      {
         head = nullptr;
         tail = nullptr;
         return;
      }

      head = new NodeD;
      head->data = arr[0];
      head->prev = nullptr;
      //tail = head;
      
      NodeD* prev = head;
      NodeD* cur;
      NodeD* prev1;

      for (int i = 1; i < size; ++i)
      {
         cur = new NodeD;
         prev1 = prev;

         cur->data = arr[i];
         cur->prev = prev1;
         prev->next = cur;
         prev = cur;
      }
      prev->next = nullptr;
      tail = prev;
   }
   ~DoublyList()
   {
      NodeD* cur = head;
      while (cur)
      {
         NodeD* nextNode = cur->next;
         delete cur;
         cur = nextNode;
      }
      cur = tail;
      head = nullptr;
      tail = nullptr;
      size = 0;
   }
   void Clear()
   {
      NodeD* cur = head;
      while (cur)
      {
         NodeD* nextNode = cur->next;
         delete cur;
         cur = nextNode;
      }
      cur = tail;
      head = nullptr;
      tail = nullptr;
      size = 0;
   }
   void Print()
   {
      NodeD* cur = head;
      cout << "( ";
      if (size == 0)
      {
         cout << ")";
         return;
      }
      while (cur != tail)
      {
         cout << cur->data << ", ";
         cur = cur->next;
      }
      cout << cur->data << " )";
   }
   DoublyList& operator=(const DoublyList& other_)
   {
      if (this == &other_)
         return *this;

      this->Clear();
      head = new NodeD;
      tail = new NodeD;
      size = other_.size;

      if (!other_.head && !other_.tail && other_.size == 0)
      {
         return *this;
      }

      head->data = other_.head->data;
      head->prev = nullptr;
      //tail = head;

      NodeD* prev = head;
      NodeD* cur;
      NodeD* prev1;

      NodeD* NewNode = other_.head;

      for (int i = 1; i < size; ++i)
      {
         cur = new NodeD;
         prev1 = prev;
         NewNode = NewNode->next;

         cur->data = NewNode->data;
         cur->prev = prev1;
         prev->next = cur;
         prev = cur;
      }
      prev->next = nullptr;
      tail = prev;

      return *this;
   }
   DoublyList(const DoublyList& other_)
   {
      this->Clear();
      head = new NodeD;
      tail = new NodeD;
      size = other_.size;

      if (!other_.head && !other_.tail && other_.size == 0)
      {
         return ;
      }

      head->data = other_.head->data;
      head->prev = nullptr;
      //tail = head;

      NodeD* prev = head;
      NodeD* cur;
      NodeD* prev1;

      NodeD* NewNode = other_.head;

      for (int i = 1; i < size; ++i)
      {
         cur = new NodeD;
         prev1 = prev;
         NewNode = NewNode->next;

         cur->data = NewNode->data;
         cur->prev = prev1;
         prev->next = cur;
         prev = cur;
      }
      prev->next = nullptr;
      tail = prev;
   }

   friend ostream& operator<<(ostream& stream, DoublyList& list_);

   friend istream& operator>>(istream& stream, DoublyList& list_);
};

ostream& operator<<(ostream& stream, DoublyList& list_)
{
   stream << "(";

   if (list_.size == 0)
   {
      stream << ")";
      return stream;
   }
   NodeD* cur = list_.head;

   for (int i = 0; i < list_.size - 1; ++i)
   {
      stream << cur->data << ", ";
      cur = cur->next;
   }
   stream << cur->data << ")";

   return stream;
}


istream& operator>>(istream& stream, DoublyList& list_)
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

      list_.head = new NodeD;
      list_.tail = new NodeD;
      list_.head->data = value;
      list_.tail = list_.head;
      NodeD* cur = list_.head;
      list_.size++;

      while (stream.peek() == ',')
      {
         stream.ignore();
         stream >> value;
         if (!stream.good())
            throw 1;

         NodeD* newNode = new NodeD;
         newNode->data = value;
         cur->next = newNode;
         cur = newNode;
         ++list_.size;
      }
      cur->next = nullptr;
      list_.tail = cur;
      if (stream.peek() == ')')
         stream.ignore();
      else
         throw 1;
   }
   catch (const int)
   {
      printf("HAHAHA!");
      return stream;
   }

   return stream;
}