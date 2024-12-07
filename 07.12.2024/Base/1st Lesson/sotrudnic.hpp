#pragma warning (disable: 4996)
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <fstream>

using namespace std;

class Sotrudnik
{
private:
	char* name;		//Фамилия и инициалы
	int year;
	float sal;
	char data[11];
public:
	Sotrudnik();

	Sotrudnik(int n);

	~Sotrudnik();

	Sotrudnik(const Sotrudnik& emp);

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

	Sotrudnik& operator = (Sotrudnik& emp)
	{
		if (&emp == this) return *this;
		if (name)
			delete[] name;

		if (emp.name)
		{
			name = new char[strlen(emp.name) + 1];
			strcpy(name, emp.name);
		}
		else
			name = (char*)'\0';
		year = emp.year;
		sal = emp.sal;
		strcpy(data, emp.data);

		return *this;
	}

	void Insert();

	bool Sif(char* s);

	inline friend ostream& operator<<(ostream& stream, const Sotrudnik& emp_);

	inline friend istream& operator>>(istream& stream, Sotrudnik& emp_);

	inline friend ifstream& operator>>(ifstream& file, Sotrudnik& emp_)
	{
		char inic[5];  // Для инициалов
		file >> emp_.name >> inic >> emp_.year >> emp_.sal >> emp_.data;

		// Объединение фамилии и инициалов в одно поле name
		strcat(emp_.name, " ");
		strcat(emp_.name, inic);

		return file;
	}
};

inline ostream& operator<<(ostream& stream, const Sotrudnik& emp_)
{
	stream << emp_.name << " " << emp_.year << " " << emp_.sal << " " << emp_.data;

	return stream;
}

inline istream& operator>>(istream& stream, Sotrudnik& emp_)
{
	char inic[5];
	stream >> emp_.name >> inic >> emp_.year >> emp_.sal >> emp_.data;
	strcat(emp_.name, " ");
	strcat(emp_.name, inic);

	return stream;
}

int Create_f(const char* namefile, int& k, Sotrudnik* arr_);

bool ParseDate(const char* dateStr, int& day, int& month, int& year);

bool Compare_Dates(const char date1[], const char date2[]);

float EmployersMore25(Sotrudnik* arr_, int size_, int& k, char** full_name_25, const char date_[11]);