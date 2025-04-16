#include <iostream>
#include <string>
#include "../library/cryptocurrency/cryptocurrency.h"
#include "../library/currency/currency.h"
#include "../library/transaction/transaction.h"
#include "../library/user-input-handler/userInputHandler.h"
#include "../library/local_db/local_db.h"
#include <windows.h>
#include <variant>

int main() {
    SetConsoleOutputCP(CP_UTF8);
    Transaction transaction;
    UserInputHandler handler;

    LocalDatabase database = initializeLocalDatabase();

    Bank selectedBank = handler.selectBank(database.banks);

    std::variant<Metal, Cryptocurrency, Currency> from, to;

    std::string fromTypeSaving = handler.getSavingType();

    if (fromTypeSaving == "металл") {
        from = handler.getMetalFromInputHandler(database.metalMap, true);
    } else if (fromTypeSaving == "криптовалюта") {
        from = handler.getCryptoCurrencyFromInputHandler(database.cryptocurrencyMap, true);
    } else if (fromTypeSaving == "валюта") {
        from = handler.getCurrencyFromInputHandler(database.currencyMap, true);
    } else {
        std::cout << "Неизвестный тип сбережения (from)." << std::endl;
        return 1;
    }

    if (fromTypeSaving == "металл") {
        to = handler.getMetalFromInputHandler(database.metalMap, false);
    } else if (fromTypeSaving == "криптовалюта") {
        to = handler.getCryptoCurrencyFromInputHandler(database.cryptocurrencyMap, false);
    } else if (fromTypeSaving == "валюта") {
        to = handler.getCurrencyFromInputHandler(database.currencyMap, false);
    } else {
        std::cout << "Неизвестный тип сбережения (to)." << std::endl;
        return 1;
    }

    double result = transaction.conductTransaction(from, to, selectedBank);

    std::cout << result;

    return 0;
}
