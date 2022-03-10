
#ifndef __INTERFACE_H__
#define __INTERFACE_H__

#include "table.h"
#include "red_black_tree.h"
#include "polynom.h"

// static?

class Interface
{
private:
    void table_select();
    void add();
    // may be print_string and print_table
    void print();
    void search();
    void change_polynom(TableString* data);
    void calculate();
    void erase();
    bool is_correct(string str);
public:
    Interface();
    void menu();
};
#endif