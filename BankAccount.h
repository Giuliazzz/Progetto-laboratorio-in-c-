//
// Created by Giuliaz on 20/01/20.
//

#ifndef ESLABORATORIO_BANKACCOUNT_H
#define ESLABORATORIO_BANKACCOUNT_H


#include <memory>
#include <string>
#include <vector>
#include "Exceptions.h"
#include "Transaction.h"

class BankAccount {
public:

    class AccountManager;

    int getID() const { return my_ID; }

    float getBalance() const { return balance; }

    void showBalance() const;

    void showTransaction() const;

    void showTransaction(int i) const;

    void deposit(float amount);

    void withdraw(float amount);

    void transferTo(float amount, shared_ptr<BankAccount> ba);

private:
    explicit BankAccount(int id, float b = 0) : my_ID(id), balance(b) {}

    void receiveFrom(float amount, int id);

    void transfer(float amount, int id, transaction_type t);

    void addTransaction(float amount, int oid, transaction_type t, time_t time);

    int my_ID;
    float balance;
    std::vector<std::unique_ptr<Transaction>> transactions;
};


#endif //ESLABORATORIO_BANKACCOUNT_H
