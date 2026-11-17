#include "calc.h"

#include <gtest/gtest.h>

// Calc::Add Function Tests.
TEST(CalcTest, AddHandlingBothPositiveOperands) {
  EXPECT_DOUBLE_EQ(Add(3,6), 9);
  EXPECT_DOUBLE_EQ(Add(6.2,8.1), 14.3);
}
TEST(CalcTest, AddHandlingSingleNegativeOperand) {
  EXPECT_DOUBLE_EQ(Add(-3,6), 3);
  EXPECT_DOUBLE_EQ(Add(3000, -2000.2), 999.8);
  EXPECT_DOUBLE_EQ(Add(0,-17), -17);
  EXPECT_DOUBLE_EQ(Add(-18.6, 4.4), -14.2);
}
TEST(CalcTest, AddHandlingBothNegativeOperand) {
  EXPECT_DOUBLE_EQ(Add(-3,-6), -9);
  EXPECT_DOUBLE_EQ(Add(-3000, -2000.2), -5000.2);
  EXPECT_DOUBLE_EQ(Add(-0,-17), -17);
  EXPECT_DOUBLE_EQ(Add(-18.6, -4.4), -23);
}
// Calc::Subtract Function Tests.
TEST(CalcTest, SubtractHandlingBothPositiveOperands) {
  EXPECT_DOUBLE_EQ(Subtract(3,6), -3);
  EXPECT_DOUBLE_EQ(Subtract(8.1, 6.2), 1.9);
}
TEST(CalcTest, SubtractHandlingSingleNegativeOperand) {
  EXPECT_DOUBLE_EQ(Subtract(-3,6), -9);
  EXPECT_DOUBLE_EQ(Subtract(3000, -2000.2), 5000.1999999999998);
  EXPECT_DOUBLE_EQ(Subtract(0,-17), 17);
  EXPECT_DOUBLE_EQ(Subtract(-18.6, 4.4), -23);
}
TEST(CalcTest, SubtractHandlingBothNegativeOperand) {
  EXPECT_DOUBLE_EQ(Subtract(-3,-6), 3);
  EXPECT_DOUBLE_EQ(Subtract(-3000, -2000.2), -999.8);
  EXPECT_DOUBLE_EQ(Subtract(-0,-17), 17);
  EXPECT_DOUBLE_EQ(Subtract(-18.6, -4.4), -14.2);
}
// Calc::Multiply Function Tests.
TEST(CalcTest, MultiplyHandlingBothPositiveOperands) {
  EXPECT_DOUBLE_EQ(Multiply(3,6), 18);
  EXPECT_DOUBLE_EQ(Multiply(8.1, 6.2), 50.22);
}
TEST(CalcTest, MultiplyHandlingSingleNegativeOperand) {
  EXPECT_DOUBLE_EQ(Multiply(-3,6), -18);
  EXPECT_DOUBLE_EQ(Multiply(3000, -2000.2), -6000600);
  EXPECT_DOUBLE_EQ(Multiply(0,-17), 0);
  EXPECT_DOUBLE_EQ(Multiply(-18.6, 4.4), -81.84);
}
TEST(CalcTest, MultiplyHandlingBothNegativeOperand) {
  EXPECT_DOUBLE_EQ(Multiply(-3,-6), 18);
  EXPECT_DOUBLE_EQ(Multiply(-3000, -2000.2), 6000600);
  EXPECT_DOUBLE_EQ(Multiply(-0,-17), 0);
  EXPECT_DOUBLE_EQ(Multiply(-18.6, -4.4), 81.84);
}
// Calc::Divide Function Tests.
TEST(CalcTest, DivideHandlingBothPositiveOperands) {
  EXPECT_DOUBLE_EQ(Divide(3,6), 0.5);
  EXPECT_DOUBLE_EQ(Divide(8.1, 6.2), 1.3064516129032258);
}
TEST(CalcTest, DivideHandlingSingleNegativeOperand) {
  EXPECT_DOUBLE_EQ(Divide(-3,6), -0.5);
  EXPECT_DOUBLE_EQ(Divide(3000, -2000.2), -1.4998500149985001);
  EXPECT_DOUBLE_EQ(Divide(0,-17), 0);
  EXPECT_DOUBLE_EQ(Divide(-18.6, 4.4), -4.2272727272727275);
}
TEST(CalcTest, DivideHandlingBothNegativeOperand) {
  EXPECT_DOUBLE_EQ(Divide(-3,-6), 0.5);
  EXPECT_DOUBLE_EQ(Divide(-3000, -2000.2), 1.4998500149985001);
  EXPECT_DOUBLE_EQ(Divide(-0,-17), 0);
  EXPECT_DOUBLE_EQ(Divide(-18.6, -4.4), 4.2272727272727275);
}
TEST(CalcTest, DivideHandlingDividingByZero) {
    EXPECT_THROW(Divide(7, 0), std::invalid_argument);
}