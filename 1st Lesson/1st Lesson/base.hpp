//#include "sotrudnic.hpp" 

#include <iostream>
#include <string.h>
#include <stdlib.h>
/*
class Base
{
private:
	int size;
	Sotrudnik* employers;
public:
	Base()
	{
		size = 0;
		employers = new Sotrudnik[size];
	}
	Base(int n)
	{
		size = n;
		employers = new Sotrudnik[size];
	}
	~Base()
	{
		if (!employers)
			delete[] employers;
	}
	void Create_Base(const char* namefile)
	{
		Create_f(namefile, size, employers);
	}
	void Print_Base()
	{
		for (int i = 0; i < size; ++i)
			employers[i].Print();
	}
	void Insert_In_Base() 
	{
		if (size == 0) {
			employers = new Sotrudnik[1];
			size = 1;
		}

		int k = 0;
		while (k < size && employers[k].GetYear() != 0) {
			++k;
		}

		if (k < size) {
			employers[k].Insert();
		}
		else {
			// Увеличение массива
			Sotrudnik* new_arr = new Sotrudnik[2 * size];
			for (int i = 0; i < size; ++i) {
				new_arr[i] = employers[i];
			}
			delete[] employers; // Удаляем старый массив
			employers = new_arr;
			size *= 2;

			employers[k].Insert(); // Вставляем нового сотрудника
		}
	}
	void Delete_Data(const char* name_) 
	{
		int k = 0;
		while (k < size && strcmp(name_, employers[k].GetName()) != 0) 
		{
			++k;
		}

		if (k < size) { // Если нашли сотрудника
			for (int j = k; j < size - 1; ++j) 
			{
				employers[j] = employers[j + 1];
			}
			--size; // Уменьшаем размер
		}
	}
	void Data_Correction(const char* name_) 
	{
		char new_name[31];
		int new_year = 0;
		float new_salary = 0.0f;
		char new_date[11];

		int k = 0;
		while (k < size && strcmp(name_, employers[k].GetName()) != 0) {
			++k;
		}

		if (k < size) { // Если нашли сотрудника
			printf("Insert new data: ");
			while (scanf("%s %d %f %s", new_name, &new_year, &new_salary, new_date) != 4);

			employers[k].SetName(new_name);
			employers[k].SetYear(new_year);
			employers[k].SetSal(new_salary);
			employers[k].SetData(new_date);
		}
		else {
			printf("Сотрудник не найден.\n");
		}
	}
	void Copy_Base() 
	{
		// Реализация глубокого копирования
		Sotrudnik* new_arr = new Sotrudnik[size];
		for (int i = 0; i < size; ++i) {
			new_arr[i] = employers[i];
		}
		delete[] employers; // Удаляем старый массив
		employers = new_arr;
	}
};
*/