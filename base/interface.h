
#ifndef __INTERFACE_H__
#define __INTERFACE_H__

#include "table.h"
#include "red_black_tree.h"
#include "polynom.h"

class Interface
{
private:
	void TableSelect();
	void Add();
	void Print();
	void Search();
	void ChangePolynom(TableString* data);
	void Calculate();
	void Delete();
	bool isCorrect(string str);
public:
	Interface();
	void Menu();
};
#endif