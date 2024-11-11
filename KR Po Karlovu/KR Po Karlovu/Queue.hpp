#include <iostream>
#include <stdexcept>

template <typename T>
class Queue {
private:
   struct Node {
      T data;
      Node* next;

      Node(const T& value) : data(value), next(nullptr) {}
   };

   Node* front; // указатель на первый элемент в очереди
   Node* back;  // указатель на последний элемент в очереди
   size_t size; // количество элементов в очереди

public:
   // Конструктор
   Queue() : front(nullptr), back(nullptr), size(0) {}

   // Деструктор
   ~Queue() {
      while (!isEmpty()) {
         dequeue();
      }
   }

   // Метод для проверки, пуста ли очередь
   bool isEmpty() const {
      return front == nullptr;
   }

   // Метод для получения размера очереди
   size_t getSize() const {
      return size;
   }

   // Метод для добавления элемента в конец очереди
   void enqueue(const T& value) {
      Node* newNode = new Node(value);
      if (isEmpty()) {
         front = back = newNode;
      }
      else {
         back->next = newNode;
         back = newNode;

      }
      ++size;
   }

   // Метод для удаления элемента из начала очереди
   void dequeue() {
      if (isEmpty()) {
         throw std::out_of_range("Queue is empty!");
      }
      Node* temp = front;
      front = front->next;
      if (front == nullptr) { // Если очередь пуста, то обновляем и back
         back = nullptr;
      }
      delete temp;
      --size;
   }

   // Метод для получения элемента из начала очереди
   T& peek() {
      if (isEmpty()) {
         throw std::out_of_range("Queue is empty!");
      }
      return front->data;
   }

   // Метод для чтения элемента из начала очереди (константная версия)
   const T& peek() const {
      if (isEmpty()) {
         throw std::out_of_range("Queue is empty!");
      }
      return front->data;
   }
};