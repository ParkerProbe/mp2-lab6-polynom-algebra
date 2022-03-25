#include "sorted_array_table.h"
#include "eq_exception.h"
#include "table_string.h"
#include <algorithm>

#include <cstddef>
#include <string>

void SortTable::Sort (TableString** unsrtd_table, int data_cnt)
{
    std::sort(unsrtd_table[0], unsrtd_table[data_cnt - 1]);
}

TableString* SortTable::find_str(const std::string& key)
{
    int i, i1 = 0, i2 = data_cnt -1;

    while(i1 <= i2) {
        i = (i1 + i2) >> 1;

        if (tbl[i]->key == key) {
            i1 = i + 1;
            i2 = i;
            break;
        }

        if (tbl[i]->key > key) {
            i2 = i - 1;
        }
        else {
            i1 = i + 1;
        }
    }
    if ((i2 < 0) || (tbl[i2]->key < key))  {
        i2++;
    }
    curr_pos = i2;
    if ((i2 < data_cnt) && (tbl[i]->key == key)) {
        return tbl[i2];
    }
    return nullptr;
}


void SortTable::insert(const TableString& data)
{
    if(is_full()) {
        throw (EqException(error_code::k_OUT_OF_MEMORY));
    }
    else {
        for (int i = data_cnt; i > curr_pos; i--) {
            tbl[i] = tbl[i-1];
        }
        tbl[curr_pos] = new TableString(data);
        data_cnt++;
    }

}

void SortTable::erase(const std::string& key)
{
    TableString* tmp = find_str(key);
    if (tmp == nullptr) {
        throw (EqException(error_code::k_NOT_FOUND));
    }
    else {
        for (int i = curr_pos; i < data_cnt; i++) {
            tbl[i] = tbl[i + 1];
        }
        tbl[--data_cnt] = nullptr;
    }
}