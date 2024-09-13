#pragma warning (disable: 4996)
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
	private:
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
		void Insert()
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
int Create_f(const char* namefile, int& k, Sotrudnik* arr_)
{
	FILE* fp;
	fopen_s(&fp, namefile, "r");

	if (!fp)
		return -1;

	char FIO[31];
	char inc[5];
	int io;
	float oklad;
	char dat[11];

	while (fscanf(fp, "%s %s %d %f %s", FIO, inc, &io, &oklad, dat) == 5)
	{
		strcat(FIO, " ");
		strcat(FIO, inc);
		arr_[k].SetYear(io);
		arr_[k].SetName(FIO);
		arr_[k].SetSal(oklad);
		arr_[k].SetData(dat);

		++k;
	}

	fclose(fp);

	return 0;
}

bool ParseDate(const char* dateStr, int& day, int& month, int& year)
{
	if (std::strlen(dateStr) != 10 || dateStr[2] != '.' || dateStr[5] != '.')
		return false;

	day = (dateStr[0] - '0') * 10 + (dateStr[1] - '0');
	month = (dateStr[3] - '0') * 10 + (dateStr[4] - '0');
	year = (dateStr[6] - '0') * 1000 + (dateStr[7] - '0') * 100 +
		(dateStr[8] - '0') * 10 + (dateStr[9] - '0');

	return true;
}

bool Compare_Dates(const char date1[], const char date2[])
{
	int day1, month1, year1;
	int day2, month2, year2;

	if (!ParseDate(date1, day1, month1, year1) || !ParseDate(date2, day2, month2, year2))
		return false;

	if (year2 - year1 > 25)
		return true;
	else if (year2 - year1 == 25)
	{ 
		if (month2 - month1 > 0)
			return true;
		else if (month2 < month1)
			return false;

		return day2 > day1;
	}

	return false;
}

float EmployersMore25(Sotrudnik* arr_, int size_, int &k, char** full_name_25, const char date_[11])
{
	float average_salary = 0;

	for (int i = 0; i < size_; ++i)
		if (Compare_Dates(arr_[i].GetData(), date_))
		{
			full_name_25[k] = arr_[i].GetName();
			++k;
			average_salary += arr_[i].GetSal();
		}

	if (k != 0)
		average_salary /= k;

	return average_salary;
}

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