#pragma warning (disable: 4996)
#include "sotrudnic.hpp" 

#include <iostream>
#include <string.h>
#include <stdlib.h>

#include "functions.hpp"

using namespace std;

/*
class <Name>
{
	[private:]
		<Описание скрытых элементов>
	public:
		<Описание доступных элементов>
};
*/

/*
int main()
{
	setlocale(LC_ALL, "RU");

	Sotrudnik arr[100];
	char** full_name = new char*[100];

	int size = 0;
	int k = 0;
	float salary = 0;

	Create_f("employers.txt", size, arr);
	salary = EmployersMore25(arr, size, k, full_name, "13.09.2024");

	printf("Average salary = %f\n", salary);

	for (int i = 0; i < k; ++i)
		printf("%s\n", full_name[i]);

	return 0;
}
*/

int main()
{
   setlocale(LC_ALL, "RU");

   Base base(100);
   

   int variant = 0;
   char* filename_in = new char [100];
   char* inic_in = new char[100];
   char* name_in = new char[100];

   const char* filename = "employers.txt";

   while (variant != 7)
   {
      Print_Menu();

      variant = get_variant(7);

      switch (variant)
      {
      case 1:
         //printf("Insert file name: ");
         //scanf("%s", filename_in);
         base.Create_Base(filename);
         break;
      case 2:
         base.Print_Base();
         break;
      case 3:
         base.Insert_In_Base();
         break;
      case 4:
         printf("Insert emplayers name: ");
         scanf("%s", name_in);
         base.Delete_Data(name_in);
         break;
      case 5:
         printf("Insert emplayers name: ");
         scanf("%s", name_in);
         printf("Insert emplayers name: ");
         scanf("%s", inic_in);
         strcat(name_in, " ");
         strcat(name_in, inic_in);
         base.Data_Correction(name_in);
         break;
      case 6:
         base.Copy_Base();
         break;
      }
      if (variant != 7)
         system("pause");
   }

   return 0;
}

