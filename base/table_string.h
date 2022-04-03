#ifndef _LIST_H_
#define _LIST_H_

#include <string>

#include "polynom.h"

using std::string;


//Protects against key damage
struct TableBody
{
    string poly_string;
    Polynom* poly;
    TableBody()
        : poly_string()
    {}
};
//Base element in every table
struct TableString
{
    string key;
    TableBody body;
    TableString()
        :body(), key("I")
    {}

    TableString(string key_, TableBody& body_)
        : key(key_), body(body_)
        {}
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


    // friend std::ostream& operator<<(std::ostream& os, const TableString& ts);
};



#endif // _LIST_H_
