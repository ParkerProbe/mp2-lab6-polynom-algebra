#ifndef _TABLE_H_
#define _TABLE_H_


#include "polynom.h"
#include "table_string.h"
#include <ostream>
#include <string>

class Table
{
protected:
    int data_cnt;
    virtual TableString* find_str(const std::string& key) = 0;
    
public:
    Table() : data_cnt(0) {}
    virtual ~Table() {}


    virtual void insert(const TableString& data) = 0;
    virtual void erase(const std::string& key) = 0;
    virtual void print() = 0;
    inline virtual bool is_full() const = 0;

    // Set to first record
    virtual bool reset() = 0;

    virtual bool is_tab_ended() const = 0;

    // Next record
    // return false for last record
    virtual bool go_next() = 0;

    // Get value of current iterable record
    inline virtual TableString* get_value() = 0;

    virtual TableBody* find(const std::string& key)
    {
        return &(*this).find_str(key)->body;
    }

    inline virtual bool empty() const
    {
        return data_cnt == 0;
    }

    inline virtual int get_size() const
    {
        return data_cnt;
    }

    friend std::ostream& operator<<(std::ostream& os, Table& tab)
    {
        std::cout << "Table printing" << std::endl;
        for (tab.reset(); !tab.is_tab_ended(); tab.go_next()) {
            os << " Key" << tab.get_value()->key << " Val "
                << tab.get_value()->body.poly_string << std::endl;
        }
        return os;
    }


};

#endif // _TABLE_H_