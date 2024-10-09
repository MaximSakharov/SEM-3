#pragma warning (disable: 4996)

#include <iostream>
#include <string.h>
#include <stdlib.h>

#include "sotrudnic.hpp" 
#include "base.h"
#include "functions.hpp"

//int Base::count = 0;

Base::Base()
{
	size = 100;
	count = 0;
	employers = new Sotrudnik[size];
	for (int i = 0; i < size; ++i)
		employers[i];
}

Base::Base(int n)
{
	size = n;
	count = 0;
	employers = new Sotrudnik[size];
	for (int i = 0; i < size; ++i)
		employers[i];
}

Base::~Base()
{
	if (employers)
		delete[] employers;
}

Base::Base(const Base& base_)
{
	employers = nullptr;
	if (base_.employers != nullptr)
	{
		employers = new Sotrudnik[base_.size];

		for (int i = 0; i < count; i++)
			employers[i] = base_.employers[i];
	}

	size = base_.size;
	count = base_.count;
}

Base& Base::operator = (Base& base_)
{
	if (&base_ == this) return *this;

	size = base_.size;
	count = base_.count;
	if (base_.employers != nullptr)
	{
		employers = new Sotrudnik[base_.size];

		for (int i = 0; i < count; i++)
			employers[i] = base_.employers[i];
	}
	else
		employers = nullptr;

	return *this;
}

Sotrudnik& Base::operator[](int index_)
{
	if (index_ < 0 || index_ > size)
		exit(1);
	else
		return employers[index_];
}


int Base::Create_Base(const char* namefile)
{
	if (!namefile)
		return -1;

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
		employers[count].SetYear(io);
		employers[count].SetName(FIO);
		employers[count].SetSal(oklad);
		employers[count].SetData(dat);

		++count;

		if (count == size)
			Base_Expansion();
	}

	fclose(fp);

	return 0;
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
		employers[0] = new_emp;
		return;
	}

	int pos = count;
	bool flag = false;

	Sotrudnik* new_emps = new Sotrudnik[count + 1];

	for (size_t i = 0; i < count; i++)
	{
		if (flag == false && strcmp(employers[i].GetName(), new_emp.GetName()) > 0)
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
int Base::Delete_Data(char* name_)
{
	if (!name_)
		return -1;

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
	/*
	if (k < size) {
		for (int j = k; j < count - 1; ++j)
		{
			this[j] = this[j + 1];
		}
		--count;
	}
	*/

	//printf("Employee succefully delete.\n");

	return 0;
}
int Base::Data_Correction(char* name_)
{
	if (!name_)
		return -1;

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
	else
		return -2;

	return 0;
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

	int flag = 0;

	while (variant != 7)
	{
		Print_Menu();

		variant = get_variant(7);

		switch (variant)
		{
		case 1:
			printf("Insert file name: ");
			scanf("%s", filename_in);
			if (base.Create_Base(filename_in) != 0)
				printf("Error filename.\n");
			else
				printf("The base was created.\n");
			break;
		case 2:
			base.Print_Base();
			break;
		case 3:
			printf("Insert file name: ");
			emp.Insert();
			base.Insert_In_Base(emp);
			break;
		case 4:
			name = InsertName();
			if (base.Delete_Data(name)==0)
				printf("Employee succefully delete.\n");
			break;
		case 5:
			name = InsertName();
			flag = base.Data_Correction(name);
			if (flag == 0)
				printf("Employee was corrected.\n");
			else if (flag == -1)
				printf("Not correct name.\n");
			else
				printf("There is no employee with this name in the database.\n");
			break;
		case 6:
			printf("Insert file name: ");
			scanf("%s", filename_in);
			if (base.Copy_Base(filename_in) == 0)
				printf("The base was copied.\n");
			else
				printf("Error filename.\n");
			break;
		}
		if (variant != 7)
			system("pause");
	}
}