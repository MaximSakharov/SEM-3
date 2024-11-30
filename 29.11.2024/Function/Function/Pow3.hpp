#include "Function.hpp"

class Pow3 : public Function
{
private:

public:
	Pow3()
	{
		name = new char[8];

		strcpy_s(name, 8, "x ^ 3");
	}
	~Pow3() { delete[] name; }
	const char* GetName() const
	{
		return name;
	}
	void Calculate();
};