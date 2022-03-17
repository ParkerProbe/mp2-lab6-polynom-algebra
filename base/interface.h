
#ifndef __INTERFACE_H__
#define __INTERFACE_H__

#include "table.h"
#include "red_black_tree.h"
#include "polynom.h"
#include "array_table.h"
#include "list_table.h"
#include <conio.h>

class Interface
{
   // ListTable lt;
private:
    void table_select();
    void add();
    void print();
    void search();
    void change_polynom(TableString* data);
    void calculate();
    void erase();
    bool is_correct(string str);


    void table_menu();
    void polinom_menu();
/// <summary>
/// void table();
/// void postfix();
/// </summary>
public:
    Interface() 
    {}
    void menu();
};
#endif