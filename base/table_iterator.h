#include "table_string.h"


#ifndef _TABLE_ITERATOR_H_
#define _TABLE_ITERATOR_H_

class TableIterator
{
    friend class Table;
private:
    TableString* p;
    
    TableIterator(TableString* _p) : p(_p)
        {}

  
public:
    TableIterator(const TableIterator &it) : p(it.p)
        {}

    bool operator!=(TableIterator const& other) const
    {
      return p != other.p;
    }

    bool operator==(TableIterator const& other) const
    {
        return p == other.p;
    }

    TableString& operator*() const
    {
        return *p;
    }

    TableIterator& operator++()
    {
        ++p;
        return *this;
    }

};

#endif