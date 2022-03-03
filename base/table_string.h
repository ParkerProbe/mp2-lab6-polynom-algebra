#ifndef _LIST_H_
#define _LIST_H_

#include <string>

#include "polynom.h"

using std::string;

struct TableString // Структура удобна, но может нарушить инкапсуляцию. Оставим структурой
{
    std::string key;
    std::string poly_string;
    Polynom* poly;
};




#endif // _LIST_H_
