#pragma warning (disable: 4996)

#include <iostream>
#include <string.h>
#include <stdlib.h>

#include "sotrudnic.hpp" 
#include "base.h"
#include "functions.hpp"

int Base::count = 0;

Base::Base()
{
	size = 0;
	employers = new Sotrudnik[size];
	for (int i = 0; i < size; ++i)
		employers[i];
	
}

Base::Base(int n)
{
	size = n;
	employers = new Sotrudnik[size];
	for (int i = 0; i < size; ++i)
		employers[i];
}
Base::~Base()
{
	if (employers)
		delete[] employers;
}
void Base::Create_Base(const char* namefile)
{
	FILE* fp;
	fopen_s(&fp, namefile, "r");

	if (!fp)
		return;

	char FIO[31];
	char inc[5];
	int io;
	float oklad;
	char dat[11];

	while (fscanf(fp, "%s %s %d %f %s", FIO, inc, &io, &oklad, dat) == 5)
	{
		strcat(FIO, " ");
		strcat(FIO, inc);
		employers[count].SetYear(io);
		employers[count].SetName(FIO);
		employers[count].SetSal(oklad);
		employers[count].SetData(dat);

		++count;
	}

	fclose(fp);
}
void Base::Print_Base()
{
	printf("%-20s %-10s %-10s %-20s\n", "Name", "Year", "Salary", "Data");
	for (int i = 0; i < count; ++i)
		employers[i].Print();
}
void Base::Insert_In_Base(Sotrudnik& new_emp)
{
	if (count == 0) {
		employers = new Sotrudnik[1];
		count = 1;
		employers[0].Insert();
		return;
	}

	int pos = 0;
	int flag = 0;

	Sotrudnik* new_emps = new Sotrudnik[count + 1];

	for (size_t i = 0; i < count; i++)
	{
		if (flag == 0 && strcmp(employers[i].GetName(), new_emp.GetName()) > 0)
		{
			if (flag == 0)
				pos = (int)i;
			flag = 1;
			new_emps[i + flag] = employers[i];
		}
		else
			new_emps[i + flag] = employers[i];
	}

	new_emps[pos] = new_emp;

	employers = new_emps;
	++count;
	size = count;

	/*
	if (count < size) {
		employers[count].Insert(); 
	}
	else {
		this->Base_Expansion(); 
		employers[count].Insert(); 
	}

	++count; 
	*/
}
void Base::Delete_Data(char* name_)
{
	int k = 0;

	while (k < size && strcmp(name_, employers[k].GetName()) != 0)
	{
		++k;
	}

	if (k < size) { 
		for (int j = k; j < count - 1; ++j)
		{
			employers[j] = employers[j + 1];
		}
		--count;
	}

	printf("Employee succefully delete.\n");
}
void Base::Data_Correction(char* name_)
{
	char new_name[31];
	char new_inic[5];
	int new_year = 0;
	float new_salary = 0.0f;
	char new_date[11];

	int k = 0;

	while (k < size && strcmp(name_, employers[k].GetName()) != 0) 
	{
		++k;
	}

	if (k < size) 
	{ 
		printf("Insert new data: ");
		while (scanf("%s %s %d %f %s", new_name, new_inic, &new_year, &new_salary, new_date) != 5);

		strcat(new_name, " ");
		strcat(new_name, new_inic);

		employers[k].SetName(new_name);
		employers[k].SetYear(new_year);
		employers[k].SetSal(new_salary);
		employers[k].SetData(new_date);
	}
	else {
		printf("Сотрудник не найден.\n");
	}
}
int Base::Copy_Base(const char* filename_)
{
	if (!filename_)
		return -1;

	FILE* fp;
	fopen_s(&fp, filename_, "w");
	if (!fp)
		return -2;

	for (int i = 0; i < count; ++i)
		fprintf_s(fp, "%s %d %f %s\n", employers[i].GetName(), employers[i].GetYear(), employers[i].GetSal(), employers[i].GetData());

	printf("File was filled.\n");

	fclose(fp);

	return 0;
}

void Base::Base_Expansion()
{
	int newSize = this->Get_Size() + 50; 
	Sotrudnik* newEmployers = new Sotrudnik[newSize]; 


	for (int i = 0; i < this->Get_Size(); ++i) 
		newEmployers[i] = this->employers[i]; 

	this->employers = newEmployers;
	this->size = newSize;
}

void Work_Base(Base& base)
{
	int variant = 0;
	char* filename_in = new char[100];
	char* name;
	Sotrudnik emp;

	while (variant != 7)
	{
		Print_Menu();

		variant = get_variant(7);

		switch (variant)
		{
		case 1:
			printf("Insert file name: ");
			scanf("%s", filename_in);
			base.Create_Base(filename_in);
			break;
		case 2:
			base.Print_Base();
			break;
		case 3:
			emp.Insert();
			base.Insert_In_Base(emp);
			break;
		case 4:
			name = InsertName();
			base.Delete_Data(name);
			break;
		case 5:
			name = InsertName();
			base.Data_Correction(name);
			break;
		case 6:
			printf("Insert file name: ");
			scanf("%s", filename_in);
			base.Copy_Base(filename_in);
			break;
		}
		if (variant != 7)
			system("pause");
	}
}