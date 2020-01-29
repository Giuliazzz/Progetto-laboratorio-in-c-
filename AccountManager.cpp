//
// Created by Giuliaz on 20/01/20.
//

#include "AccountManager.h"

namespace fs = std::experimental::filesystem;

AccountManager* AccountManager::instance = nullptr;

shared_ptr<BankAccount> AccountManager::findAccount(int id) {
    for(auto& a : accounts) {
        if (a->getID() == id) {
            return shared_ptr<BankAccount>(a);
        }
    }
    throw accountNotFound();
}

void AccountManager::addAccount() {
    accounts.push_back(shared_ptr<BankAccount>(new BankAccount(next_number)));
    updateNextNumber();
}

void AccountManager::addAccount(float balance) {
    accounts.push_back(shared_ptr<BankAccount>(new BankAccount(next_number, balance)));
    updateNextNumber();
}

void AccountManager::addAccount(ifstream& file, string name) {
    addAccount();
    try {
        auto a = findAccount(stoi(name));
    }
    catch(accountNotFound& e){
        accounts.back()->my_ID = stoi(name);
    }
    string line;
    int k = 0;
    if(file.is_open()){
        while(getline(file, line)){
            if(!k) {
                accounts.back()->balance = stof(line);
                k++;
            } else {
                string delimiter = "::";
                size_t pos = 0;
                int i = 0;
                float bal;
                int oid;
                transaction_type type;
                time_t time;
                string data;
                while ((pos = line.find(delimiter)) != std::string::npos) {
                    data = line.substr(0, pos);
                    line.erase(0, pos + delimiter.length());

                    switch (i) {
                        case (0): {
                            bal = stof(data);
                            break;
                        }

                        case (1): {
                            oid = stoi(data);
                            break;
                        }

                        case (2): {
                            type = (transaction_type) stoi(data);
                            break;
                        }

                        case (3): {
                            time = (time_t) stol(data);
                            break;
                        }
                        default:
                            throw runtime_error("La riga conteneva più dati del previsto.");
                    }
                    i++;
                }
                accounts.back()->addTransaction(bal, oid, type, time);
            }
        }
    }
}

void AccountManager::addFromFolder() {
    std::string path = "../accounts/";
    for (const auto & entry : fs::directory_iterator(path)) {
        ifstream file(entry.path().string(), ios::in);
        addAccount(file, entry.path().string().substr(path.length()));
    }
    updateNextNumber();
}

void AccountManager::removeAccount(int id) {
    int i = 0;
    for(auto itr = accounts.begin(); itr != accounts.end(); itr++) {
        if(accounts[i]->getID() == id) {
            if(accounts[i]->getID() < next_number)
                next_number = accounts[i]->getID();
            accounts.erase(itr);
            break;
        } else {
            i++;
        }
    }
}

void AccountManager::updateNextNumber() {
    int i = 0;
    bool found;
    do {
        found = false;
        for (auto const& a : accounts) {
            if (a->getID() == i) {
                found = true;
                i++;
                break;
            }
        }
    }
    while(found);
    next_number = i;
}

void AccountManager::saveToFile() {
    for(auto const& a : accounts){
        ofstream file("../accounts/" + to_string(a->getID()), ios::trunc | ios::out);
        if(file.is_open()){
            file << to_string(a->getBalance()) + "\n";
            for(auto const& t : a->transactions){
                file << to_string(t->getAmount()) + "::" + to_string(t->getOtherId()) + "::" +
                        to_string(t->getType()) + "::" + to_string(t->getDate()) + "\n";
            }
        } else {
            throw runtime_error("Impossibile aprire il file " + to_string(a->getID()));
        }
    }
}
