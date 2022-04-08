#include "list_table.h"
//void insert(const std::string& key, TableBody& data)
bool ListTable::insert(const std::string& key, TableBody& data_)
{
    if (!find_str(key))/*!= nullptr*/ {
        return false;
    }
    TableString tmp(key, data_);
    data.add(tmp);
    return true;
}
bool ListTable::erase(const std::string& key)
{
    TableString* tmp;
    if (find_str(key) == nullptr) {
        return false;
    }
    data.erase_first_found((*tmp));
    return true;
}
TableBody* ListTable::find(const std::string& key)
{
    TableString* tmp = find_str(key);
    if (tmp == nullptr) {
        return nullptr;
    }
    else {
        return &(tmp->body);
    }
}
TableString* ListTable::find_str(const std::string& key)
{
    for (TableString tmp : data) {
        if (tmp.key == key) {
            TableString* out = new TableString(tmp);
            return out;
        }
    }
    return nullptr;
}
void ListTable::print()
{
    print_header();
    for (ListIterator<TableString> it = data.begin(); it != data.end(); ++it)
        std::cout << *it;
}