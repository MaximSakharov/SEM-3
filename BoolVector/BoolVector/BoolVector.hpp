#include <iostream>

using namespace std;

class BoolVector
{
private:
   bool* elements;
   size_t size;
   size_t capacity;
public:
   BoolVector(bool* elems_ = nullptr, size_t capacity_ = 0)
      : elements(elems_), capacity(capacity_), size(0)
   {
      if (capacity_ > 0)
      {
         elements = new bool[capacity_];
         size = capacity_;
         for (size_t i = 0; i < capacity; ++i)
            elements[i] = (elems_ ? elems_[i] : false);
      }
   }
   ~BoolVector()
   {
      if (elements)
         delete[] elements;
   }

   bool& operator[](size_t i) const
   {
      if (i >= size) // size or capacity?
         throw 1;

      return elements[i];
   }
   BoolVector& operator=(const BoolVector& other_) 
   {
      if (this != &other_) 
      {
         delete[] elements;
         size = other_.size;
         capacity = other_.capacity;
         elements = new bool[capacity];

         for (size_t i = 0; i < size; ++i)
            elements[i] = other_[i];
      }
      return *this;
   }
   BoolVector(const BoolVector& other_)
      : size(other_.size), capacity(other_.capacity), elements(nullptr) 
   {
      if (capacity > 0) 
      {
         elements = new bool[capacity];
         for (size_t i = 0; i < size; ++i)
            elements[i] = other_[i];
      }
   }

   bool GetElement(size_t pos_)
   {
      if (pos_ >= size) // size or capacity?
         throw 1;

      return elements[pos_];
   }
   void SetElement(size_t pos_, bool new_element_)
   {
      if (pos_ >= size) // size or capacity?
         throw 1;

      elements[pos_] = new_element_;
   }

   BoolVector OrOperation(const BoolVector& other_) const // | or |= ?
   {
      if (size != other_.size)
         throw 2;

      BoolVector result(nullptr, size);

      for (size_t i = 0; i < size; ++i)
      {
         result[i] = (elements[i] || other_.elements[i]);
      }

      return result;
   }
   BoolVector AndOperation(const BoolVector& other_) const // | or |= ?
   {
      if (size != other_.size)
         throw 2;

      BoolVector result(nullptr, size);

      for (size_t i = 0; i < size; ++i)
      {
         result[i] = (elements[i] && other_.elements[i]);
      }

      return result;
   }

   /*
      BoolVector operator^(const BoolVector& other) const {
        if (size != other.size) {
            throw std::invalid_argument("Vectors must be of the same size");
        }
        BoolVector result(size);
        for (size_t i = 0; i < size; ++i) {
            result.set(i, get(i) ^ other.get(i));
        }
        return result;
    }
   */

   BoolVector operator!() const
   {
      BoolVector result(nullptr, size);

      for (size_t i = 0; i < size; ++i)
         result[i] = !elements[i];

      return result;
   }
   void Print()
   {
      for (size_t i = 0; i < size; ++i)
         cout << elements[i] << " ";

      cout << endl;
   }
   /*
   int operator*(const BoolVector& other_) const
   {
      if (size != other_.size)
         throw 2;

      double result = 0;
      for (size_t i = 0; i < size; ++i) {
         result += elements[i] * other_.elements[i];
      }
      return result;
   }
   */
   size_t ScalarProduct(const BoolVector& other_) const 
   {
      if (size != other_.size)
         throw 2;

      size_t result = 0;
      for (size_t i = 0; i < size; ++i)
         result += (elements[i] && other_.elements[i]);
      
      return result;
   }
   BoolVector concatenate(const BoolVector& other_) const
   {
      bool *arr = new bool[size + other_.size];

      BoolVector result(arr, size + other_.size);

      for (size_t i = 0; i < size; ++i)
         result.elements[i] = elements[i];
      for (size_t i = 0; i < other_.size; ++i)
         result.elements[i + size] = other_.elements[i];

      return result;
   }
   BoolVector operator<<(size_t n) const 
   {
      if (n < 0) 
         throw 3;

      //bool* arr = new bool[size + n];
      BoolVector result(nullptr, size + n);
      for (size_t i = 0; i < size; ++i) {
         result[i] = elements[i];
      }
      return result;
   }

   BoolVector operator>>(size_t n) const 
   {
      if (n < 0) 
         throw 3;
      
      if (n >= size)
         return BoolVector(0);

      bool* arr = new bool[size + n];
      BoolVector result(arr, size - n);
      for (size_t i = 0; i < size - n; ++i) {
         result[i] = elements[n + i];
      }
      return result;
   }
};