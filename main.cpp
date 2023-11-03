#include <iostream>
#include <iostream>
#include <vector>
#include <cstdlib>
#include "BankAccount.h"
#include "ATMFunctions.h"

int main() {
    std::cout << "Hi! Welcome to Luke’s ATM Machine!\n";
    std::vector<BankAccount> accounts;
    start(accounts);
    return 0;
}
