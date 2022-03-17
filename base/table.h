#ifndef _TABLE_H_
#define _TABLE_H_


#include "polynom.h"
#include "table_string.h"
#include "table_iterator.h"
#include <ostream>

class Table
{


protected:
	int size;
	virtual TableString& find_str(const std::string& key) = 0;
public:
	virtual TableBody& find(const std::string& key) = 0;
	virtual void insert(const TableString& data) = 0;
	virtual void erase(const std::string& key) = 0;
	virtual void print() const = 0;
	virtual bool is_full() const = 0;

	// Set to first record
	virtual bool reset() = 0;

	// Is tab ended
	virtual bool is_tab_ended() const = 0;

	// Next record
	// return false for last record
	virtual bool go_next() = 0;

	// Get value of current iterable record
	virtual TableString* get_value() = 0;

	virtual TableIterator begin() const = 0;
	virtual TableIterator end() const = 0;



	virtual ~Table() {}
	virtual bool empty() const
	{
		return size == 0;
	}
	virtual int get_size() const
	{
		return size;
	}

	friend std::ostream& operator<<(std::ostream& os, Table& tab)
	{
		std::cout << "Table printing" << std::endl;
		for (TableIterator it = tab.begin();
       it != tab.end(); ++it)
  	{
    		os << " Key" << (*it).key << " Val "
				 << (*it).body.poly_string << std::endl;
  	}
		return os;
	}

};

#endif // _TABLE_H_