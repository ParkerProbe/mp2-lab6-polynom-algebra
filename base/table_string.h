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
    
};
//Base element in every table
struct TableString
{
    string key;
    TableBody body;
};



#endif // _LIST_H_
