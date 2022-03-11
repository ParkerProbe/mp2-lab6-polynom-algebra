#include <polynom.h>

#include <gtest.h>

TEST(TPolynom, can_create_polynom_default)
{
    ASSERT_NO_THROW(Polynom pl());
}

TEST(TPolynom, can_create_polynom_copy)
{
    ASSERT_NO_THROW(Polynom pl());
}

TEST(TPolynom, can_create_polynom_from_string)
{
    ASSERT_NO_THROW(Polynom pl());
}

TEST(TPolynom, can_create_polynom_from_list)
{
    ASSERT_NO_THROW(Polynom pl());
}

TEST(TPolynom, can_add_monom_to_polynom)
{
    Polynom pl();
    ASSERT_NO_THROW(pl.add_monom());
}

TEST(TPolynom, can_sort_monoms_of_polynom)
{
    Polynom pl();
    ASSERT_NO_THROW(pl.sort());
}

TEST(TPolynom, can_plus_two_polynoms)
{
    Polynom pl1();
    Polynom pl2();
    ASSERT_NO_THROW(pl1 + pl2);
}

TEST(TPolynom, can_minus_two_polynoms)
{
    Polynom pl1();
    Polynom pl2();
    ASSERT_NO_THROW(pl1 - pl2);
}

TEST(TPolynom, can_multiply_two_polynoms)
{
    Polynom pl1();
    Polynom pl2();
    ASSERT_NO_THROW(pl1 * pl2);
}

TEST(TPolynom, can_calculate_value_in_point)
{
    Polynom pl();
    ASSERT_NO_THROW(pl.calculate_in_point());
}

TEST(TPolynom, can_take_derivative)
{
    Polynom pl;
    ASSERT_NO_THROW(pl.derivative());
}

TEST(TPolynom, can_take_integral)
{
    Polynom pl;
    ASSERT_NO_THROW(pl.integral());
}

TEST(TPolynom, can_write_to_file)
{
    Polynom pl;
    ASSERT_NO_THROW(pl.write_to_file());
}

TEST(TPolynom, can_read_from_file)
{
    Polynom pl;
    ASSERT_NO_THROW(pl.read_from_file());
}