//
// Created by somec on 2023-10-27.
//

#include "ATMFunctions.h"
#include <iostream>
#include <cstdlib>
#include <limits>

void printIntroMenu() {

    // Intro Message
    std::cout << "Please select an option from the menu below:" << std::endl;
    std::cout << "l -> Login" << std::endl;
    std::cout << "c -> Create New Account" << std::endl;
    std::cout << "q -> Quit" << std::endl;
    std::cout << "> ";
}

void printMainMenu() {

    // Main Menu Messages
    std::cout << "d -> Deposit Money" << std::endl;
    std::cout << "w -> Withdraw Money" << std::endl;
    std::cout << "r -> Request Balance" << std::endl;
    std::cout << "q -> Quit" << std::endl;
    std::cout << "> ";
}

void start(std::vector<BankAccount>& accounts) {
    char menuInput;

    while (true) {
        printIntroMenu();
        std::cin >> menuInput;

        switch (menuInput) {
            case 'l':

                login(accounts);

                break;
            case 'c':

                createAccount(accounts);

                break;
            case 'q':

                std::cout << "Thanks for stopping by!" << std::endl;
                exit(0);

            default:
                std::cout << "Invalid option. Please try again." << std::endl;

        }
    }
}

void createAccount(std::vector<BankAccount>& accounts) {

    int userId;
    std::string password;

    // Enter int for your user identification.
    std::cout << "Please enter your user id: ";
    while (!(std::cin>>userId)) {   // While loop to get userID, and check if what was entered was NOT an int.
        std::cout << "Invalid input! Please enter a number only!: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Outputs only the below message once. Without this the error message below
    }                                                                                // would output the message an amount of times equivalent to chars making up the String.

    // Enter String for user password.
    std::cout << "Please enter your password: ";
    std::cin >> password;

    // Add user information to BankAccount vector named 'accounts'
    accounts.push_back(BankAccount(userId, password));
    std::cout << "Thank You! Your account has been created!" << std::endl;
}

void login(std::vector<BankAccount>& accounts) {
    int userId;
    std::string password;

    std::cout << "Please enter your user id: ";
    std::cin >> userId;
    std::cin.clear();   // Validation explained above.
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Please enter your password: ";
    std::cin >> password;
    std::cin.clear();   // Validation explained above.
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // Create a pointer variable (accountPointer) of the class (BankAccount) and assign it the findAccount function to store the results from said function.
    BankAccount* accountPointer = findAccount(accounts, userId, password);

    if (accountPointer != nullptr) {   // Check if accountPointer details are NOT equal to null using the pointer of the BankAccount object.
        std::cout << "Access Granted!" << std::endl;
        char choice;

        while (true) {
            printMainMenu();
            std::cin >> choice;

            switch (choice) {
                case 'd':

                    double deposit;
                    std::cout << "Amount of deposit: $";
                    while (!(std::cin>>deposit)) {
                        std::cin.clear();   // Validation explained above.
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cout << "Invalid input! Please enter a number only!: ";
                    }
                    //std::cin >> deposit;
                    accountPointer->balance += deposit;    // The pointer is used to assign a new value to the "balance"

                    break;
                case 'w':

                    double withdrawal;
                    std::cout << "Amount of withdrawal: $";
                    while (!(std::cin>>withdrawal)) {
                        std::cin.clear();   // Validation explained above.
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cout << "Invalid input! Please enter a number only!: ";
                    }
                    //std::cin >> withdrawal;
                    if (withdrawal <= accountPointer->balance) {
                        accountPointer->balance -= withdrawal;
                    } else {
                        std::cout << "Insufficient funds!" << std::endl;
                    }

                    break;
                case 'r':

                    std::cout << "Your balance is $" << accountPointer->balance << "." << std::endl;

                    break;
                case 'q':

                    std::cout << "Thanks for stopping by!" << std::endl;
                    return;

                default:
                    std::cout << "Invalid option. Please try again." << std::endl;
            }
        }
    } else {
        std::cout << "\n******** LOGIN FAILED! ********" << std::endl;
    }
}
// Definition of the findAccount function. The for loop uses the variable
BankAccount* findAccount(std::vector<BankAccount>& accounts, int userIDCompare, std::string passwordCompare) {
    for (BankAccount& accountFind : accounts) {
        if (accountFind.userID == userIDCompare && accountFind.password == passwordCompare) {
            return &accountFind;
        }
    }
    return nullptr;
}
