#ifndef _SORTED_ARRAY_TABLE_H_
#define _SORTED_ARRAY_TABLE_H_

#include "array_table.h"
#include "table_string.h"


class SortTable : public ArrayTable
{
private:
    void Sort (TableString** unsrtd_table, int data_cnt);

public:
    SortTable(int size = DEFAULT_SIZE) : ArrayTable(size) {} ;


    TableString* find_str(const std::string& key) override ;
    TableBody* find(const std::string& key) override;
    void insert(const TableString& data) override;
    void erase(const std::string& key) override;
};
#endif


