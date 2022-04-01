#ifndef _LIST_TABLE_H_
#define _LIST_TABLE_H_
#include "table.h"

class ListTable :public Table
{
    List<TableString> data;
    virtual TableString* find_str(const std::string& key);
public:
    TableBody* find(const std::string& key);
    void insert(const TableString& data_);
    void erase(const std::string& key);
    /////////////////////////////////////
    void print();
    bool empty()
    {
        return data_cnt == 0;
    }
    int get_size()
    {
        return data_cnt;
    }
    bool is_full()
    {
        try {
            NodeList<TableString>* tmp = new NodeList<TableString>;
            delete tmp;
        }
        catch (...)
        {
            return true;
        }
        return false;
    }
    ListTable() : data()
    {
        data_cnt = 0;
    }
    ListTable(std::vector<TableString> a) : data(a)
    {
        data_cnt = a.size();
    }
    ~ListTable()
    {}
};
#endif