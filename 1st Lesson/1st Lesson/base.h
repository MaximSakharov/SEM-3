//#include "sotrudnic.hpp" 
#pragma warning (disable: 4996)

#include <iostream>
#include <string.h>
#include <stdlib.h>

class Base {
private:
   int size;
   Sotrudnik* employers;
   int count;
public:
   Base();
   Base(int n);
   ~Base();
   Base(const Base& base_);
   Base& operator = (Base& base_);
   Sotrudnik& operator[](int index_);
   int Get_Size() { return size; };
   int Create_Base(const char* namefile);
   void Print_Base();
   void Insert_In_Base(Sotrudnik& new_emp);
   int Delete_Data(char* name_);
   int Data_Correction(char* name_);
   int Copy_Base(const char* filename);
   void Base_Expansion();

};

void Work_Base(Base& base);