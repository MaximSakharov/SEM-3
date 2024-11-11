#include <iostream>

using namespace std;

class HashTable1 {
private:
   struct Node {
      int data;
      int link;  // ������ ���������� �������� (������)
      bool isOccupied;  // ����, �����������, ������ �� ������

      Node() : data(0), link(-1), isOccupied(false) {} // ������������� ������ ������
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
      int i = value % size; // ������, ���������� �� ���-�������
      int R = size - 1;  // ������ ��� ������ ��������� ������

      // ��� 2: ���� ������ ��������, ��������� � ���� 14
      if (!hash[i].isOccupied) {
         cout << "������� " << value << " �������� � ������� " << i << endl;
         hash[i].data = value;
         hash[i].isOccupied = true;
         hash[i].link = -1;  // ������������� ������ ������
         return;
      }

      // ��� 3: ���� ������� ������� �� ����� x � ���� ��������� ������, ����������
      while (hash[i].data != value && hash[i].link != -1) {
         i = hash[i].link;  // ��������� � ���������� �������� � �������
      }

      // ��� 6: ���� ������� ��� ���������� � �������, �������� �� ����
      if (hash[i].data == value) {
         cout << "������� " << value << " ������." << endl;
         return;
      }

      // ��� 7: ���� ������ ��������� ������
      while (R >= 0 && hash[R].isOccupied) {
         R--;
      }

      // ��� 10: ���� ��������� ����� ���, �������� � ������������
      if (R == -1) {
         cout << "������� �����������!" << endl;
         return;
      }

      // ��� 13: ������������� ������ �� ��������� ������
      hash[i].link = R;
      i = R;

      // ��� 14: ��������� ������� � ��������� ������
      hash[i].data = value;
      hash[i].isOccupied = true;
      hash[i].link = -1;  // ������������� ������ ������ ��� ������ ��������

      cout << "������� " << value << " �������� � ������� " << i << endl;
   }

   void Print() {
      for (int i = 0; i < size; ++i) {
         if (hash[i].isOccupied) {
            cout << "������ " << i << ": " << hash[i].data;
            if (hash[i].link != -1) {
               cout << " (������ �� " << hash[i].link << ")";
            }
            cout << endl;
         }
         else {
            cout << "������ " << i << ": �����" << endl;
         }
      }
   }

   void DeleteEl(int value)
   {

   }
};