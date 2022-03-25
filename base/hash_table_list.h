
   
#ifndef __HASHTABLELIST_H__
#define __HASHTABLELIST_H__

#include "table.h"
#include "table_string.h"
#include <string>
#include <vector>

class HashTableList : public Table
{
private:
    struct TLink
    {
        TableString* rec;
        TLink* pNext;
    };

    int size;

    int curr_pos;
    int curr_index;
    TLink* ptr_curr_pos;

    std::vector<TLink*> table;

    int Hash(const std::string& key)
    {
        
    }

public:
    HashTableList(int _size)
        :  size(_size), table(_size, nullptr)
    {}

    ~HashTableList() = default;

    TableString* find_str(const std::string& key);
    void insert(const TableString& data);
    void erase(const std::string& key);
    void print();
    bool is_full() const;
    bool reset();
    bool is_tab_ended() const;
    bool go_next();
    bool set_current_pos(int pos);
    int get_current_pos() const;
    TableString* get_value();
};

#endif