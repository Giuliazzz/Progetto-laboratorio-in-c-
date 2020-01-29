//
// Created by Giuliaz on 20/01/20.
//

#include "Transaction.h"

using namespace std;

void string Transaction::getString() const {
    tm* tm = localtime(&date);
    switch(type) {
        case INGOING:
            cout << setprecision(2) << fixed << amount << "€ ricevuti dal conto n. " << other_ID;
            break;
        case OUTGOING:
            cout << setprecision(2) << fixed << amount * (-1) << "€ inviati al conto n. " << other_ID;
            break;
        case DEPOSIT:
            cout << setprecision(2) << fixed << amount << "€ depositati";
            break;
        case WITHDRAWAL:
            cout << setprecision(2) << fixed << amount * (-1) << "€ ritirati";
            break;
    }
    cout << " in data " << tm->tm_year + 1900 << "/" << setfill('0') << setw(2) << tm->tm_mon + 1 << "/" <<
         setw(2) << tm->tm_mday << " alle ore " << setw(2) << tm->tm_hour << ":" << setw(2) << tm->tm_min << ":" <<
         setw(2) << tm->tm_sec << endl;
}
