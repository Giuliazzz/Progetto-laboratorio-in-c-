//
// Created by Giuliaz on 20/01/20.
//

#include "BankAccount.h"

void BankAccount::deposit(float amount) {
    transfer(amount, my_ID, DEPOSIT);
    balance += amount;
}

void BankAccount::withdraw(float amount) {
    if(balance > amount) {
        transfer(amount * -1, my_ID, WITHDRAWAL);
        balance -= amount;
    }
    else
        throw noMoneyException();
}

void BankAccount::transferTo(float amount, shared_ptr<BankAccount> ba) {
    if(balance > amount) {
        transfer(amount * -1, ba->getID(), OUTGOING);
        balance -= amount;
        ba->receiveFrom(amount, my_ID);
    }
    else
        throw noMoneyException();
}

void BankAccount::receiveFrom(float amount, int id) {
    transfer(amount, id, INGOING);
    balance += amount;
}

void BankAccount::transfer(float amount, int id, transaction_type t) {
    transactions.push_back(std::unique_ptr<Transaction>(new Transaction(t, id, amount, time(nullptr))));
}

void BankAccount::showBalance() const {
    std::cout << std::setprecision(2) << std::fixed << balance << "€" << std::endl;
}

void BankAccount::showTransaction() const {
    int i = 1;
    for(auto& t : transactions) {
        std::cout << i << ". ";
        t->showData();
        i++;
    }
}

void BankAccount::showTransaction(int i) const {
    transactions[i]->showData();
}

void BankAccount::addTransaction(float amount, int oid, transaction_type t, time_t time) {
    transactions.push_back(std::unique_ptr<Transaction>(new Transaction(t, oid, amount, time)));
}
