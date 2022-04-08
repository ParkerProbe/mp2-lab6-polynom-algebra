
#ifndef __INTERFACE_H__
#define __INTERFACE_H__

#include "table.h"
#include "red_black_tree.h"
#include "polynom.h"
#include "array_table.h"
#include "list_table.h"
#include "sorted_array_table.h"
#include "hash_table_list.h"
#include "hash_table_double.h"
#include "eq_exception.h"
#include "postfix.h"
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
    const int k_table_size;
    Table_num mode;
    // 0 Arr, 1 Sort, 2 List, 3 Tree, 4 Chain-Hash, 5 List-Hash
    Table** tab;
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
    void polynom_menu();
    void print();

   /* catch (EqException exc)
    {
        print_error(exc.get_error);
    }*/
    void print_error(error_codes ec);
public:
    Interface() :mode(Table_num::k_TABLE), k_table_size(6)
    {
        tab = new Table * [k_table_size];
        tab[0] = new ArrayTable;
        tab[1] = new SortTable;
        tab[2] = new ListTable;
        tab[3] = new RedBlackTree;
        //////////////////////////////////////////////////
       // tab[4] = new HashTableDouble(100);
        tab[5] = new HashTableList(100);
    }
    void menu();
};
#endif