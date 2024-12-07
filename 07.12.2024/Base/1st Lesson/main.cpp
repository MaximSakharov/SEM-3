#pragma warning (disable: 4996)
#include "sotrudnic.hpp" 
#include "base.h"

#include <iostream>
#include <fstream>
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

   Base base;

	fstream file1("employers.txt");
	fstream file2("test.txt");
	if (!file1.is_open() || !file2.is_open())
	{
		std::cerr << "Не удалось открыть файл!" << std::endl;
		return 1;
	}

	file1 >> base;
	file2 << base;

	//cout << base;

	//cin >> base;
	//cout << base;

	/*
   Sotrudnik emp;
   cin >> emp;
   cout << emp;
	*/

	//Work_Base(base);

   return 0;
}

