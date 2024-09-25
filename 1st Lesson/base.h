//#include "sotrudnic.hpp" 

#include <iostream>
#include <string.h>
#include <stdlib.h>

class Base {
private:
   int size;
   Sotrudnik* employers;
public:
   static int count; // Объявление статической переменной
   Base();
   Base(int n);
   ~Base();
   int Get_Size() { return size; };
   void Create_Base(const char* namefile);
   void Print_Base();
   void Insert_In_Base();
   void Delete_Data();
   void Data_Correction();
   int Copy_Base(const char* filename);
   void Base_Expansion();
};

void Work_Base(Base& base);