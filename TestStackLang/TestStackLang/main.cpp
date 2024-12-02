#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <algorithm>
#include <unordered_map>

class StackMachine {
private:
   std::vector<int> stack;
   std::vector<std::string> program;
   size_t pc; // program counter
   std::unordered_map<std::string, int> variables; // �������� ����������

public:
   StackMachine(const std::vector<std::string>& prog) : program(prog), pc(0) {}

   void run() {
      while (pc < program.size()) {
         std::string command = program[pc];
         pc++;

         if (command.substr(0, 5) == "push ") {
            std::string valueStr = command.substr(5);
            if (valueStr.empty() || (!std::all_of(valueStr.begin(), valueStr.end(), ::isdigit) && variables.find(valueStr) == variables.end())) {
               throw std::runtime_error("Invalid argument for push: " + valueStr);
            }
            int value;
            if (std::all_of(valueStr.begin(), valueStr.end(), ::isdigit)) {
               value = std::stoi(valueStr);
            }
            else {
               value = variables[valueStr]; // ���������� �������� ����������
            }
            push(value);
         }
         else if (command.substr(0, 4) == "pop ") {
            std::string var = command.substr(4);
            pop(var);
         }
         else if (command == "+") {
            arithmeticOperation(add);
         }
         else if (command == "-") {
            arithmeticOperation(subtract);
         }
         else if (command == "*") {
            arithmeticOperation(multiply);
         }
         else if (command == "/") {
            arithmeticOperation(divide);
         }
         else if (command == "%") {
            arithmeticOperation(modulus);
         }
         else if (command == "read") {
            read();
         }
         else if (command == "write") {
            write();
         }
         else if (command.substr(0, 4) == "jmp ") {
            int target = std::stoi(command.substr(4));
            jump(target);
         }
         else if (command.substr(0, 3) == "ji ") {
            int target = std::stoi(command.substr(3));
            jumpIfNotZero(target);
         }
         else if (command == "end") {
            break;
         }
         else {
            throw std::runtime_error("Unknown command: " + command);
         }
      }
   }

private:
   void push(int value) {
      stack.push_back(value);
   }

   void pop(const std::string& var) {
      if (stack.empty()) {
         throw std::runtime_error("Stack underflow on pop");
      }
      int value = stack.back();
      stack.pop_back();
      variables[var] = value; // ��������� �������� � ����������
      std::cout << "Popped value into " << var << ": " << value << std::endl;
   }

   void arithmeticOperation(int (*operation)(int, int)) {
      if (stack.size() < 2) {
         throw std::runtime_error("Not enough elements for arithmetic operation");
      }
      int b = stack.back(); stack.pop_back();
      int a = stack.back(); stack.pop_back();
      stack.push_back(operation(a, b));
   }

   static int add(int a, int b) { return a + b; }
   static int subtract(int a, int b) { return a - b; }
   static int multiply(int a, int b) { return a * b; }
   static int divide(int a, int b) {
      if (b == 0) {
         throw std::runtime_error("Division by zero");
      }
      return a / b;
   }
   static int modulus(int a, int b) {
      if (b == 0) {
         throw std::runtime_error("Division by zero in modulus");
      }
      return a % b;
   }

   void read() {
      int value;
      std::cout << "Enter a natural number: ";
      std::cin >> value;
      if (value <= 0) {
         throw std::runtime_error("Only natural numbers are allowed");
      }
      push(value);
   }

   void write() {
      if (stack.empty()) {
         throw std::runtime_error("Stack underflow on write");
      }
      int value = stack.back();
      stack.pop_back();
      std::cout << "Output: " << value << std::endl;
   }

   void jump(int target) {
      if (target < 0 || target >= program.size()) {
         throw std::runtime_error("Jump target out of bounds: " + std::to_string(target));
      }
      pc = target; // ������������� pc �� ������� ������
   }

   void jumpIfNotZero(int target) {
      if (stack.empty()) {
         throw std::runtime_error("Stack underflow on jump if not zero");
      }
      int value = stack.back();
      if (value != 0) {
         jump(target); // �������, ���� ������� ������� �� ����� ����
      }
      else {
         std::cout << "Jump skipped because top of the stack is zero." << std::endl;
      }
   }
};

int main() {
   std::vector<std::string> program = {
       "push 2",     // ����� 2 �� ����
       "push 3",     // ����� 3 �� ����
       "+",          // 2 + 3
       "write",      // �������� ���������
       "push 10",    // ����� 10 �� ����
       "push 4",     // ����� 4 �� ����
       "-",          // 10 - 4
       "write",      // �������� ���������
       "push 6",     // ����� 6 �� ����
       "push 7",     // ����� 7 �� ����
       "*",          // 6 * 7
       "write",      // �������� ���������
       "push 20",    // ����� 20 �� ����
       "push 5",     // ����� 5 �� ����
       "/",          // 20 / 5
       "write",      // �������� ���������
       "push 10",    // ����� 10 �� ����
       "push 3",     // ����� 3 �� ����
       "%",          // 10 % 3
       "write",      // �������� ���������
       "end"         // ���������� ���������
   };

   StackMachine machine(program);
   try {
      machine.run();
   }
   catch (const std::exception& e) {
      std::cerr << "Error: " << e.what() << std::endl;
   }

   return 0;
}
