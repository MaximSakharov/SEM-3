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

   Node* top; // ��������� �� ������� �����
   size_t size; // ���������� ��������� � �����

public:
   // �����������
   Stack() : top(nullptr), size(0) {}

   // ����������
   ~Stack() {
      while (!isEmpty()) {
         pop();
      }
   }

   // ����� ��� ��������, ���� �� ����
   bool isEmpty() const {
      return top == nullptr;
   }

   // ����� ��� ��������� ������� �����
   size_t getSize() const {
      return size;
   }

   // ����� ��� ���������� �������� � ����
   void push(const T& value) {
      Node* newNode = new Node(value);
      newNode->next = top;
      top = newNode;
      ++size;
   }

   // ����� ��� �������� �������� � ������� �����
   void pop() {
      if (isEmpty()) {
         throw std::out_of_range("Stack is empty!");
      }
      Node* temp = top;
      top = top->next;
      delete temp;
      --size;
   }

   // ����� ��� ��������� �������� � ������� �����
   T& peek() {
      if (isEmpty()) {
         throw std::out_of_range("Stack is empty!");
      }
      return top->data;
   }

   // ����� ��� ������ �������� � ������� ����� (����������� ������)
   const T& peek() const {
      if (isEmpty()) {
         throw std::out_of_range("Stack is empty!");
      }
      return top->data;
   }
};