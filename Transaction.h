//
// Created by Giuliaz on 20/01/20.
//

#ifndef ESLABORATORIO_TRANSACTION_H
#define ESLABORATORIO_TRANSACTION_H

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <ctime>

class enum Transaction_type 
{   INGOING,
    OUTGOING,
    WITHDRAWAL,
    DEPOSIT
};

class Transaction {
private:

    class BankAccount;

    transaction_type getType() const { return type; }

    int getOtherId() const { return other_ID; }

    float getAmount() const { return amount; }

    time_t getDate() const { return date; }

    void showData() const;

public:
    Transaction(transaction_type t, int oid, float a, time_t time) : type(t), other_ID(oid), amount(a), date(time) {}

    const transaction_type type;
    const int other_ID;
    const float amount;
    const time_t date;
};


#endif //ESLABORATORIO_TRANSACTION_H
