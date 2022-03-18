#ifndef _ARRAY_TABLE_H_
#define _ARRAY_TABLE_H_


#include "table.h"
#include <utility>

#define DEFAULT_SIZE 25

class ArrayTable : public Table
{
    TableString** data;
    int size;
    int curr_pos;
public:
    ArrayTable(int _size = DEFAULT_SIZE)
        : Table(), size(_size), curr_pos(0)
    {
        data = new TableString*[size];
        for (int i = 0; i < _size; i++) {
          data[i] = nullptr;
        }
    }
    virtual ~ArrayTable()
    {
      for (int i = 0; i < size; i++) {
        delete [] data[i];
      }
      delete [] data;
    }
	  
    TableString& find_str(const std::string& key) = 0;
    TableBody& find(const std::string& key) = 0;
	  void insert(const TableString& data) = 0;
	  void erase(const std::string& key) = 0;
	  void print() const = 0;
	  bool is_full() const = 0;
	  bool reset() = 0;
	  bool is_tab_ended() const = 0;
    bool go_next() = 0;
    TableString* get_value() = 0;
    TableIterator begin() const = 0;
    TableIterator end() const = 0; 
};


#endif