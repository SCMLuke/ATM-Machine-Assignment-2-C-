//
// Created by somec on 2023-10-27.
//

#ifndef ATM_MACHINE_ATTEMPT_2_BANKACCOUNT_H
#define ATM_MACHINE_ATTEMPT_2_BANKACCOUNT_H


#include <string>

struct BankAccount {
    int userID;
    std::string password;
    double balance;

    BankAccount(int id, std::string pass);
};


#endif //ATM_MACHINE_ATTEMPT_2_BANKACCOUNT_H
