// #include <gtest.h>
// #include "hash_table_list.h"

#include "../gtest/gtest.h"
#include "../base/hash_table_list.h"



TEST(HashTableList, can_create_table)
{
	ASSERT_NO_THROW(HashTableList tab);
}

TEST(HashTableList, can_hash_string)
{
    HashTableList tab(2);
    ASSERT_NO_THROW(tab.hash_string("xyz12"));    
}


TEST(HashTableList, can_insert_elem_in_tab)
{
    HashTableList tab(2);
    TableBody rec;
    tab.insert("1", rec);
}

TEST(HashTableList, can_insert_elem_in_tab_when_its_not_empty)
{
    HashTableList tab(2);
    TableBody rec1;
    tab.insert("1", rec1);
    tab.insert("2", rec1);
}

TEST(HashTableList, cant_insert_elem_with_same_key)
{
    HashTableList tab(2);
    TableBody rec1;
    tab.insert("1", rec1);
    ASSERT_ANY_THROW(tab.insert("2", rec1));
}

TEST(HashTableList, cant_find_when_is_empty)
{
    HashTableList tab(2);
    ASSERT_ANY_THROW(tab.find_str("1"));
}

TEST(HashTableList, can_find_elem)
{
    HashTableList tab(2);
    TableBody rec1;
    tab.insert("1", rec1);
    EXPECT_EQ(tab.find_str("1")->key, "1");
}

TEST(HashTableList, cant_find_elem)
{
    HashTableList tab(2);
    TableBody rec1;
    tab.insert("1", rec1);
    EXPECT_EQ(tab.find_str("2"), nullptr);
}

TEST(HashTableList, cant_delete_elem_when_its_empty)
{
    HashTableList tab(2);
    ASSERT_ANY_THROW(tab.erase("1"));
}

TEST(HashTableList, can_delete_existing_elem)
{
    HashTableList tab(2);
    TableBody rec1;
    tab.insert("1", rec1);
    tab.erase("1");
    EXPECT_EQ(tab.get_data_count(), 0);
}

TEST(HashTableList, cant_delete_non_existing_elem)
{
    HashTableList tab(2);
    TableBody rec1;
    tab.insert("1", rec1);
    ASSERT_ANY_THROW(tab.erase("2"));
}


TEST(HashTableList, can_check_is_tab_ended_1)
{
    HashTableList tab(2);
    EXPECT_EQ(tab.is_tab_ended(), true);
}


TEST(HashTableList, can_go_next)
{
    HashTableList tab(2);
    TableBody rec1;
    tab.insert("1", rec1);
    tab.insert("2", rec1);
    tab.go_next();
    EXPECT_EQ(tab.get_value()->key, "2");
}


TEST(HashTableList, cant_go_next)
{
    HashTableList tab(2);
    TableBody rec1;
    tab.insert("1", rec1);
    tab.go_next();
    EXPECT_EQ(tab.get_value()->key, "1");
}

TEST(HashTableList, can_reset)
{
    HashTableList tab(2);
    TableBody rec1;

    tab.insert("1", rec1);
    tab.insert("2", rec1);
    tab.insert("3", rec1);

    tab.go_next();
    tab.go_next();
    tab.reset();

    EXPECT_EQ(tab.get_value()->key, "1");
}

TEST(HashTableList, can_check_is_tab_ended_2)
{
    HashTableList tab(2);
    EXPECT_EQ(tab.reset(), true);
}

TEST(HashTableList, can_check_is_tab_ended_3)
{
    HashTableList tab(2);
    TableBody rec1;
    tab.insert("1", rec1);
    tab.insert("2", rec1);
    tab.insert("3", rec1);
    tab.go_next();
    tab.go_next();
    EXPECT_EQ(tab.is_tab_ended(), true);
}


TEST(HashTableList, can_get_current_pos)
{
    HashTableList tab(2);
    TableBody rec1;

    tab.insert("1", rec1);
    tab.insert("2", rec1);
    tab.insert("3", rec1);

    tab.go_next();
    tab.go_next();

    EXPECT_EQ(tab.get_current_pos(), 2);
}


TEST(HashTableList, can_set_current_pos)
{
    HashTableList tab(2);
    TableBody rec1;

    tab.insert("1", rec1);
    tab.insert("2", rec1);
    tab.insert("3", rec1);

    tab.set_current_pos(2);

    EXPECT_EQ(tab.set_current_pos(2), true);
    
    EXPECT_EQ(tab.get_current_pos(), 2);
    EXPECT_EQ(tab.get_value()->key, "3");
}


TEST(HashTableList, cant_set_current_pos)
{
    HashTableList tab(2);
    TableBody rec1;

    tab.insert("1", rec1);
    tab.insert("2", rec1);
    tab.insert("3", rec1);

    tab.set_current_pos(3);

    EXPECT_EQ(tab.set_current_pos(3), false);
}

TEST(HashTableList, can_get_value)
{
    HashTableList tab(2);
    TableBody rec1;
    tab.insert("1", rec1);
    EXPECT_EQ(tab.get_value()->key, "1");
}

