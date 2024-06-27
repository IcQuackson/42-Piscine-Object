#include "Bank.hpp"
#include <iostream>
#include <string>

/* function to receive a color and text and print text in that color */
void printColor(std::string color, std::string text) {
    std::cout << color << text << RESET << std::endl;
}

int main() {
    Bank myBank;

    // Test 1: Create accounts and check initial balances
    printColor(GREEN, "Test 1: Account Creation");
    const Bank::Account* account1 = myBank.createAccount(100);
    const Bank::Account* account2 = myBank.createAccount(200);
    std::cout << "Account 1 Balance: " << account1->getBalance() << std::endl;
    std::cout << "Account 2 Balance: " << account2->getBalance() << std::endl << std::endl;

    // Negative Test: Create account with invalid balance (e.g., negative)
    printColor(RED, "Negative Test: Create account with negative balance");
    try {
        const Bank::Account* invalidAccount = myBank.createAccount(-100);
        std::cout << "Invalid Account Balance: " << invalidAccount->getBalance() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    // Test 2: Deposit and withdrawal
    printColor(GREEN, "\nTest 2: Deposit and Withdrawal Operations");
    printColor(GREEN, "Adding 50 to Account 1 and withdrawing 25 from Account 2");
    myBank.depositToAccount(account1->getId(), 50);
    myBank.withdrawFromAccount(account2->getId(), 25);
    std::cout << "Account 1 Balance after Deposit: " << account1->getBalance() << std::endl;
    std::cout << "Account 2 Balance after Withdrawal: " << account2->getBalance() << std::endl;

    // Negative Test: Deposit negative amount
    printColor(RED, "\nNegative Test: Deposit negative amount");
    try {
        myBank.depositToAccount(account1->getId(), -50);
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    // Negative Test: Withdrawal with insufficient funds
    printColor(RED, "\nNegative Test: Withdrawal with insufficient funds");
    try {
        myBank.withdrawFromAccount(account1->getId(), 1000);
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    // Test 3: Liquidity management
    printColor(GREEN, "\nTest 3: Liquidity Management");
    printColor(GREEN, "Setting Liquidity to 1000, increasing by 500 and decreasing by 200");
    myBank.setLiquidity(1000);
    myBank.increaseLiquidity(500);
    myBank.decreaseLiquidity(200);
    std::cout << "Current Liquidity: " << myBank.getLiquidity() << std::endl;

    // Negative Test: Increase liquidity by a negative amount
    printColor(RED, "\nNegative Test: Increase liquidity by a negative amount");
    try {
        myBank.increaseLiquidity(-100);
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    // Negative Test: Decrease liquidity below zero
    printColor(RED, "\nNegative Test: Decreasing liquidity below zero");
    try {
        myBank.decreaseLiquidity(2000);
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    // Test 4: Access account using operator[]
    printColor(GREEN, "\nTest 4: Operator [] Access");
    const Bank::Account* accountAtIndex = myBank[1];
    std::cout << "Account at Index 1: " << *accountAtIndex << std::endl;

    // Negative Test: Access invalid account index
    printColor(RED, "\nNegative Test: Access invalid account index");
    try {
        const Bank::Account* invalidAccount = myBank[100];
        std::cout << "Account at Index 100: " << *invalidAccount << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    // Test 6: Getting a loan
    printColor(GREEN, "\nTest 5: Getting a Loan");
    std::cout << "Account 1 Balance before Loan: " << account1->getBalance() << std::endl;
    printColor(GREEN, "Getting a loan of 500 on Account 1");
    myBank.getLoan(account1->getId(), 500);
    std::cout << "Account 1 Balance after Loan: " << account1->getBalance() << std::endl;

    // Negative Test: Attempt to get a loan on an invalid account
    printColor(RED, "\nNegative Test: Attempt to get a loan on an invalid account");
    try {
        myBank.getLoan(101, 500);
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    // Negative Test: Attempt to get a loan when bank has no liquidity
    printColor(RED, "\nNegative Test: Attempt to get a loan when bank has no liquidity");
    try {
        printColor(RED, "Getting a loan of 5000 on Account 2");
        myBank.getLoan(account2->getId(), 5000);
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    // Test 6: Output Bank and Account details
    printColor(GREEN, "\nTest 5: Output Bank and Account Details");
    std::cout << myBank << std::endl;
    printColor(BLUE, "Account 1 Details:");
    std::cout << *account1 << std::endl;
    printColor(BLUE, "Account 2 Details:");
    std::cout << *account2 << std::endl;

    return 0;
}
