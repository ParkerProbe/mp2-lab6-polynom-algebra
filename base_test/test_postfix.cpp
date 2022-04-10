//#include "postfix.h"
//
//#include <gtest.h>
//
//TEST(TPostfix, can_create_postfix)
//{
//  ASSERT_NO_THROW(TPostfix p);
//}
//
//TEST(TPostfix, can_get_infix)
//{
//  TPostfix p;
//  std::string form = "5+3*4/(2-1)";
//  p.set_infix(form);
//  std::string in = "A+B*C/(D-E)";
//  EXPECT_EQ(in, p.get_infix());
//}
//TEST(TPostfix, can_get_postfix)
//{
//  TPostfix p;
//  std::string form = "5+3*4/(2-1)";
//  p.set_infix(form);
//  p.to_postfix();
//  std::string post = "ABC*DE-/+";
//  EXPECT_EQ(post, p.get_postfix());
//}
//TEST(TPostfix, can_calculate_plus)
//{
//  TPostfix p;
//  std::string form = "5+3.5";
//  p.set_infix(form);
//  p.to_postfix();
//  EXPECT_EQ(8.5, p.calculate());
//}
//
//TEST(TPostfix, can_calculate_minus)
//{
//  TPostfix p;
//  std::string form = "5-3.5";
//  p.set_infix(form);
//  p.to_postfix();
//  EXPECT_EQ(1.5, p.calculate());
//}
//
//TEST(TPostfix, can_calculate_multiplication)
//{
//  TPostfix p;
//  std::string form = "5*3";
//  p.set_infix(form);
//  p.to_postfix();
//  EXPECT_EQ(5 * 3, p.calculate());
//}
//
//TEST(TPostfix, can_calculate_division)
//{
//  TPostfix p;
//  std::string form = "6/3";
//  p.set_infix(form);
//  p.to_postfix();
//  EXPECT_EQ(6 / 3, p.calculate());
