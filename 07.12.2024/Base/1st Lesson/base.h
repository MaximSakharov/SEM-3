//#include "sotrudnic.hpp" 
#pragma warning (disable: 4996)

using namespace std;

#include <iostream>
#include <fstream>
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

   void Insert_Element_Base(Sotrudnik& new_emp);


   inline friend ostream& operator<<(ostream& stream, const Base& base);
   inline friend istream& operator>>(istream& stream, Base& base);

   friend fstream& operator>>(fstream& file, Base& base) 
   {
      if (base.employers)
         delete[] base.employers;

      file >> base.size;

      base.employers = new Sotrudnik[base.size];
      Sotrudnik emp;

      for (int i = 0; i < base.size; ++i) 
      {
         file >> emp;
         base.Insert_Element_Base(emp);
      }

      return file;
   }
   friend fstream& operator<<(fstream& file, const Base& base)
   {
       for (int i = 0; i < base.size; ++i) {
           file << base.employers[i].GetName() << " " << base.employers[i].GetYear() << " " << base.employers[i].GetSal() << " " << base.employers[i].GetData() << endl;
       }
       return file;
   }
};

inline ostream& operator<<(ostream& stream, const Base& base)
{
   stream << "Employee Database:\n";
   stream << "----------------------------------------\n";
   for (int i = 0; i < base.size; ++i) {
      base.employers[i].Print();
   }
   return stream;
}

inline istream& operator>>(istream& stream, Base& base)
{
   //cout << "Enter the number of employees: ";
   stream >> base.size;

   delete[] base.employers;
   base.employers = new Sotrudnik[base.size];

   Sotrudnik emp;

   for (int i = 0; i < base.size; ++i)
   {
      emp.Insert();
      base.Insert_Element_Base(emp);
   }

   return stream;
}

void Work_Base(Base& base);