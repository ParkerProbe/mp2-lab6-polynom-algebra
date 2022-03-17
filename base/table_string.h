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
        : poly_string("0")
    {}
    bool operator!=(const TableBody& tb)
    {
        return poly_string != tb.poly_string;
    }
    bool operator==(const TableBody& tb)
    {
        return poly_string != tb.poly_string;
    }
};
//Base element in every table
struct TableString
{
    string key;
    TableBody body;
    TableString() 
        :body(), key("I")
    {}
    bool operator!=(const TableString& ts)
    {
        return body != ts.body;
    }
    bool operator==(const TableString& ts)
    {
        return body == ts.body;
    }
};



#endif // _LIST_H_
