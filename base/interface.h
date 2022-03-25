
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
    enum Table_num
    {
        k_TABLE,
        k_ARRAY_TABLE,
        k_SORTED_ARRAY_TABLE,
        k_LIST_TABLE,
        k_RED_BLACK_TREE,
        k_CHAIN_HASH_TABLE,
        k_LIST_HASH_TABLE,
    };
    Table_num mode;
private:
    /*void table_select();
    void add();
    void print();
    void search();
    void change_polynom(TableString* data);
    void calculate();
    void erase();
    bool is_correct(string str);*/

    bool is_tab_not_chosen();
    bool are_sure();
    void table_menu();
    void find();
    void insert();
    void erase();
    void polinom_menu();
    void print();
public:
    Interface() :mode(Table_num::k_TABLE)
    {}
    void menu();
};
#endif