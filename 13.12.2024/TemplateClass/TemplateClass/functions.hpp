#include <iostream>

#ifndef SMOOTHMATR_H
#define SMOOTHMATR_H

template <typename T, typename D>
inline D** SmoothMatr(T** matr_, int size_)
{
   D** new_matr = new D * [size_];
   for (int i = 0; i < size_; ++i)
      new_matr[i] = new D[size_];

   for (int i = 0; i < size_; ++i)
   {
      for (int j = 0; j < size_; ++j)
      {
         D sum = 0;
         int amount = 0;

         for (int p = i - 1; p <= i + 1; ++p)
         {
            for (int n = j - 1; n <= j + 1; ++n)
            {
               if (p < 0 || p >= size_ || n < 0 || n >= size_ || (p == i && n == j))
                  continue;

               sum += matr_[p][n];
               ++amount;
            }
         }

         if (amount > 0)
            new_matr[i][j] = sum / amount;
         else
            new_matr[i][j] = matr_[i][j];
      }
   }

   return new_matr;
}

#endif