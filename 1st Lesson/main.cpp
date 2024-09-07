#include <iostream>
#include <string.h>
#include <stdlib.h>
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


class Sotrudnik
{
	[private:]
			char* name;		//Фамилия и инициалы
			int year;
			float sal;
			char data[11];
	public:
		Sotrudnik()
		{
			name = new char[31];
			year = 0;
			sal = 0.0;
			data[0] = '\0';
		}
		Sotrudnik(int n)
		{
			name = new char[n];
			year = 0;
			sal = 0.0;
			data[0] = '\0';
		}
		~Sotrudnik()
		{
			if (name != NULL)
				delete[] name;
		}
		void SetName(char* s)
		{
			strcpy(name, s);

		}
		void SetYear(int year1)
		{
			year = year1;
		}
		void SetSal(float sal1)
		{
			sal = sal1;
		}
		void SetData(char* s)
		{
			strcpy(data, s);
		}

		char* GetName()
		{
			return name;
		}
		int GetYear()
		{
			return year;
		}
		float GetSal()
		{
			return sal;
		}
		char* GetData()
		{
			return data;
		}

		void Print()
		{
			printf("%s %d %f %s\n", name, year, sal, data);
		}
		void Vvod()
		{
			char inic[5];
			scanf("%s %s %d %f %s", name, inic, &year, &sal, data);
			strcat(name, " ");
			strcat(name, inic);
		}
		bool Sif(char* s)
		{
			if (strcmp(name, s) == NULL)
				return true;
			else
				return false;
		};
};

// k - реальная размерность массива
int Create_f(char* namefile, int& k, Sotrudnik* arr_)
{
	FILE* fp;
	fopen_s(&fp, "namefile", "r");

	if (!fp)
		return -1;

	char FIO[30];
	char inc[5];
	int io;
	float oklad;
	char dat[11];

	while (fscanf_s(fp, "%s %s %d %f %s", FIO, inc, &io, &oklad, dat) == 5)
	{
		strcat(FIO, " ");
		strcat(FIO, inc);
		arr_[k].SetYear(io);
		arr_[k].SetName(FIO);
		arr_[k].SetSal(oklad);
		arr_[k].SetData(dat);
	}
}