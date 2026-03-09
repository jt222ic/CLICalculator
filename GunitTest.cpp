//
// Created by JanTr on 2026-01-19.
//
#include <gtest/gtest.h>
#include "GunitTest.h"
#include <stdexcept>
#include "Calculator.h"



Calculator calc;

TEST(CalculatorTest, ReturnsValidVoltage) {

    EXPECT_DOUBLE_EQ(input.readVoltage(), 3.3);
}
TEST(CalculatorTest, ReturnValidCurrent) {

    EXPECT_DOUBLE_EQ(calc.readCurrent(), 3.3);
}
TEST(CalculatorTest,ReturnValidPower) {
    EXPECT_DOUBLE_EQ(calc.readPower(), 3.3);
}


TEST(CombineValue, PositiveValues) {

    EXPECT_DOUBLE_EQ(calc.calculatePower(5.0, 2.0), 10.0);
}

TEST(CombineValue, ZeroVoltage) {

    EXPECT_DOUBLE_EQ(calc.calculatePower(0.0, 5.0), 0.0);
}

TEST(CombineValue, NegativeValues) {

    EXPECT_DOUBLE_EQ(calc.calculatePower(-5.0, 4.0), -12.0);
}

// TEST(KalkylatorTest, NotANumber) {
//     // I TDD definierar vi även hur fel ska hanteras
//     EXPECT_THROW(calc.readVoltage(), std::invalid_argument);
// }

 int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);


     return RUN_ALL_TESTS();
 }
