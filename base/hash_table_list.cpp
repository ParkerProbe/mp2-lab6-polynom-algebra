#include "hash_table_list.h"
#include "eq_exception.h"
#include "table_string.h"


TableString* HashTableList::find_str(const std::string& key)
{
    int index = Hash(key);
    for(TLink* p = table[index]; p != nullptr; p = p->pNext) {
        if(p->rec->key == key) {
            return p->rec;
        }
    }
    return nullptr;
}

void HashTableList::insert(const TableString& data)
{
    int index = Hash(data.key);
    TLink* p = new TLink();
    p->rec = new TableString(data);
    p->pNext = table[index];
    table[index] = p;
    data_cnt++;
}


void HashTableList::erase(const std::string& key)
{
    int index = Hash(key);

    if(table[index] == nullptr) {
        throw(EqException(error_code::k_NOT_FOUND));
    }

    TLink* p = table[index];
    TLink* pp = nullptr;
    for(; p != nullptr; p = p->pNext) {
        if(p->rec->key == key) {
            if(pp == nullptr) {
                delete [] p;
            }
            else {
                pp->pNext = p->pNext;
                delete [] p;
            }
        }
        pp = p;
    }
    throw EqException(error_code::k_NOT_FOUND);

}

bool HashTableList::is_full() const
{
    try {
        TableString* pNode = new TableString();
    }
    catch(std::bad_alloc& e) {
        return 1;
    }
    
    return 0;
}

bool  HashTableList::is_tab_ended() const
{
    return curr_pos >= data_cnt;

}

bool HashTableList::reset()
{
    curr_pos = 0;
    curr_index = 0;
    ptr_curr_pos = table[0];
    return is_tab_ended();
}

bool HashTableList::go_next()
{
    if(is_tab_ended()) {
        return false;
    }

    if(ptr_curr_pos->pNext == nullptr) {
        curr_pos++;
        curr_index++;
        ptr_curr_pos = table[curr_index];
    }
    else {
        ptr_curr_pos = ptr_curr_pos->pNext;
        curr_pos++;
    }
    return true;
}


void HashTableList::print()
{
    operator<<(std::cout, *this);
}

bool HashTableList::set_current_pos(int pos)
{
    curr_pos = ((pos > -1) && (pos < data_cnt)) ? pos : 0;
    return is_tab_ended(); 
}

int HashTableList::get_current_pos() const
{
    return curr_pos;
}

TableString*  HashTableList::get_value()
{
    return ptr_curr_pos->rec;
}