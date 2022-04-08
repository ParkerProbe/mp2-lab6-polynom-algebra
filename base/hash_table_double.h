#ifndef __HASHTABLEDOUBLE_H__
#define __HASHTABLEDOUBLE_H__


#include "table.h"
#include "table_string.h"
#include <string>

class HashTableDouble : public Table
{
private:
    int default_size;//размер таблицы
    int size;// количество эл-в в таблице
    int size_all_non_nullptr;//кол-во эл-в вместе с удаленными
    int* flag;//массив состояния элементов таблицы
    TableString** table;
    unsigned int Hash1(const std::string& key);
    unsigned int Hash2(const std::string& key);
public:
    HashTableDouble(int _size)
    {
        default_size = _size;
        size = 0;
        size_all_non_nullptr = 0;
        table = new TableString * [default_size];
        flag = new int [default_size];
        for (int i = 0; i < default_size; i++)
            table[i] = nullptr;
    }

    ~HashTableDouble()
    {
        for (int i = 0; i < default_size; i++)
                delete table[i];
        delete[] table;
    }

    int get_size()
    {
        return size;
    }

    TableString* find_str(const std::string& key);
    void insert(const TableString& data);
    bool erase(const std::string& key);
    void print();
    bool is_full() const;
};


#endif