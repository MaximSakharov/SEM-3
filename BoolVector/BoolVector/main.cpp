#include <iostream>

#include "BoolVector.hpp"
#include "Exception.hpp"
#include <locale.h>

using namespace std;


int main() 
{
   setlocale(LC_ALL, "RUS");
   // 1. �������� BoolVector � �������� ��������
   BoolVector bv1(5);  // ������� ������ � �������� 5

   // 2. ������������� ��������� PushBack ��� ���������� ���������
   bv1.PushBack(true);
   bv1.PushBack(false);
   bv1.PushBack(true);
   bv1.PushBack(false);
   bv1.PushBack(true);

   // 3. ����� �������
   cout << "Vector bv1: " << bv1 << endl;

   // 4. ������������� ������������ �����������
   BoolVector bv2 = bv1;
   cout << "Vector bv2 (����� bv1): " << bv2 << endl;

   // 5. ������������� ��������� ������������
   BoolVector bv3(3);  // ������ ����� ������
   bv3 = bv1;  // ����������� bv1 � bv3
   cout << "Vector bv3 (������������ bv1): " << bv3 << endl;

   // 6. ������������� ��������� ��������������
   try {
      cout << "Element at index 2 in bv1: " << bv1[-1] << endl;
      cout << "Element at index 5 in bv1 (������): " << bv1[5] << endl;  // ��� ������� ����������
   }
   catch (const IndexOutOfRangeException& e) {
      e.Print();
   }

   // 7. ���������� �������� ����������� � � ���
   BoolVector bv4(5);  // �������� ������ ������ ��� ��������
   bv4.PushBack(true);
   bv4.PushBack(true);
   bv4.PushBack(false);
   bv4.PushBack(true);
   bv4.PushBack(false);

   cout << "Vector bv4: " << bv4 << endl;

   BoolVector bv5 = bv1.OrOperation(bv4);
   cout << "Result of OR operation between bv1 and bv4: " << bv5 << endl;

   BoolVector bv6 = bv1.AndOperation(bv4);
   cout << "Result of AND operation between bv1 and bv4: " << bv6 << endl;

   // 8. ������������� ��������� ���������� ��������� (!)
   BoolVector bv7 = !bv1;
   cout << "Result of NOT operation on bv1: " << bv7 << endl;

   // 9. ������������� ������ SubvectorExtraction
   try {
      BoolVector sub = bv1.SubvectorExtraction(1, 3);  // ��������� �������� � ������� 1 �� 3
      cout << "Subvector from bv1 (1 to 3): " << sub << endl;
   }
   catch (const IndexOutOfRangeException& e) {
      e.Print();
   }

   // 10. ������������� ��������� ������ ����� (ShiftLeftOperation)
   BoolVector bv8 = bv1.ShiftLeftOperation(4);
   cout << "Result of left shift by 2: " << bv8 << endl;

   // 11. ������������� ��������� ������ ������ (ShiftRightOperation)
   BoolVector bv9 = bv1.ShiftRightOperation(4);
   cout << "Result of right shift by 2: " << bv9 << endl;

   // 12. �������� �� ������� ������� (����� Front � Back)
   try {
      cout << "First element in bv1 (Front): " << bv1.Front() << endl;
      cout << "Last element in bv1 (Back): " << bv1.Back() << endl;
   }
   catch (const EmptyVectorException& e) {
      e.Print();
   }

   // 13. ������� � �������������� ���������
   cout << "Iterating over bv1 using iterator: ";
   for (BoolVector::Iterator it = bv1.Begin(); it != bv1.End(); ++it) {
      cout << *it << " ";  // ������� ������ �������
   }
   cout << endl;

   // 14. ������������ �������� ���������
   if (bv1 == bv2) {
      cout << "bv1 � bv2 ���������" << endl;
   }
   else {
      cout << "bv1 � bv2 ������" << endl;
   }

   // 15. ������������ ������������ ���� ��������
   BoolVector bv10 = bv1.Concatenate(bv4);
   cout << "Concatenated bv1 and bv4: " << bv10 << endl;

   // 16. ������������ ���������� ������������
   size_t scalarProduct = bv1.ScalarProduct(bv4);
   cout << "Scalar product of bv1 and bv4: " << scalarProduct << endl;

   return 0;
}

/*
int main()
{
   setlocale(LC_ALL, "RUS");

   bool arr[5] = { 1, 1, 1,0,1 };

   try
   {
      BoolVector a;
      BoolVector b;

      cin >> a;
      cin >> b;
      //a.Print();
      //cout << endl;
      //cout << a.Front();

      cout << a << endl;
      cout << b << endl;

      BoolVector res = a.Concatenate(b);

      cout << res << endl;

      //BoolVector res2;

      //cin >> res2;

      //cout << res2 << endl;

      //a.PopBack();
     //cout << a << endl;

      
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
      

   }
   catch (const Exception& e)
   {
      e.Print();
   }
   
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


   c.Print();
   


      return 0;
   
}
*/