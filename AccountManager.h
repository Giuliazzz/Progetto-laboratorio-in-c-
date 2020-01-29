//
// Created by Giuliaz on 20/01/20.
//

#ifndef ESLABORATORIO_ACCOUNTMANAGER_H
#define ESLABORATORIO_ACCOUNTMANAGER_H


#include <fstream>
#include <vector>
#include <experimental/filesystem>
#include "BankAccount.h"

using namespace std;

class AccountManager {
public:

    static AccountManager* getInstance() {
        if(instance != nullptr)
            return instance;
        else
            return new AccountManager();
    }

    shared_ptr<BankAccount> findAccount(int id);

    void addAccount();

    void addAccount(float balance);

    void addAccount(ifstream& file, string name);

    void addFromFolder();

    void saveToFile();

    void removeAccount(int id);

private:
    AccountManager() {
        instance = this;
        next_number = 0;
    }

    void updateNextNumber();

    static AccountManager* instance;
    vector<shared_ptr<BankAccount>> accounts;
    int next_number;
};

static AccountManager* instance = nullptr;


#endif //ESLABORATORIO_ACCOUNTMANAGER_H
