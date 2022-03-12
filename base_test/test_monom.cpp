#include <polynom.h>

#include <gtest.h>

TEST(TMonom, can_create_monom_default)
{
  ASSERT_NO_THROW(Monom m());
}
TEST(TMonom, can_create_monom)
{
  ASSERT_NO_THROW(Monom m(2.5, 123));
}
TEST(TMonom, can_create_monom_copy)
{
  ASSERT_NO_THROW(Monom m());
}
TEST(TMonom, cant_create_monom_with_degree_more_than_max_degree)
{
  ASSERT_ANY_THROW();
}
TEST(TMonom, cant_create_monom_with_degree_less_than_null)
{
  ASSERT_ANY_THROW(Monom m(2.5, -123));
}

TEST(TMonom, true_if_first_monom_is_less_than_second_monom)
{
  Monom m();
  Monom m1();
  EXPECT_EQ(true, m < m1);
}

TEST(TMonom, can_plus_two_monoms)
{
  Monom m();
  Monom m1();
  ASSERT_NO_THROW(m + m1);
}

TEST(TMonom, can_minus_two_monoms)
{
  Monom m();
  Monom m1();
  ASSERT_NO_THROW(m - m1);
}

TEST(TMonom, can_multiply_two_monoms)
{
  Monom m();
  Monom m1();
  ASSERT_NO_THROW(m * m1);
}

TEST(TMonom, can_take_derivative_to_param)
{
  Monom m();
  ASSERT_NO_THROW(m.derivative('x'));
}

TEST(TMonom, can_take_integral_to_param)
{
  Monom m();
  ASSERT_NO_THROW(m.integral('x'));
}
