#include "LoanData.h"

#ifndef LOANDATA_H
#define LOANDATA_H

#include <iostream>
#include <iomanip>
#include <cmath>

class LoanData
{
private:
    double Bal;
    double n;
    double i;
    double A;
    int months;

public:
    LoanData (double p, double n, double i)
    {
        Bal = p;
        this->n = n;
        this->i = i;

        i = i / 100;
        i = i / 12;
        months = n * 12;

        double numerator = i * pow(1 + i, n);
        double denominator = pow(1 + i, n) - 1;
        A = p * (numerator / denominator);

    }

    void    MakePayment(double pay)
    {
        A = pay;
        Bal = (i + 1) * Bal - pay;
    }

    void    PrintAmortizationSchedule()
    {
        double beginningBalance = Bal;
        double payment;
        double interestPaid;
        double principalPaid;
        double endingBalance;
        int month = 1;

        // Print header
        std::cout << std::left
                  << std::setw(10) << "Month"
                  << std::setw(20) << "Beginning Balance"
                  << std::setw(10) << "Payment"
                  << std::setw(15) << "Interest Paid"
                  << std::setw(15) << "Principal Paid"
                  << std::setw(20) << "Ending Balance" << "\n";

        while (beginningBalance > 0)
        {

            if ((i + 1) * Bal > A)
            {
                payment = A;
            }
            else
            {
                payment = (i + 1) * Bal;
            }

            interestPaid = i * Bal;
            principalPaid = A - interestPaid;
            endingBalance = (i + 1) * Bal - A;

            std::cout << std::setw(15) << month++
                      << std::setw(15) << std::fixed << std::setprecision(2) << beginningBalance
                      << std::setw(15) << payment
                      << std::setw(15) << interestPaid
                      << std::setw(15) << principalPaid
                      << std::setw(15) << endingBalance << "\n";


            beginningBalance = endingBalance;
            Bal = beginningBalance;  // Set Bal to the new beginning balance
        }
    }
        void    PrintPayoffTimeReport(double p, double i)
    {
        this->Bal = p;
        this->i = i;
        for (n = 6; n < 360; n++)
        {
            double numerator = i * pow(1 + i, n);
            double denominator = pow(1 + i, n) - 1;
            A = p * (numerator / denominator);
            std::cout << n << ", " << A << std::endl;

        }

    }

};

#endif