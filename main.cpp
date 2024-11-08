
#include <iostream>
#include "LoanData.h"
#include <iomanip>
#include <cmath>

int main()
{
    std::cout << "Please enter loan amount" << std::endl;
    std::cout << "Please enter years paying" << std::endl;
    std::cout << "Please enter loan rate" << std::endl;

    LoanData L1(100000, 30, 6);
    L1.PrintAmortizationSchedule();
    L1.PrintPayoffTimeReport(100000, 6);
}
