#include <iostream>

using namespace std;

class Vector
{
private:
   double* elements;
   size_t size;
public:
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
   ~Vector()
   {
      if (elements)
         delete[] elements;
   }

   Vector(const Vector& other_) : size(other_.size)
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

   Vector operator+(const Vector& other_) const 
   {
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
   }
   Vector operator-(const Vector& other_) const
   {
      if (size != other_.size)
      {
         return Vector();
      }

      Vector result(size);

      for (size_t i = 0; i < size; ++i)
      {
         result.elements[i] = elements[i] - other_.elements[i];
      }

      return result;
   }

   Vector concatenate(const Vector& other_) const
   {
      Vector result(size + other_.size);
      for (size_t i = 0; i < size; ++i)
         result.elements[i] = elements[i];
      for (size_t i = 0; i < other_.size; ++i)
         result.elements[i + size] = other_.elements[i];

      return result;
   }
};