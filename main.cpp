//Coder/Developer: Lorenna Solis, Alexis Taggart
//Class: COP 2006-80599, Fall 2024
//Date: November 7th, 2024
//Description: Write a C++ program to calculate,
//• the monthly payment on a loan given the loan amount,
//• interest rate and
//• the number of years to pay off the loan.
//• Then add a function to print an amortization schedule for that loan.
//• Create a class to save the current balance and the rest of the data as private data.
//• Add member functions to make a payment and to print the amortization report
//Log: November  4th, 2024- Started Program 
//https://www.geeksforgeeks.org/constructors-c/ (review for using constructors) 




#include <iostream>
#include <cmath>
#include <iomanip>

class LoanData
 {
private:
    double Bal;
    double n;
    double i;
    double A;

public:
    LoanData(double p, double n, double i)
     {
        i = i / 100.0;      
        i = i / 12.0;       
        n = n * 12;         
        A = p * (i * pow(1 + i, n)) / (pow(1 + i, n) - 1);  
        Bal = p;            
    }

    void MakePayment(double pay) 
    {
        Bal = (i + 1) * Bal - pay;  
    }

    void printAmortizationSchedule()
     {
        double beginningBalance = Bal;
        double payment;
        double interestPaid;
        double principalPaid;
        double endingBalance;
        int month = 1;

        std::cout << std::left
                  << std::setw(10) << "Month"
                  << std::setw(20) << "Beginning Balance"
                  << std::setw(10) << "Payment"
                  << std::setw(15) << "Interest Paid"
                  << std::setw(15) << "Principal Paid"
                  << std::setw(20) << "Ending Balance" << "\n";

        while (beginningBalance > 0)
         {
            interestPaid = i * beginningBalance;
            if ((i + 1) * beginningBalance > A)
             {
                payment = A;
            } else
             {
                payment = (i + 1) * beginningBalance;
            }
            principalPaid = payment - interestPaid;
            endingBalance = (i + 1) * beginningBalance - payment;
            beginningBalance = endingBalance;

            std::cout << std::fixed << std::setprecision(2)
                      << std::setw(10) << month++
                      << std::setw(20) << beginningBalance
                      << std::setw(10) << payment
                      << std::setw(15) << interestPaid
                      << std::setw(15) << principalPaid
                      << std::setw(20) << endingBalance << "\n";
        }
    }

    void printPayOffTimeReport(double p, double i) 
    {
        double A;
        for (int n = 6; n < 360; n++) 
        {
            A = p * (i * pow(1 + i, n)) / (pow(1 + i, n) - 1);
            std::cout << "Months: " << n << " - Monthly Payment: " << A << "\n";
        }
    }
};

int main() 
{
    double p = 10000;   // Loan amount
    double n = 30;      //years
    double i = 6;       //rate

    LoanData loan(p, n, i);
    loan.printAmortizationSchedule();  // Print amortization schedule
    loan.printPayOffTimeReport(p, i); // Print payoff time report

    return 0;
}
