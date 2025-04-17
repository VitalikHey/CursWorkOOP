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

    void addTransaction(const std::variant<Metal, Cryptocurrency, Currency>& from,
                        const std::variant<Metal, Cryptocurrency, Currency>& to,
                        double result) {

        std::string fromAssetName, toAssetName;

        std::visit([&](auto&& arg){
            fromAssetName = arg.getName();
        },from);

        std::visit([&](auto&& arg){
            toAssetName = arg.getName();
        },to);

        double amount = 0.0;

        if (std::holds_alternative<Currency>(from)) {
            amount = std::get<Currency>(from).getCount();
        } else if (std::holds_alternative<Cryptocurrency>(from)) {
            amount = std::get<Cryptocurrency>(from).getCoins();
        } else if (std::holds_alternative<Metal>(from)) {
            amount = std::get<Metal>(from).getWeight();
        } else {
            throw std::runtime_error("Unexpected type in 'from' variant.");
        }
        m_transactions.emplace_back(amount, fromAssetName, toAssetName, result);
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
        const auto &transactions = getTransactionHistory();

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
