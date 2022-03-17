#include <gtest.h>
#include "list_table.h"
TEST(ListTable, can_create_empty_tab)
{
    ASSERT_NO_THROW(ListTable tab);
}

TEST(ListTable, empty_tab_shows_that_it_is_empty)
{
    ListTable tab;
    ASSERT_NO_THROW(tab.empty());
}

TEST(ListTable, can_existing_find_elem_by_key)
{

}

TEST(ListTable, cant_find_elem_by_non_existent_key)
{

}
TEST(ListTable, can_insert_elem)
{

}
TEST(ListTable, after_insert_elem_tab_is_not_empty)
{

}

TEST(ListTable, cant_insert_elem_with_non_unique_key)
{

}

TEST(ListTable, can_show_table)
{

}

TEST(ListTable, cant_delete_elem_when_its_empty)
{

}

TEST(ListTable, can_delete_existing_elem)
{

}

TEST(ListTable, cant_delete_non_existing_elem)
{

}

//TEST(ListTable)
//{
//
//}