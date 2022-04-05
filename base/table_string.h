#ifndef _LIST_H_
#define _LIST_H_

#include <ostream>
#include <string>

#include "polynom.h"

using std::string;

class TableString;


class TableBody
{
private:
    string poly_string;
    Polynom* poly;
    
public:
    TableBody()
        : poly_string()
    {}

    friend class TableString;


    friend std::ostream& operator<<(std::ostream& os, const TableString& ts);

    friend class ArrayTable;
    friend class Table;
    friend class HashTableList;
    friend class HashTableDouble;
    friend class HashTableDouble;
    friend class Interface;
    friend class ListTable;
    friend class RedBlackTree;
    friend class SortTable;
};

//Base element in every table
class TableString
{
private:
    string key;
    TableBody body;
public:
    TableString()
        :body(), key(" ")
    {}

    TableString(string key_, TableBody& body_)
        : key(key_), body(body_)
        {}
    
    TableString(const TableString& other) = default;
    ~TableString() = default;

    TableString& operator=(const TableString& other) = default; 

    int operator==(const TableString& other)
    {
        return key == other.key;
    }

    int operator<(const TableString& other)
    {
        return key < other.key;
    }

    int operator>(const TableString& other)
    {
        return key > other.key;
    }

    inline string GetKey() const
    {
        return key;
    }

    inline Polynom* GetPolynom() const
    {
        return body.poly;
    }

    void print(std::ostream& os) const
    { 
        os << key << " " << body.poly_string << std:: endl;
    }

    friend std::ostream& operator<<(std::ostream& os, const TableString& ts);

    friend class ArrayTable;
    friend class Table;
    friend class HashTableList;
    friend class HashTableDouble;
    friend class HashTableDouble;
    friend class Interface;
    friend class ListTable;
    friend class RedBlackTree;
    friend class SortTable;
};



#endif // _LIST_H_
