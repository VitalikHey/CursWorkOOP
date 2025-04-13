#include <iostream>
#include <string>
#include "library/cryptocurrency/cryptocurrency.h"
#include "library/currency/currency.h"
#include "library/transaction/transaction.h"
#include <windows.h>

int main() {
    SetConsoleOutputCP(CP_UTF8);

    Transaction converter;
    TransactionHistory transactionHistory;

    Currency usd;
    usd.setName("USD");
    usd.setRateToDollar(1.0);

    Currency eur;
    eur.setName("EUR");
    eur.setRateToDollar(1.10);

    Currency rub;
    rub.setName("RUB");
    rub.setRateToDollar(0.011);

    Bank alfaBank("AlfaBank", 5, false, true);

    converter.addCurrency(usd);
    converter.addCurrency(eur);
    converter.addCurrency(rub);

    try {
        double dollars = converter.conductTransaction(91, rub.getName(), usd.getName(), alfaBank);
        double dollars1 = converter.conductTransaction(3, eur.getName(), usd.getName(), alfaBank);
        double dollars2 = converter.conductTransaction(12241, usd.getName(), usd.getName(), alfaBank);
        transactionHistory.addTransaction(91, eur.getName(), usd.getName(), dollars1);
        transactionHistory.addTransaction(3, rub.getName(), usd.getName(), dollars);
        transactionHistory.addTransaction(12241, usd.getName(), usd.getName(), dollars2);

        transactionHistory.printTransactionHistory();
    } catch (const std::exception &e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }

    return 0;
}