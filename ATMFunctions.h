//
// Created by somec on 2023-10-27.
//

#ifndef ATM_MACHINE_ATTEMPT_2_ATMFUNCTIONS_H
#define ATM_MACHINE_ATTEMPT_2_ATMFUNCTIONS_H


#include <vector>
#include "BankAccount.h"

void printIntroMenu();
void printMainMenu();
void start(std::vector<BankAccount>& accounts);
void login(std::vector<BankAccount>& accounts);
void createAccount(std::vector<BankAccount>& accounts);
BankAccount* findAccount(std::vector<BankAccount>& accounts, int userIDCompare, std::string passwordCompare);


#endif //ATM_MACHINE_ATTEMPT_2_ATMFUNCTIONS_H
