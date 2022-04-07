#ifndef _TABLE_STRING_H_
#define _TABLE_STRING_H_

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
<<<<<<< HEAD
=======
    
>>>>>>> 55a71b49e09385f1870914eb62041ece58185c9b
public:
    TableBody()
        : poly_string(), poly(nullptr)
    {}
<<<<<<< HEAD
    TableBody(const Polynom& poly_)
    {
        poly = new Polynom(poly_);
        poly_string = poly_.str();
    }
=======
>>>>>>> 55a71b49e09385f1870914eb62041ece58185c9b

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
<<<<<<< HEAD
//private:
public:
=======
private:
>>>>>>> 55a71b49e09385f1870914eb62041ece58185c9b
    string key;
    TableBody body;
public:
    TableString()
        :body(), key(" ")
    {}

    TableString(string key_, TableBody& body_)
        : key(key_), body(body_)
<<<<<<< HEAD
    {
        const int k_MAX_NAME = 16;
        //const int k_MAX_POLY_STRING = 102;
        if (key_.size() > k_MAX_NAME)
            throw EqException(error_code::k_OVERFLOW);
        for (int i=0;i<key.size();i++)
        {
           
            char c = key[i];
            if (c == 'I')
                throw EqException(error_code::k_USING_RESERVED_NAME);
            if (c == 'd' && (key[i + 1] == 'x' || key[i + 1] == 'y'||key[i+1]=='z'))
                throw EqException(error_code::k_USING_RESERVED_NAME);
            if (c >= '9' + 1 && c <= '9' + 7)
                throw EqException(error_code::k_USING_PUNCTUATION_MARKS);
        }
    }

=======
        {}
    
>>>>>>> 55a71b49e09385f1870914eb62041ece58185c9b
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

<<<<<<< HEAD
    inline string get_key() const
=======
    inline string GetKey() const
>>>>>>> 55a71b49e09385f1870914eb62041ece58185c9b
    {
        return key;
    }

<<<<<<< HEAD
    inline Polynom* get_polynom() const
=======
    inline Polynom* GetPolynom() const
>>>>>>> 55a71b49e09385f1870914eb62041ece58185c9b
    {
        return body.poly;
    }

    void print(std::ostream& os) const
<<<<<<< HEAD
    {
        os << key << " " << body.poly_string << std::endl;
=======
    { 
        os << key << " " << body.poly_string << std:: endl;
>>>>>>> 55a71b49e09385f1870914eb62041ece58185c9b
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