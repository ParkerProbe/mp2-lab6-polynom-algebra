#ifndef _LIST_H_
#define _LIST_H_

#include <ostream>
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

    int operator==(const TableString& other)
    {
        return key == other.key;
    }

    int operator< (const TableString& other)
    {
        return key < other.key;
    }

    int operator> (const TableString& other)
    {
        return key > other.key;
    }
};



#endif // _LIST_H_
