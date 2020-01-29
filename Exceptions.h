//
// Created by Giuliaz on 20/01/20.
//

#ifndef ESLABORATORIO_EXCEPTIONS_H
#define ESLABORATORIO_EXCEPTIONS_H

#include <exception>

using namespace std;

class noMoneyException: public exception {
public:
    const char* what() const noexcept override {
        return "Il conto non ha un bilancio sufficiente a eseguire la transazione.";
    }
};


class accountNotFound: public exception {
public:
    const char* what() const noexcept override {
        return "Non è presente un conto con l'ID specificato.";
    }
};

#endif //ESLABORATORIO_EXCEPTIONS_H
