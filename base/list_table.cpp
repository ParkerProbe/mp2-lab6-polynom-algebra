#include "list_table.h"
void ListTable::insert(const TableString& data_)
{
    if (find_str(data_.key) == nullptr) {
        return;
    }
    data.add(data_);
}
void ListTable::erase(const std::string& key)
{
    TableString* tmp;
    if ((tmp = find_str(key)) == nullptr) {
        return;
    }
    data.erase_first_found((*tmp));
}
TableBody& ListTable::find(const std::string& key)
{
    return find_str(key)->body;
}
TableString* ListTable::find_str(const std::string& key)
{
    for (TableString tmp : data) {
        if (tmp.key == key) {
            TableString* out = new TableString(tmp);
            return out;
        }
    }
}