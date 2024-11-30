#include <iostream>
#include "Function.hpp"

class Menu
{
private:
   int SelectItem(int nItem) const;
   Function** functions;
   int size;
public:
	~Menu()
	{
		delete[] functions;
	}
   Menu(Function** functions_, int size);
   Function* SelectObject() const;
};