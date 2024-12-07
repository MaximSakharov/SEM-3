//#include "sotrudnic.hpp" 

#include <iostream>
#include <string.h>
#include <stdlib.h>

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
		employers = new Sotrudnik [size];
	}
	~Base()
	{
		if (!employers)
			delete[] employers;
	}
	void Print_Base()
	{
		for (int i = 0; i < size; ++i)
			employers[i].Print();
	}
	void Insert_In_Base(Sotrudnik new_param)
	{
		Base(++size);
		employers[size] = new_param;
	}
};