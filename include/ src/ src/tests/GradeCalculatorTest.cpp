#include <gtest/gtest.h>
#include "GradeCalculator.h"

TEST(GradeCalculatorTest, LetterGradesCoverAllBranches) {
    EXPECT_EQ(calculateLetterGrade(90), 'A');
    EXPECT_EQ(calculateLetterGrade(70), 'B');
    EXPECT_EQ(calculateLetterGrade(55), 'C');
    EXPECT_EQ(calculateLetterGrade(40), 'F');
}

TEST(GradeCalculatorTest, PassingThresholdWorks) {
    EXPECT_TRUE(isPassing(50));
    EXPECT_TRUE(isPassing(85));
    EXPECT_FALSE(isPassing(49));
}

