#ifndef _TABLE_STRING_H_
#define _TABLE_STRING_H_

#include <ostream>
#include <string>

#include "polynom.h"

using std::string;

class TableString;


struct TableBody
{
    string poly_string;
    Polynom* poly;
    TableBody()
        : poly_string(), poly(nullptr)
    {}
    TableBody(const Polynom& poly_)
    {
        poly = new Polynom(poly_);
        poly_string = poly_.str();
    }

   /* friend class TableString;


    friend std::ostream& operator<<(std::ostream& os, const TableString& ts);*/

 /*   friend class ArrayTable;
    friend class Table;
    friend class HashTableList;
    friend class HashTableDouble;
    friend class HashTableDouble;
    friend class Interface;
    friend class ListTable;
    friend class RedBlackTree;
    friend class SortTable;*/
};

//Base element in every table
struct TableString
{
    //private:
    string key;
    TableBody body;

    TableString()
        :body(), key(" ")
    {}

    TableString(string key_, TableBody& body_)
        : key(key_), body(body_)
    {
        const int k_MAX_NAME = 16;
        //const int k_MAX_POLY_STRING = 102;
        if (key_.size() > k_MAX_NAME)
            throw EqException(error_codes::k_OVERFLOW);
        for (int i = 0; i < key.size(); i++)
        {

            char c = key[i];
            if (c == 'I')
                throw EqException(error_codes::k_USING_RESERVED_NAME);
            if (c == 'd' && (key[i + 1] == 'x' || key[i + 1] == 'y' || key[i + 1] == 'z'))
                throw EqException(error_codes::k_USING_RESERVED_NAME);
            if (c >= '9' + 1 && c <= '9' + 7)
                throw EqException(error_codes::k_USING_PUNCTUATION_MARKS);
        }
    }

    TableString(const TableString& other) = default;
    ~TableString() = default;

    TableString& operator=(const TableString& other) = default;

    bool operator==(const TableString& other)
    {
        return key == other.key;
    }
    bool operator!=(const TableString& other)
    {
        return key != other.key;
    }

    bool operator<(const TableString& other)
    {
        return key < other.key;
    }

    bool operator>(const TableString& other)
    {
        return key > other.key;
    }

    inline string get_key() const
    {
        return key;
    }

    inline Polynom* get_polynom() const
    {
        return body.poly;
    }

    void print(std::ostream& os) const
    {
        os << key << " " << body.poly_string << std::endl;
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



#endif // 