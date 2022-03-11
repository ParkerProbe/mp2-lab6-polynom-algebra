#ifndef _ARRAY_TABLE_H_
#define _ARRAY_TABLE_H_


#include "table.h"

class ArrayTable : public Table
{
    TableString* data;
    int capacity;
    void repack();
public:
    ArrayTable() : Table()
    {
        size = 0;
        capacity_ = 100;
        data = new TableString[capacity_];
    }
    void erase(const string& key);
    void insert(const TableString& data);
    TableString* find(const string& key);
    void print();
    ~ArrayTable();
};


#endif