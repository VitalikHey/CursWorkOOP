#include "../../library/transaction-history/transactionHistory.h"
#include <stdexcept>
#include <iostream>
#include <iomanip>

void TransactionHistory::addTransaction(const std::variant<Metal, Cryptocurrency, Currency> &from,
                                        const std::variant<Metal, Cryptocurrency, Currency> &to,
                                        double result) {

    std::string fromAssetName, toAssetName;

    std::visit([&](auto &&arg) {
        fromAssetName = arg.getName();
    }, from);

    std::visit([&](auto &&arg) {
        toAssetName = arg.getName();
    }, to);

    double amount = 0.0;

    if (std::holds_alternative<Currency>(from)) {
        amount = std::get<Currency>(from).getCount();
    } else if (std::holds_alternative<Cryptocurrency>(from)) {
        amount = std::get<Cryptocurrency>(from).getCoins();
    } else if (std::holds_alternative<Metal>(from)) {
        amount = std::get<Metal>(from).getWeight();
    } else {
        throw std::runtime_error("Неподдерживаемый тип сбережения");
    }
    m_transactions.emplace_back(amount, fromAssetName, toAssetName, result);
}

const std::vector<std::tuple<double, std::string, std::string, double>> &
TransactionHistory::getTransactionHistory() const {
    return m_transactions;
}

std::vector<std::tuple<double, std::string, std::string, double>>
TransactionHistory::getTransactionsByFromCurrency(const std::string &currencyName) const {
    std::vector<std::tuple<double, std::string, std::string, double>> result;
    for (const auto &transaction: m_transactions) {
        if (std::get<1>(transaction) == currencyName) {
            result.push_back(transaction);
        }
    }
    return result;
}

std::vector<std::tuple<double, std::string, std::string, double>>
TransactionHistory::getTransactionsByToCurrency(const std::string &currencyName) const {
    std::vector<std::tuple<double, std::string, std::string, double>> result;
    for (const auto &transaction: m_transactions) {
        if (std::get<2>(transaction) == currencyName) {
            result.push_back(transaction);
        }
    }
    return result;
}

