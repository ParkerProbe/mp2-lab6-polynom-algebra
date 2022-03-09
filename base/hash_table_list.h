
   
#ifndef __HASHTABLELIST_H__
#define __HASHTABLELIST_H__

#include "table.h"

class HashTableList : public Table
{
    Data* Tab[1000];
public:
    HashTableList()
    {
      for (int i = 0; i < 1000; i++) {
          Tab[i] = nullptr;
      }
    }
    ~HashTableList();

    Data* find(const std::string& key);
    void insert(const Data& data);
    void erase(const std::string& key);
    void print();
};

#endif