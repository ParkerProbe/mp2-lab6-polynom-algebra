#ifndef _TABLE_H_
#define _TABLE_H_


#include "table_string.h"

// READ THIS CLASS!
class Table
{
protected:
	int size;
	int capacity;
	virtual TableString* find_str(const std::string& key) = 0;
public:
	virtual TableBody* find(const std::string& key) = 0;
	virtual void insert(const TableString& data) = 0;
	virtual void erase(const std::string& key) = 0;
	virtual void print() = 0;
	virtual ~Table() {}
	virtual bool empty()
	{
		return size == 0;
	}
	virtual int get_size()
	{
		return size;
	}
};

#endif // _TABLE_H_