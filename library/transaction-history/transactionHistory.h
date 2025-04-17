#ifndef CURSWORKOOP_TRANSACTIONHISTORY_H
#define CURSWORKOOP_TRANSACTIONHISTORY_H

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include "../transaction/transaction.h"
#include "../metal/metal.h"
#include "../currency/currency.h"
#include "../cryptocurrency/cryptocurrency.h"

class TransactionHistory {
private:
    std::vector<std::tuple<double, std::string, std::string, double>> m_transactions;

public:
    TransactionHistory() = default;

    void addTransaction(const std::variant<Metal, Cryptocurrency, Currency> &from,
                        const std::variant<Metal, Cryptocurrency, Currency> &to,
                        double result);

    const std::vector<std::tuple<double, std::string, std::string, double>> &getTransactionHistory() const;

    std::vector<std::tuple<double, std::string, std::string, double>>
    getTransactionsByFromCurrency(const std::string &currencyName) const;

    std::vector<std::tuple<double, std::string, std::string, double>>
    getTransactionsByToCurrency(const std::string &currencyName) const;
};

#endif
