#include "functions.hpp"

int main()
{
   const int size = 4;  // ������ �������
   int** matr = new int* [size];
   for (int i = 0; i < size; ++i)
      matr[i] = new int[size];

   int mt[size][size] =
   { { 4, 5, 7, 12 },
     { 8, 6, 9, 2 },
     { 13, 18, 20, 5 },
     { 1, 2, 3, 4 } };

   // ���������� �������
   for (int i = 0; i < size; ++i)
      for (int j = 0; j < size; ++j)
         matr[i][j] = mt[i][j];

   // ����� ������� SmoothMatr
   double** smoothed_matr = SmoothMatr<int, double>(matr, size);

   // ����� �������� �������
   std::cout << "Original Matrix:" << std::endl;
   for (int i = 0; i < size; ++i) {
      for (int j = 0; j < size; ++j) {
         std::cout << matr[i][j] << " ";
      }
      std::cout << std::endl;
   }

   // ����� ���������� �������
   std::cout << "\nSmoothed Matrix:" << std::endl;
   for (int i = 0; i < size; ++i) {
      for (int j = 0; j < size; ++j) {
         std::cout << smoothed_matr[i][j] << " ";
      }
      std::cout << std::endl;
   }

   // ������������ ������ ��� �������� �������
   for (int i = 0; i < size; ++i) {
      delete[] matr[i];
   }
   delete[] matr;

   // ������������ ������ ��� ���������� �������
   for (int i = 0; i < size; ++i) {
      delete[] smoothed_matr[i];
   }
   delete[] smoothed_matr;

   return 0;
}