#include <iostream>

using namespace std;

class BoolVector
{
private:
   bool* elements;
   size_t size;
   size_t capacity;
public:
   class Iterator 
   {
   private:
      bool* current; // Указатель на текущий элемент
   public:
      Iterator(bool* ptr) : current(ptr) {}

      // Операторы разыменования
      bool& operator*() 
      {
         return *current;
      }

      const bool& operator*() const 
      {
         return *current;
      }

      // Оператор инкремента
      Iterator& operator++() 
      {
         ++current;
         return *this;
      }

      // Оператор сравнения
      bool operator!=(const Iterator& other) const 
      {
         return current != other.current;
      }
   };

   BoolVector(size_t capacity_= 0)
      :capacity(capacity), size(0), elements(capacity ? new bool[capacity] : nullptr) {}

   ~BoolVector()
   {
      if (elements)
         delete[] elements;
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

   bool& operator[](size_t i) const
   {
      if (i >= size)
         throw 1;

      return elements[i];
   }
   bool& operator[](size_t i)
   {
      if (i >= size)
         throw 1;

      return elements[i];
   }
   bool At(size_t pos_)
   {
      if (pos_ >= size)
         throw 1;

      return elements[pos_];
   }
   bool Front()
   {
      if (size == 0)
         throw 1;

      return elements[0];
   }
   bool Back()
   {
      if (size == 0)
         throw 1;

      return elements[size - 1];
   }
   void SetElement(size_t pos_, bool new_element_)
   {
      if (pos_ >= size)
         throw 1;

      elements[pos_] = new_element_;
   }

   void PushBack(bool element_)
   {
      if (size < capacity)
      {
         elements[size++] = element_;
         return;
      }
      if (capacity == 0)
      {
         elements = new bool;
         capacity = size = 1;
         elements[0] = element_;
      }
      else
      {
         bool* new_elements = new bool[capacity *= 2];
         if (!new_elements)
            return;

         for (size_t i = 0; i < size; ++i)
            new_elements[i] = elements[i];

         delete[] elements;
         elements = new_elements;

         elements[size++] = element_;
      }
   }
   void PopBack()
   {
      if (size == 0)
         return;

      --size;
   }
   void Insert(size_t pos_, bool element_)
   {
      if (pos_ > size - 1)
         throw 1;

      elements[pos_] = element_;
   }

   BoolVector OrOperation(const BoolVector& other_) const
   {
      if (size != other_.size)
         throw 2;

      BoolVector result(size);
      result.size = size;

      for (size_t i = 0; i < size; ++i)
      {
         result[i] = (elements[i] || other_.elements[i]);
      }

      return result;
   }
   BoolVector AndOperation(const BoolVector& other_) const
   {
      if (size != other_.size)
         throw 2;

      BoolVector result(size);
      result.size = size;

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

   bool operator==(const BoolVector& other_) const
   {
      if (size != other_.size)
         return false;

      for (size_t i = 0; i < size; ++i)
         if (elements[i] != other_[i])
            return false;

      return true;
   }
   bool operator!=(const BoolVector& other_) const
   {
      return !(*this == other_);
   }

   BoolVector operator!() const
   {
      BoolVector result(size);

      for (size_t i = 0; i < size; ++i)
         result[i] = !elements[i];

      return result;
   }
   void Print()
   {
      cout << "< ";
      for (size_t i = 0; i < size - 1; ++i)
         cout << elements[i] << ", ";

      cout << elements[size - 1];

      cout << " >";
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
   BoolVector Concatenate(const BoolVector& other_) const
   {
      //bool *arr = new bool[size + other_.size];

      BoolVector result(size + other_.size);

      for (size_t i = 0; i < size; ++i)
         result.elements[i] = elements[i];
      for (size_t i = 0; i < other_.size; ++i)
         result.elements[i + size] = other_.elements[i];

      return result;
   }
   BoolVector ShiftLeftOperation(size_t n) const
   {
      if (n < 0)
         throw 3;

      BoolVector result(size + n);
      for (size_t i = 0; i < size; ++i) {
         result[i] = elements[i];
      }

      return result;
   }

   BoolVector ShiftRightOperation(size_t n) const
   {
      if (n < 0) 
         throw 3;
      
      if (n >= size)
         return BoolVector(0);

      bool* arr = new bool[size + n];
      BoolVector result(size - n);

      for (size_t i = 0; i < size - n; ++i)
         result[i] = elements[n + i];

      return result;
   }

   // Метод для получения итератора на первый элемент
   Iterator Begin() 
   {
      return Iterator(elements);
   }

   // Метод для получения итератора на элемент после последнего
   Iterator End() 
   {
      return Iterator(elements + size);
   }

   friend ostream& operator<<(ostream& stream, const BoolVector& vector_);
   friend istream& operator>>(istream& stream, BoolVector& vector_);

};

ostream& operator<<(ostream& stream, const BoolVector& vector_)
{
   stream << "< ";

   size_t vector_size = vector_.size - 1;

   for (size_t i = 0; i < vector_size; ++i)
      stream << vector_[i] << ", ";
   
   stream << vector_[vector_size];

   stream << " >";

   return stream;
}

istream& operator>>(std::istream& stream, BoolVector& vector_) 
{
   if (vector_.elements)
   {
      delete[] vector_.elements;
      vector_.size = 0;
      vector_.elements = new bool[vector_.capacity];
   }

   char ch;
   bool a;

   // Ожидаем символ '<'
   stream >> ch;
   if (ch != '<') 
   {
      throw 4;
   }

   // Читаем элементы до символа '>'
   while (stream >> a) 
   {
      vector_.PushBack(a);

      // Ожидаем либо '>' либо ',' чтобы продолжить
      stream >> ch;
      if (ch == '>') 
      {
         break; // Выходим из цикла, если встретили '>'
      }
      else if (ch != ',') 
      {
         throw 4;
      }
   }

   return stream;
}
