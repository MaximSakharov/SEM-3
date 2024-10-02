//#include "sotrudnic.hpp" 
#pragma warning (disable: 4996)

#include <iostream>
#include <string.h>
#include <stdlib.h>

class Base {
private:
   int size;
   Sotrudnik* employers;
   static int count;
public:
   Base();
   Base(int n);
   ~Base();
   int Get_Size() { return size; };
   void Create_Base(const char* namefile);
   void Print_Base();
   void Insert_In_Base(Sotrudnik& new_emp);
   void Delete_Data(char* name_);
   void Data_Correction(char* name_);
   int Copy_Base(const char* filename);
   void Base_Expansion();
};

void Work_Base(Base& base);