#include <iostream>
#include <stdexcept>

template <typename T>
class Stack {
private:
   struct Node {
      T data;
      Node* next;

      Node(const T& value) : data(value), next(nullptr) {}
   };

   Node* top; // указатель на вершину стека
   size_t size; // количество элементов в стеке

public:
   // Конструктор
   Stack() : top(nullptr), size(0) {}

   // Деструктор
   ~Stack() {
      while (!isEmpty()) {
         pop();
      }
   }

   // Метод для проверки, пуст ли стек
   bool isEmpty() const {
      return top == nullptr;
   }

   // Метод для получения размера стека
   size_t getSize() const {
      return size;
   }

   // Метод для добавления элемента в стек
   void push(const T& value) {
      Node* newNode = new Node(value);
      newNode->next = top;
      top = newNode;
      ++size;
   }

   // Метод для удаления элемента с вершины стека
   void pop() {
      if (isEmpty()) {
         throw std::out_of_range("Stack is empty!");
      }
      Node* temp = top;
      top = top->next;
      delete temp;
      --size;
   }

   // Метод для получения элемента с вершины стека
   T& peek() {
      if (isEmpty()) {
         throw std::out_of_range("Stack is empty!");
      }
      return top->data;
   }

   // Метод для чтения элемента с вершины стека (константная версия)
   const T& peek() const {
      if (isEmpty()) {
         throw std::out_of_range("Stack is empty!");
      }
      return top->data;
   }
};