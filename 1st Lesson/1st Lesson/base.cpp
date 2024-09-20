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
void Base::Insert_In_Base()
{
	if (count == 0) {
		employers = new Sotrudnik[1];
		count = 1;
		employers[0].Insert();
		return;
	}

	if (count < size) {
		employers[count].Insert(); 
	}
	else {
		this->Base_Expansion(); 
		employers[count].Insert(); 
	}

	++count; 
}
void Base::Delete_Data()
{
	char name[31];
	char inic[5];

	printf("Insert name: ");
	scanf("%s", name);
	scanf("%s", inic);

	strcat(name, " ");
	strcat(name, inic);

	int k = 0;

	while (k < size && strcmp(name, employers[k].GetName()) != 0)
	{
		++k;
	}

	if (k < size) { 
		for (int j = k; j < size - 1; ++j)
		{
			employers[j] = employers[j + 1];
		}
		--count; 
	}
}
void Base::Data_Correction()
{
	char name[31];
	char inic[5];

	printf("Insert name: ");
	scanf("%s", name);
	scanf("%s", inic);

	strcat(name, " ");
	strcat(name, inic);


	char new_name[31];
	char new_inic[5];
	int new_year = 0;
	float new_salary = 0.0f;
	char new_date[11];

	int k = 0;
	while (k < count && strcmp(name, employers[k].GetName()) != 0) {
		++k;
	}

	if (k < count) 
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
void Base::Copy_Base()
{
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
			base.Insert_In_Base();
			break;
		case 4:
			base.Delete_Data();
			break;
		case 5:
			base.Data_Correction();
			break;
		case 6:
			base.Copy_Base();
			break;
		}
		if (variant != 7)
			system("pause");
	}
}