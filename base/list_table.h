#ifndef _LIST_TABLE_H_
#define _LIST_TABLE_H_
#include "table.h"

class ListTable :public Table
{
	List<TableString> data;
public:
	virtual TableBody* find(const std::string& key);
	virtual void insert(const TableString& data);
	virtual void erase(const std::string& key);
	virtual void print();
	virtual bool empty()
	{
		return size == 0;
	}
	virtual int get_size()
	{
		return size;
	}
	ListTable()
	{
		size = 0;
		capacity = 0;
	}
};

#endif