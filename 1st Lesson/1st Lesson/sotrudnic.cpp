#pragma warning (disable: 4996)
#include "sotrudnic.hpp" 
#include <iostream>
#include <string.h>
#include <stdlib.h>

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

float EmployersMore25(Sotrudnik* arr_, int size_, int& k, char** full_name_25, const char date_[11])
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