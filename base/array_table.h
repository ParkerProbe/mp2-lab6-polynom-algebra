#ifndef _ARRAY_TABLE_H_
#define _ARRAY_TABLE_H_


#include "table.h"
#include <utility>

#define DEFAULT_SIZE 25

class ArrayTable : public Table
{
protected:
    TableString** tbl;
    int size;
    int curr_pos;
public:
    ArrayTable(int _size = DEFAULT_SIZE)
        : Table(), size(_size), curr_pos(0)
    {
        tbl = new TableString*[size];
        for (int i; i < _size; i++) {
            tbl[i] = nullptr;
        }
    }
    virtual ~ArrayTable()
    {
        // Delete key - not  data
        for (int i; i < size; i++) {
            delete [] tbl[i];
        }
        delete [] tbl;
    }


    inline int get_tab_size() const
    {
        return size;
    }
    

    TableString* find_str(const std::string& key);
    TableBody* find(const std::string& key);
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