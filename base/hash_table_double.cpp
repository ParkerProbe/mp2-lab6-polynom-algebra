#include "hash_table_double.h"
#include "eq_exception.h"
#include "table_string.h"
#include "list.h"
#include "table.h"

unsigned int HashTableDouble::Hash1(const std::string& key)
{
    int hash_result = 0;
    int len = key.length();
    for (int i = 0; i < len; i++)
        hash_result = ((default_size - 1) * hash_result + key[i]) % default_size;
    hash_result = (hash_result * 2 + 1) % default_size;
    return hash_result;
}

unsigned int HashTableDouble::Hash2(const std::string& key)
{
    int hash_result = 0;
    int len = key.length();
    for (int i = 0; i < len; i++)
        hash_result = ((default_size + 1) * hash_result + key[i]) % default_size;
    hash_result = (hash_result * 2 + 1) % default_size;
    return hash_result;
}

TableString* HashTableDouble::find_str(const std::string& key)
{
    int k = 0;
    int h1 = Hash1(key);
    int h2 = Hash2(key);
    while (table[h1] != nullptr && k < default_size)
    {
        if ((table[h1]->key == key) && (flag[h1] == 1))
            return table[h1];
        h1 = (h1 + h2) % default_size;
        k++;
    }
    return nullptr;
}

TableBody* HashTableDouble::find(const std::string& key)
{
    if ((*this).find_str(key) != nullptr)
        return &(*this).find_str(key)->body;
    return nullptr;
}

bool HashTableDouble::erase(const std::string& key)
{
    int k = 0;
    int f = 0;
    int h1 = Hash1(key);
    int h2 = Hash2(key);
    while (table[h1] != nullptr && k < default_size)
    {
        if (table[h1]->key == key)
        {
            f = 1;
            break;
        }
        h1 = (h1 + h2) % default_size;
        k++;
    }
    if (f == 1)
    {
        flag[h1] = -1;
        size--;
        return true;
    }
    return false;
}

bool HashTableDouble::insert(const std::string& key, TableBody& data)
{
    if (is_full()) {
        throw EqException(error_codes::k_OUT_OF_MEMORY);
    }
    int i = 0;
    int h1 = Hash1(key);
    int h2 = Hash2(key);
    TableString* tmp = new TableString(key, data);
    int first_deleted = -1; // ���������� ������ ���������� (���������) �������
    while (first_deleted == -1 && flag[h1] != 0 && i < default_size)
    {
        if (table[h1]->key == key && flag[h1] == 1)
            return false; // ����� ������� ��� ����
        if (flag[h1] == -1) // ������� ����� ��� ������ ��������
            first_deleted = h1;
        h1 = (h1 + h2) % default_size;
        i++;
    }
    if (flag[h1] == 0) // ���� �� ������� ����������� �����, ������� ����� Node
    {
        table[h1] = tmp;
        size_all_non_nullptr++;
        size++;
    }
    else
    {
        table[first_deleted] = tmp;
        size++;
    }
    return true;
}

bool HashTableDouble::is_full() const
{
    if (default_size - size > default_size/2)
        return 1;
    else
    return 0;
}

bool  HashTableDouble::is_tab_ended() const
{
    return curr_index >= default_size;
}

bool HashTableDouble::reset()
{
    if (size != 0)
    {
        int i = 0;
        curr_index = 0;
        while (flag[curr_index + i] != 1 && curr_index + i < default_size)
            i++;
        curr_index = curr_index + i;
        return is_tab_ended();
    }
    curr_index = 0;
    return is_tab_ended();
}

bool HashTableDouble::go_next()
{
    if (is_tab_ended()) {
        return false;
    }
    int i = 1;
    while (flag[curr_index + i] != 1 && curr_index + i<default_size)
        i++;
    curr_index= curr_index + i;
    if (is_tab_ended()) {
        return false;
    }
    return true;
}

TableString* HashTableDouble::get_value()
{
    return table[curr_index];
}

