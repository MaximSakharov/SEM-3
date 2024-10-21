#include <iostream>
#include <stdlib.h>

using namespace std;

class Vector
{
private:
   double* elements;
   size_t size;  // текущее
   size_t capacity;
public:

   Vector(double* elems_ = nullptr, size_t capacity_ = 0)
      : size(0), capacity(capacity_), elements(nullptr) // Member initializer list
   {
      if (capacity_ > 0 && elems_ != nullptr) {
         elements = new double[capacity_];
         size = capacity_; // Set the size to the number of elements copied
         for (size_t i = 0; i < size; ++i) {
            elements[i] = elems_[i];
         }
      }
   }
   /*
   Vector() : elements(nullptr), size(0) {}
   
   Vector(size_t size_): size(size_)
   {
      elements = new double[size_];
      if (size_ != 0)
      {
         for (int i = 0; i < size_; ++i)
            elements[i] = 0.0;
      }
   }
   
   
   Vector(size_t size_, double* elems_) : size(size_)
   {
      elements = new double[size_];
      if (size_ != 0)
      {
         for (int i = 0; i < size_; ++i)
            elements[i] = elems_[i];
      }
   }
   */
   ~Vector()
   {
      if (elements)
         delete[] elements;
   }

   Vector(const Vector& other_) : size(other_.size), capacity(other_.capacity)
   {
      elements = new double[size];
      for (size_t i = 0; i < size; ++i)
         elements[i] = other_.elements[i];
   }

   Vector& operator=(const Vector& other_)
   {
      if (this != &other_) 
      {
         delete[] elements;
         size = other_.size;
         capacity = other_.capacity ;

         elements = new double[size];
         for (size_t i = 0; i < size; ++i)
            elements[i] = other_.elements[i];
      }
      return *this;
   }

   void Print()
   {
      cout << "( ";
      for (size_t i = 0; i < size; ++i)
      {
         cout << elements[i];
         if (i + 1 < size)
            cout << ", ";
      }
      cout << " )" << endl;
   }

   void PushBack(double element_)
   {
      if (size < capacity)
      {
         elements[size++] = element_;
         return;
      }
      if (capacity == 0)
      {
         elements = new double;
         capacity = size = 1;
         elements[0] = element_;
      }
      else
      {
         double* new_elements = new double[capacity *= 2];
         if (!new_elements)
            return;

         for (size_t i = 0; i < size; ++i)
            new_elements[i] = elements[i];

         delete[] elements;
         elements = new_elements;

         elements[size++] = element_;
      }
   }

   double& operator[](size_t index_)
   {
      if (index_ >= size)
         exit(1);

      return elements[index_];
   }

   Vector operator+(const Vector& other_) const 
   {
      if (size != other_.size)
         return Vector();

      Vector result;
      result.elements = new double[size];
      result.size = size;
      result.capacity = size;

      for (size_t i = 0; i < size; ++i)
         result.elements[i] = elements[i] + other_.elements[i];

      return result;
      /*
      if (size != other_.size) 
      {
         return Vector();
      }

      Vector result(size);

      for (size_t i = 0; i < size; ++i) 
      {
         result.elements[i] = elements[i] + other_.elements[i];
      }

      return result;
      */
   }
   Vector operator-(const Vector& other_) const
   {
      if (size != other_.size)
         return Vector();

      Vector result;
      result.elements = new double[size];
      result.size = size;
      result.capacity = size;

      for (size_t i = 0; i < size; ++i)
         result.elements[i] = elements[i] - other_.elements[i];

      return result;
      /*
      if (size != other_.size)
      {
         return Vector();
      }

      Vector result(size);

      for (size_t i = 0; i < size; ++i)
      {
         result.elements[i] = elements[i] + other_.elements[i];
      }

      return result;
      */
   }

   Vector& operator+=(const Vector& other_)
   {
      if (size != other_.size)
      {
         *this = Vector();
         return *this;
      }

      for (size_t i = 0; i < size; ++i)
         elements[i] += other_.elements[i];

      return *this;
   }

   Vector& operator-=(const Vector& other_)
   {
      if (size != other_.size)
      {
         *this = Vector();
         return *this;
      }

      for (size_t i = 0; i < size; ++i)
         elements[i] -= other_.elements[i];

      return *this;
   }

   Vector operator&(const Vector& other_) const
   {
      double* arr = new double[size + other_.size];

      Vector result(arr, size + other_.size);
      for (size_t i = 0; i < size; ++i)
         result.elements[i] = elements[i];
      for (size_t i = 0; i < other_.size; ++i)
         result.elements[i + size] = other_.elements[i];

      return result;
   }

   Vector& operator&=(const Vector& other_)
   {
      double* arr = new double[size];

      for (size_t i = 0; i < size; ++i)
         arr[i] = elements[i];

      delete[] elements;
      elements = new double[size + other_.size];
      
      for (size_t i = 0; i < size; ++i)
         elements[i] = arr[i];
      
      for (size_t i = 0; i < other_.size; ++i)
         elements[i + size] = other_.elements[i];

      size += other_.size;
      capacity = size;

      return *this;
   }

   bool operator==(const Vector& other_) const
   {
      if (size != other_.size)
         return false;

      for (size_t i = 0; i < size; ++i)
         if (elements[i] != other_.elements[i])
            return false;

      return true;
   }

   bool operator!=(const Vector& other_) const
   {
      return !(*this == other_);
   }

   bool operator!() const 
   {
      for (size_t i = 0; i < size; ++i) 
         if (elements[i] != 0) 
            return false; 

      return true;
   }

   double operator*(const Vector& other) const 
   {
      if (size != other.size) 
      {
         return 0;
      }

      double result = 0;
      for (size_t i = 0; i < size; ++i) {
         result += elements[i] * other.elements[i];
      }
      return result;
   }

   /*
   Vector concatenate(const Vector& other_) const
   {
      Vector result(size + other_.size);
      for (size_t i = 0; i < size; ++i)
         result.elements[i] = elements[i];
      for (size_t i = 0; i < other_.size; ++i)
         result.elements[i + size] = other_.elements[i];

      return result;
   }
   */
};