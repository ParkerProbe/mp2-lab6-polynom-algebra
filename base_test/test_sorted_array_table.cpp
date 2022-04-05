
#include <gtest.h>
#include "sorted_array_table.h"

// #include "../gtest/gtest.h"
// #include "../base/sorted_array_table.h"

TEST(SortTable, can_create_table)
{
	ASSERT_NO_THROW(SortTable tab);
}

TEST(SortTable, can_insert_elem_in_tab)
{
    SortTable tab(2);
    TableBody rec;
    tab.insert("1", rec);
}

TEST(SortTable, can_insert_elem_in_tab_when_its_not_empty)
{
    SortTable tab(2);
    TableBody rec1;
    tab.insert("1", rec1);
    tab.insert("2", rec1);
}

TEST(SortTable, cant_insert_elem_with_same_key)
{
    SortTable tab(2);
    TableBody rec1;
    tab.insert("1", rec1);
    ASSERT_ANY_THROW(tab.insert("2", rec1));
}

TEST(SortTable, cant_find_when_is_empty)
{
    SortTable tab(2);
    ASSERT_ANY_THROW(tab.find_str("1"));
}

TEST(SortTable, can_find_elem)
{
    SortTable tab(2);
    TableBody rec1;
    tab.insert("1", rec1);
    EXPECT_EQ(tab.find_str("1")->key, "1");
}

TEST(SortTable, cant_find_elem)
{
    SortTable tab(2);
    TableBody rec1;
    tab.insert("1", rec1);
    EXPECT_EQ(tab.find_str("2"), nullptr);
}

TEST(SortTable, cant_delete_elem_when_its_empty)
{
    SortTable tab(2);
    ASSERT_ANY_THROW(tab.erase("1"));
}

TEST(SortTable, can_delete_existing_elem)
{
    SortTable tab(2);
    TableBody rec1;
    tab.insert("1", rec1);
    tab.erase("1");
    EXPECT_EQ(tab.get_data_count(), 0);
}

TEST(SortTable, cant_delete_non_existing_elem)
{
    SortTable tab(2);
    TableBody rec1;
    tab.insert("1", rec1);
    ASSERT_ANY_THROW(tab.erase("2"));
}


TEST(SortTable, can_check_is_tab_ended_1)
{
    SortTable tab(2);
    EXPECT_EQ(tab.is_tab_ended(), true);
}


TEST(SortTable, can_go_next)
{
    SortTable tab(2);
    TableBody rec1;
    tab.insert("1", rec1);
    tab.insert("2", rec1);
    tab.go_next();
    EXPECT_EQ(tab.get_value()->key, "2");
}


TEST(SortTable, cant_go_next)
{
    SortTable tab(2);
    TableBody rec1;
    tab.insert("1", rec1);
    tab.go_next();
    EXPECT_EQ(tab.get_value()->key, "1");
}

TEST(SortTable, can_reset)
{
    SortTable tab(2);
    TableBody rec1;

    tab.insert("1", rec1);
    tab.insert("2", rec1);
    tab.insert("3", rec1);

    tab.go_next();
    tab.go_next();
    tab.reset();

    EXPECT_EQ(tab.get_value()->key, "1");
}

TEST(SortTable, can_check_is_tab_ended_2)
{
    SortTable tab(2);
    EXPECT_EQ(tab.reset(), true);
}

TEST(SortTable, can_check_is_tab_ended_3)
{
    SortTable tab(2);
    TableBody rec1;
    tab.insert("1", rec1);
    tab.insert("2", rec1);
    tab.insert("3", rec1);
    tab.go_next();
    tab.go_next();
    EXPECT_EQ(tab.is_tab_ended(), true);
}


TEST(SortTable, can_get_current_pos)
{
    SortTable tab(2);
    TableBody rec1;

    tab.insert("1", rec1);
    tab.insert("2", rec1);
    tab.insert("3", rec1);

    tab.go_next();
    tab.go_next();

    EXPECT_EQ(tab.get_current_pos(), 2);
}


TEST(SortTable, can_set_current_pos)
{
    SortTable tab(2);
    TableBody rec1;

    tab.insert("1", rec1);
    tab.insert("2", rec1);
    tab.insert("3", rec1);

    tab.set_current_pos(2);

    EXPECT_EQ(tab.set_current_pos(2), true);

    EXPECT_EQ(tab.get_current_pos(), 2);
    EXPECT_EQ(tab.get_value()->key, "3");
}


TEST(SortTable, cant_set_current_pos)
{
    SortTable tab(2);
    TableBody rec1;

    tab.insert("1", rec1);
    tab.insert("2", rec1);
    tab.insert("3", rec1);

    tab.set_current_pos(3);

    EXPECT_EQ(tab.set_current_pos(3), false);
}

TEST(SortTable, can_get_value)
{
    SortTable tab(2);
    TableBody rec1;
    tab.insert("1", rec1);
    EXPECT_EQ(tab.get_value()->key, "1");
}

