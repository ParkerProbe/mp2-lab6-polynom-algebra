#ifndef _LIST_H_
#define _LIST_H_

#include <string>

#include "polynom.h"

using std::string;

struct TableBody
{
    string poly_string;
    Polynom* poly;
};
struct TableString
{
    string key;
    TableBody body;
};



#endif // _LIST_H_
