#include "GradeCalculator.h"

char calculateLetterGrade(int score) {
    if (score >= 80) return 'A';
    if (score >= 65) return 'B';
    if (score >= 50) return 'C';
    return 'F';
}

bool isPassing(int score) {
    return score > 50;
}

