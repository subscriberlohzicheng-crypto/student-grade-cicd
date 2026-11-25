#include <gtest/gtest.h>
#include "GradeCalculator.h"

TEST(GradeCalculatorTest, HighScoreReturnsA) {
    EXPECT_EQ(calculateLetterGrade(90), 'A');
}
