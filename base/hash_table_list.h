
   
#ifndef __HASHTABLELIST_H__
#define __HASHTABLELIST_H__

#include "table.h"
#include "table_string.h"
#include <string>
#include <vector>
#include "list.h"

#define DEFAULT_SIZE 25


class HashTableList : public Table
{
private:
    int size;
    int curr_index;
    int curr_pos_num;
    std::vector<List<TableString*>*> table;
    ListIterator<TableString*> curr_pos;
    unsigned int Hash(const std::string& key);

public:
    HashTableList(int _size = DEFAULT_SIZE)
        :  size(_size), table(_size, nullptr), curr_pos(table[0]->begin())
    {
        for(int i = 0; i < _size; i++) {
            table[i] = new List<TableString*>;
        }
    }

    ~HashTableList() = default;

    int get_size()
    {
        return size;
    }

    TableString* find_str(const std::string& key);
    void insert(const std::string& key, TableBody& data);
    void erase(const std::string& key);
    void print();
    bool is_full() const;
    bool reset();
    bool is_tab_ended() const;
    bool go_next();
    TableString* get_value();
    bool set_current_pos(int pos);
    int get_current_pos() const ;
    int hash_string(const std::string& key);
};

#endif