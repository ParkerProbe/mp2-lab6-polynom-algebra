
   
#ifndef __HASHTABLELIST_H__
#define __HASHTABLELIST_H__

#include "table.h"
#include "table_string.h"
#include <string>
#include <vector>
#include "list.h"

class HashTableList : public Table
{
private:
    int size;
    int curr_index;
    std::vector<List<TableString*>*> table;
    ListIterator<TableString*> curr_pos;
    unsigned int Hash(const std::string& key);

public:
    HashTableList(int _size)
        :  size(_size), table(_size, nullptr), curr_pos(table[0]->begin())
    {
        for(int i = 0; i < _size; i++) {
            table[i] = new List<TableString*>;
        }
    }

    ~HashTableList() = default;

    TableString* find_str(const std::string& key);
    void insert(const TableString& data);
    void erase(const std::string& key);
    void print();
    bool is_full() const;
    bool reset();
    bool is_tab_ended() const;
    bool go_next();
    bool set_current_pos(int pos) = delete;
    int get_current_pos() const = delete;
    TableString* get_value();
};

#endif