#ifndef CURSWORKOOP_TRANSACTIONHISTORY_H
#define CURSWORKOOP_TRANSACTIONHISTORY_H

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include "../transaction/transaction.h"

class TransactionHistory {
private:
    std::vector<std::tuple<double, std::string, std::string, double>> m_transactions; //amount, fromCurrency, toCurrency, result
public:
    TransactionHistory() = default;

    void addTransaction(double amount, const std::string &fromCurrencyName, const std::string &toCurrencyName,
                        double result) {
        m_transactions.emplace_back(amount, fromCurrencyName, toCurrencyName, result);
    }

    const std::vector<std::tuple<double, std::string, std::string, double>> &getTransactionHistory() const {
        return m_transactions;
    }

    std::vector<std::tuple<double, std::string, std::string, double>>
    getTransactionsByFromCurrency(const std::string &currencyName) const {
        std::vector<std::tuple<double, std::string, std::string, double>> result;
        for (const auto &transaction: m_transactions) {
            if (std::get<1>(transaction) == currencyName) {
                result.push_back(transaction);
            }
        }
        return result;
    }

    std::vector<std::tuple<double, std::string, std::string, double>>
    getTransactionsByToCurrency(const std::string &currencyName) const {
        std::vector<std::tuple<double, std::string, std::string, double>> result;
        for (const auto &transaction: m_transactions) {
            if (std::get<2>(transaction) == currencyName) {
                result.push_back(transaction);
            }
        }
        return result;
    }

    void printTransactionHistory() const {
        const auto &transactions = getTransactionHistory(); // Используем getTransactionHistory()

        if (transactions.empty()) {
            std::cout << "История транзакций пуста." << std::endl;
            return;
        }

        std::cout << "----------------------------------------------------------------------" << std::endl;
        std::cout << "|   Сумма   |   Из валюты   |   В валюту   |   Результат   |" << std::endl;
        std::cout << "----------------------------------------------------------------------" << std::endl;

        for (const auto &transaction: transactions) {
            double amount = std::get<0>(transaction);
            std::string fromCurrency = std::get<1>(transaction);
            std::string toCurrency = std::get<2>(transaction);
            double result = std::get<3>(transaction);

            std::cout << "| " << std::fixed << std::setprecision(2) << std::setw(9) << amount << " ";
            std::cout << "| " << std::setw(15) << fromCurrency << " ";
            std::cout << "| " << std::setw(13) << toCurrency << " ";
            std::cout << "| " << std::fixed << std::setprecision(2) << std::setw(11) << result << " |" << std::endl;
        }

        std::cout << "----------------------------------------------------------------------" << std::endl;
    }

};

#endif
