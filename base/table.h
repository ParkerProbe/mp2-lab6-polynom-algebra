#ifndef _TABLE_H_
#define _TABLE_H_


#include "table_string.h"

//It is possible that new methods or fields will be added
class Table
{
	virtual TableString* find_str(const std::string& key) = 0;
public:
	virtual TableBody* find(const std::string& key) = 0;
	virtual void insert(const TableString& data) = 0;
	virtual void erase(const std::string& key) = 0;
  virtual void print() = 0;
  virtual ~Table(){}
	virtual bool empty();
	virtual bool full();
};
  
#endif // _TABLE_H_