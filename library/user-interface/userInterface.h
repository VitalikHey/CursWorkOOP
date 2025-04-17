#ifndef CURSWORKOOP_USERINTERFACE_H
#define CURSWORKOOP_USERINTERFACE_H

#include "../transaction/transaction.h"
#include "../user-input-handler/userInputHandler.h"
#include "../local_db/local_db.h"
#include <windows.h>

class UserInterface {
private:
    Transaction transaction;
    TransactionHistory transactionHistory;
    UserInputHandler handler;
    LocalDatabase* database;

public:
    UserInterface();
    void run();
    void printTransactionHistory();
};


#endif
