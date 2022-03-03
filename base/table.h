#ifndef _TABLE_H_
#define _TABLE_H_


#include "table_string.h"

class Table
{
public:
	virtual TableString* Find(const std::string& key) = 0;
	virtual void Insert(const TableString& data) = 0;
	virtual void Delete(const std::string& key) = 0;
    virtual void print() = 0;
    virtual ~Table(){}
	virtual is_empty();
	virtual is_full();
};
  
#endif // _TABLE_H_