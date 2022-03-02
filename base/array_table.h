#ifndef _ARRAY_TABLE_H_
#define _ARRAY_TABLE_H_


#include "table.h"

class ArrayTable : public Table
{
    TableString* data_;
    int size_;
    int capacity_;
    void Repack();
public:
    ArrayTable() : BaseTable()
    {
        size = 0;
        capacity_ = 100;
        data = new TableString[capacity_];
    }
    void Delete(const string& key);
    void Insert(const TableString& data);
    TableString* Find(const string& key);
    void Print();
    ~ArrayTable();
};


#endif