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
    }
}

void HashTableDouble::insert(const TableString& data)
{
    if (is_full()) {
        throw EqException(error_codes::k_OUT_OF_MEMORY);
    }
    int i = 0;
    int h1 = Hash1(data.key);
    int h2 = Hash2(data.key);
    TableString* tmp = new TableString(data);
    int first_deleted = -1; // ���������� ������ ���������� (���������) �������
    while (first_deleted == -1 && flag[h1] != 0 && i < default_size)
    {
        if (table[h1]->key == data.key && flag[h1] == 1)
            return; // ����� ������� ��� ����
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
}

bool HashTableDouble::is_full() const
{
    try {
        TableString* pNode = new TableString();
    }
    catch (std::bad_alloc& e) {
        return 1;
    }

    return 0;
}
