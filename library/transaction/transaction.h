#ifndef CURSWORKOOP_TRANSACTION_H
#define CURSWORKOOP_TRANSACTION_H

#include <map>
#include <stdexcept>
#include <limits>
#include "../saving/saving.h"
#include "../bank/bank.h"
#include "../transaction-history/transactionHistory.h"

class Transaction {
    std::map<std::string, Saving> m_currencies;
public:
    Transaction() = default;

    void addCurrency(const Saving &currency) {
        if (m_currencies.count(currency.getName()) > 0) {
            throw std::invalid_argument("Валюта с таким именем уже существует.");
        }
        m_currencies[currency.getName()] = currency;
    }

    const Saving &getCurrency(const std::string &name) const {
        auto it = m_currencies.find(name);
        if (it == m_currencies.end()) {
            throw std::invalid_argument("Валюта с таким именем не найдена.");
        }
        return it->second;
    }

    double conductTransaction(double amount, const std::string &fromCurrencyName, const std::string &toCurrencyName,
                              const Bank &bank) const {
        const Saving &fromCurrency = getCurrency(fromCurrencyName);
        const Saving &toCurrency = getCurrency(toCurrencyName);

        if ((fromCurrency.getTypeSaving() == "CryptoCurrency" || toCurrency.getTypeSaving() == "CryptoCurrency") &&
            !bank.getIsWorkWithCrypto()) {
            throw std::runtime_error("Выбранный банк не работает с криптовалютой.");
        }

        if ((fromCurrency.getTypeSaving() == "Metal" || toCurrency.getTypeSaving() == "Metal") &&
            !bank.getIsWorkWithMetal()) {
            throw std::runtime_error("Выбранный банк не работает с металлами.");
        }

        if (fromCurrency.getRateToDollar() == 0.0) {
            throw std::runtime_error("Невозможно конвертировать из валюты с нулевым курсом.");
        }

        if (toCurrency.getRateToDollar() == 0.0) {
            throw std::runtime_error("Невозможно конвертировать в валюту с нулевым курсом.");
        }

        double amountInDollars = amount * fromCurrency.getRateToDollar();
        double fee =
                amountInDollars * (bank.getCommission() / 100.0);

        amountInDollars -= fee;

        return amountInDollars / toCurrency.getRateToDollar();
    }
};


#endif
