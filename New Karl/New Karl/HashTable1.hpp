#include <iostream>

using namespace std;

class HashTable1 {
private:
   struct Node {
      int data;
      int link;  // »ндекс следующего элемента (ссылка)
      bool isOccupied;  // ‘лаг, указывающий, зан€та ли €чейка

      Node() : data(0), link(-1), isOccupied(false) {} // »нициализаци€ пустой ссылки
   };

   Node* hash;
   int size;
   //int new_pos;
public:
   HashTable1(int size_ = 10) {
      size = size_;
     // new_pos = size - 1;
      hash = new Node[size];
   }

   ~HashTable1() {
      delete[] hash;
   }

   void Insert(int value) {
      int i = value % size; // »ндекс, полученный по хеш-функции
      int R = size - 1;  // »ндекс дл€ поиска свободной €чейки

      // Ўаг 2: ≈сли €чейка свободна, переходим к шагу 14
      if (!hash[i].isOccupied) {
         cout << "Ёлемент " << value << " вставлен в позицию " << i << endl;
         hash[i].data = value;
         hash[i].isOccupied = true;
         hash[i].link = -1;  // ”станавливаем пустую ссылку
         return;
      }

      // Ўаг 3: ѕока текущий элемент не равен x и есть следующа€ €чейка, продолжаем
      while (hash[i].data != value && hash[i].link != -1) {
         i = hash[i].link;  // ѕереходим к следующему элементу в цепочке
      }

      // Ўаг 6: ≈сли элемент уже существует в таблице, сообщаем об этом
      if (hash[i].data == value) {
         cout << "Ёлемент " << value << " найден." << endl;
         return;
      }

      // Ўаг 7: »щем первую свободную €чейку
      while (R >= 0 && hash[R].isOccupied) {
         R--;
      }

      // Ўаг 10: ≈сли свободных €чеек нет, сообщаем о переполнении
      if (R == -1) {
         cout << "“аблица переполнена!" << endl;
         return;
      }

      // Ўаг 13: ”станавливаем ссылку на свободную €чейку
      hash[i].link = R;
      i = R;

      // Ўаг 14: ¬ставл€ем элемент в найденную €чейку
      hash[i].data = value;
      hash[i].isOccupied = true;
      hash[i].link = -1;  // ”станавливаем пустую ссылку дл€ нового элемента

      cout << "Ёлемент " << value << " вставлен в позицию " << i << endl;
   }

   void Print() {
      for (int i = 0; i < size; ++i) {
         if (hash[i].isOccupied) {
            cout << "»ндекс " << i << ": " << hash[i].data;
            if (hash[i].link != -1) {
               cout << " (ссылка на " << hash[i].link << ")";
            }
            cout << endl;
         }
         else {
            cout << "»ндекс " << i << ": пусто" << endl;
         }
      }
   }

   void DeleteEl(int value)
   {

   }
};