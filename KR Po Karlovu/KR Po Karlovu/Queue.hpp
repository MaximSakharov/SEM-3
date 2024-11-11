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

   Node* front; // ��������� �� ������ ������� � �������
   Node* back;  // ��������� �� ��������� ������� � �������
   size_t size; // ���������� ��������� � �������

public:
   // �����������
   Queue() : front(nullptr), back(nullptr), size(0) {}

   // ����������
   ~Queue() {
      while (!isEmpty()) {
         dequeue();
      }
   }

   // ����� ��� ��������, ����� �� �������
   bool isEmpty() const {
      return front == nullptr;
   }

   // ����� ��� ��������� ������� �������
   size_t getSize() const {
      return size;
   }

   // ����� ��� ���������� �������� � ����� �������
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

   // ����� ��� �������� �������� �� ������ �������
   void dequeue() {
      if (isEmpty()) {
         throw std::out_of_range("Queue is empty!");
      }
      Node* temp = front;
      front = front->next;
      if (front == nullptr) { // ���� ������� �����, �� ��������� � back
         back = nullptr;
      }
      delete temp;
      --size;
   }

   // ����� ��� ��������� �������� �� ������ �������
   T& peek() {
      if (isEmpty()) {
         throw std::out_of_range("Queue is empty!");
      }
      return front->data;
   }

   // ����� ��� ������ �������� �� ������ ������� (����������� ������)
   const T& peek() const {
      if (isEmpty()) {
         throw std::out_of_range("Queue is empty!");
      }
      return front->data;
   }
};