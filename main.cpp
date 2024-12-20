#pragma warning(disable:4996)
#include <iostream>
using namespace std;

void matrix_create_F(const char* filename_, int& size_, int**& matrix_)
{
   FILE* f1 = fopen(filename_, "r");
   if (!f1)
      return ;

   if (fscanf(f1, "%d", &size_) != 1)
   {
      perror("Error reading matrix size");
      fclose(f1);
      exit(EXIT_FAILURE);
   }

   matrix_ = new int* [size_];

   for (int i = 0; i < size_; ++i)
      matrix_[i] = new int[size_];

   for (int i = 0; i < size_; ++i) 
   {
      for (int j = 0; j < size_; ++j) 
      {
         if (fscanf(f1, "%d", &matrix_[i][j]) != 1) 
         {
            perror("Error reading matrix elements");
            fclose(f1);
            // Free allocated memory before exiting
            for (int k = 0; k <= i; ++k) 
            {
               delete[] matrix_[k];
            }
            delete[] matrix_;
            exit(EXIT_FAILURE);
         }
      }
   }

   fclose(f1);
}

bool is_magic_square(int**& matrix_, int& size_)
{
   if (size_ == 1)
      return true;

   int final_sum = 0;
   int test_sum = 0;

   for (int i = 0; i < size_; ++i)
      final_sum += matrix_[i][i];

   for (int i = 0, j = size_ - 1; i < size_ && j >= 0; ++i, --j)
      test_sum += matrix_[i][j];

   if (final_sum != test_sum)
      return false;

   for (int i = 0; i < size_; ++i)
   {
      test_sum = 0;
      for (int j = 0; j < size_; ++j)
         test_sum += matrix_[i][j];
      
      if (test_sum != final_sum)
         return false;
   }

   for (int i = 0; i < size_; ++i)
   {
      test_sum = 0;
      for (int j = 0; j < size_; ++j)
         test_sum += matrix_[j][i];

      if (test_sum != final_sum)
         return false;
   }

   return true;
}

int main()
{
   int size = 0;
   int** matrix = nullptr;

   matrix_create_F("matrix.txt", size, matrix);

   if (is_magic_square(matrix, size))
      cout << "This is a magic square!\n";
   else
      cout << "This is not a magic square!\n";

   for (int i = 0; i < size; ++i) {
      delete[] matrix[i];
   }
   delete[] matrix;

   return 0;
}