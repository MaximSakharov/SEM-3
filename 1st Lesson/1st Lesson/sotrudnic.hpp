#pragma warning (disable: 4996)
#include <iostream>
#include <string.h>
#include <stdlib.h>

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
		printf("%-20s %-10d %-10.2f %-20s\n", name, year, sal, data);
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
	}
};

int Create_f(const char* namefile, int& k, Sotrudnik* arr_);

bool ParseDate(const char* dateStr, int& day, int& month, int& year);

bool Compare_Dates(const char date1[], const char date2[]);

float EmployersMore25(Sotrudnik* arr_, int size_, int& k, char** full_name_25, const char date_[11]);