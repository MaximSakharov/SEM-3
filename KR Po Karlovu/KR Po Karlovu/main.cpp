/*
#include <iostream>
#include "List.hpp"
#include "DoublyList.hpp"
#include <stack> 
#include "Stack.hpp"
#include "Queue.hpp"
#include "BinTree.hpp"


using namespace std;
*/
/*
int main()
{
   int arr[5] = { 5, 6, 1, 8, 9 };
   int arr2[5] = { 5, 6, 7, 8, 9 };

   BinTree tree1(arr, 5);

   tree1.Print(tree1.GetRoot());
*/


   /*
   Queue<int> queue;

   // Добавление элементов в очередь
   queue.enqueue(10);
   queue.enqueue(20);
   queue.enqueue(30);

   std::cout << "Front element: " << queue.peek() << std::endl; // 10
   std::cout << "Queue size: " << queue.getSize() << std::endl; // 3

   // Удаление элементов из очереди
   queue.dequeue();
   std::cout << "Front element after dequeue: " << queue.peek() << std::endl; // 20
   std::cout << "Queue size after dequeue: " << queue.getSize() << std::endl; // 2

   queue.dequeue();
   queue.dequeue();

   // Пытаемся вызвать dequeue на пустой очереди
   try {
      queue.dequeue();
   }
   catch (const std::out_of_range& e) {
      std::cout << e.what() << std::endl; // Queue is empty!
   }
   */
   /*
   Stack<int> stack;

   // Добавление элементов в стек
   stack.push(10);
   stack.push(20);
   stack.push(30);

   std::cout << "Top element: " << stack.peek() << std::endl; // 30
   std::cout << "Stack size: " << stack.getSize() << std::endl; // 3

   // Удаление элементов из стека
   stack.pop();
   std::cout << "Top element after pop: " << stack.peek() << std::endl; // 20
   std::cout << "Stack size after pop: " << stack.getSize() << std::endl; // 2

   stack.pop();
   stack.pop();

   // Пытаемся вызвать pop на пустом стеке
   try {
      stack.pop();
   }
   catch (const std::out_of_range& e) {
      std::cout << e.what() << std::endl; // Stack is empty!
   }
   */
   /*
   setlocale(LC_ALL, "rus");
   stack <int> steck;  // создаем стек

   int i = 0;

   cout << "Введите шесть любых целых чисел: " << endl; // предлагаем пользователю 
   // ввести 6 чисел
   while (i != 6) {
      int a;
      cin >> a;

      steck.push(a);  // добавляем введенные числа
      i++;
   }

   steck.pop();

   while (!steck.empty())
   {
      cout << steck.top();
      steck.pop();
   }
   */
   /*
   if (steck.empty()) cout << "Стек не пуст";  // проверяем пуст ли стек (нет)

   cout << "Верхний элемент стека: " << steck.top() << endl; // выводим верхний элемент
   cout << "Давайте удалим верхний элемент " << endl;

   steck.pop();  // удаляем верхний элемент

   cout << "А это новый верхний элемент: " << steck.top(); // выводим уже новый
   */
   // верхний элемент 
   //system("pause");

   /*
   int arr[4] = { 1, 2, 3, 4 };
   int arr2[5] = { 5, 6, 7, 8, 9 };

   
   DoublyList Dlist1(arr, 4);
   DoublyList Dlist2(arr2, 5);
   */
   /*
   Dlist1.Print();
   cout << "\n";
   Dlist2.Print();
   cout << "\n";
   
   Dlist1 = Dlist2;
   Dlist1.Print();
   cout << "\n";

   DoublyList Dlist3(Dlist1);
   Dlist3.Print();
   cout << "\n";
   */

   /*
   cin >> Dlist1;
   cout << Dlist1;
   */
   /*

   List list1(arr, 4);
   List list2(arr2, 5);
   
   cout << list1;
   cout << "\n";

   cin >> list1;

   cout << list1;
   cout << "\n";
   */

   /*
   List list3;
   cout << list3;
   */

   /*
   list1.Print();
   cout << "\n";
   list2.Print();
   cout << "\n";

   list1 = list2;

   list1.Print();
   cout << "\n";

   List list3(list2);

   list3.Print();
   cout << "\n";
   */

/*
   return 0;
}
*/