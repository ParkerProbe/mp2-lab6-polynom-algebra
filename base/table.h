#ifndef _TABLE_H_
#define _TABLE_H_


#include "table_string.h"

class Table
{
	virtual TableString* Find_str(const std::string& key) = 0;
public:
	virtual TableBody* Find(const std::string& key) = 0;
	virtual void Insert(const TableString& data) = 0;
	virtual void Delete(const std::string& key) = 0;
    virtual void print() = 0;
    virtual ~Table(){}
	virtual bool is_empty();
	virtual bool is_full();
};
  
#endif // _TABLE_H_