#include <iostream>
#include <string>
#include "GradeCalculator.h"

int main(int argc, char* argv[]) {
    // Post-deployment smoke/health check mode
    if (argc > 1 && std::string(argv[1]) == "--health-check") {
        if (calculateLetterGrade(85) == 'A' && isPassing(50)) {
            std::cout << "HEALTH CHECK OK" << std::endl;
            return 0;
        }
        std::cerr << "HEALTH CHECK FAILED" << std::endl;
        return 1;
    }

    int score = 78;
    std::cout << "Student Score: " << score
              << " | Letter Grade: " << calculateLetterGrade(score)
              << " | Status: " << (isPassing(score) ? "PASS" : "FAIL")
              << std::endl;
    return 0;
}
