#include <iostream>

#include "vector.hpp"
/*
class Vector {
private:
   double* elements;
   size_t size;

public:
   // �����������
   Vector(size_t s) : size(s) 
   {
      elements = new double[size];  // �������� ������
      for (size_t i = 0; i < size; ++i) 
         elements[i] = 0.0;  // �������������� ������
   }

   // ����������� � ��������������
   Vector(const double* elems, size_t s) : size(s) {
      elements = new double[size];
      for (size_t i = 0; i < size; ++i) {
         elements[i] = elems[i];
      }
   }

   // ����������
   ~Vector() {
      delete[] elements;  // ����������� ������
   }

   // ����� ������
   void print() const {
      std::cout << "[ ";
      for (size_t i = 0; i < size; ++i) {
         std::cout << elements[i] << " ";
      }
      std::cout << "]" << std::endl;
   }

   // ����� �������� ��������
   Vector operator+(const Vector& other) const {
      if (size != other.size) {
         std::cerr << "������: ������� �������� �� ���������!" << std::endl;
         return Vector(0); // ���������� ������ ������
      }

      Vector result(size);
      for (size_t i = 0; i < size; ++i) {
         result.elements[i] = elements[i] + other.elements[i];
      }
      return result;
   }

   // ����� ��������� ��������
   Vector operator-(const Vector& other) const {
      if (size != other.size) {
         std::cerr << "������: ������� �������� �� ���������!" << std::endl;
         return Vector(0); // ���������� ������ ������
      }

      Vector result(size);
      for (size_t i = 0; i < size; ++i) {
         result.elements[i] = elements[i] - other.elements[i];
      }
      return result;
   }

   // ����� ������������
   Vector concatenate(const Vector& other) const {
      Vector result(size + other.size);
      for (size_t i = 0; i < size; ++i) {
         result.elements[i] = elements[i];
      }
      for (size_t i = 0; i < other.size; ++i) {
         result.elements[size + i] = other.elements[i];
      }
      return result;
   }
};
*/

int main() 
{
   
   double arr1[] = { 1.0, 2.0, 3.0 };
   double arr2[] = { 4.0, 5.0, 6.0 };

   Vector v1(3, arr1);
   Vector v2(3, arr2);

   std::cout << "������ v1: ";
   v1.Print();

   std::cout << "������ v2: ";
   v2.Print();

   Vector sum = v1 + v2;
   std::cout << "����� v1 � v2: ";
   sum.Print();

   Vector diff = v1 - v2;
   std::cout << "�������� v1 � v2: ";
   diff.Print();

   Vector concatenated = v1.concatenate(v2);
   std::cout << "������������ v1 � v2: ";
   concatenated.Print();

   return 0;
}