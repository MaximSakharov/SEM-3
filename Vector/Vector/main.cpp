#include <iostream>
#include <locale.h>

#include "vector.hpp"
/*
class Vector {
private:
   double* elements;
   size_t size;

public:
   // Конструктор
   Vector(size_t s) : size(s) 
   {
      elements = new double[size];  // Выделяем память
      for (size_t i = 0; i < size; ++i) 
         elements[i] = 0.0;  // Инициализируем нулями
   }

   // Конструктор с инициализацией
   Vector(const double* elems, size_t s) : size(s) {
      elements = new double[size];
      for (size_t i = 0; i < size; ++i) {
         elements[i] = elems[i];
      }
   }

   // Деструктор
   ~Vector() {
      delete[] elements;  // Освобождаем память
   }

   // Метод печати
   void print() const {
      std::cout << "[ ";
      for (size_t i = 0; i < size; ++i) {
         std::cout << elements[i] << " ";
      }
      std::cout << "]" << std::endl;
   }

   // Метод сложения векторов
   Vector operator+(const Vector& other) const {
      if (size != other.size) {
         std::cerr << "Ошибка: размеры векторов не совпадают!" << std::endl;
         return Vector(0); // Возвращаем пустой вектор
      }

      Vector result(size);
      for (size_t i = 0; i < size; ++i) {
         result.elements[i] = elements[i] + other.elements[i];
      }
      return result;
   }

   // Метод вычитания векторов
   Vector operator-(const Vector& other) const {
      if (size != other.size) {
         std::cerr << "Ошибка: размеры векторов не совпадают!" << std::endl;
         return Vector(0); // Возвращаем пустой вектор
      }

      Vector result(size);
      for (size_t i = 0; i < size; ++i) {
         result.elements[i] = elements[i] - other.elements[i];
      }
      return result;
   }

   // Метод конкатенации
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
   setlocale(LC_ALL, "RU");

   double arr1[] = { 1.0, 2.0, 3.0 };
   double arr2[] = { 4.0, 5.0, 6.0 };

   Vector v1(arr1, 3);
   Vector v2(arr2, 3);

   std::cout << "Вектор v1: ";
   v1.Print();

   std::cout << "Вектор v2: ";
   v2.Print();

   Vector sum = v1 + v2;
   std::cout << "Сумма v1 и v2: ";
   sum.Print();

   Vector diff = v1 - v2;
   std::cout << "Разность v1 и v2: ";
   diff.Print();

   v1 += v2;
   std::cout << "Сумма v1 и v2: ";
   v1.Print();

   v1 -= v2;
   std::cout << "Разность v1 и v2: ";
   v1.Print();

   Vector cant = v1 & v2;
   std::cout << "Конкатенация v1 и v2: ";
   cant.Print();
   /*
   v1 &= v2;
   std::cout << "Конкатенация v1 и v2: ";
   v1.Print();
   */

   printf("%d\n", v1 == v2);
   printf("%d\n", v1 != v2);

   /*
   Vector concatenated = v1.concatenate(v2);
   std::cout << "Конкатенация v1 и v2: ";
   concatenated.Print();
   */

   return 0;
}