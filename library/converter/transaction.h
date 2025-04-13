#ifndef CURSWORKOOP_TRANSACTION_H
#define CURSWORKOOP_TRANSACTION_H

#include <map>
#include <stdexcept>
#include <limits>
#include "../saving/saving.h"

class Transaction {
private:
    std::map<std::string, Saving> m_currencies;
    int m_rateToDollarSentSaving{};
    int m_rateToDollarReceivedSaving{};
    double m_resultTransaction{};
    double m_sentSaving{};
    double m_receivedSaving{};
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

    double conductTransaction(double amount, const std::string &fromCurrencyName, const std::string &toCurrencyName, const double commission) const {
        const Saving &fromCurrency = getCurrency(fromCurrencyName);
        const Saving &toCurrency = getCurrency(toCurrencyName);

        if (fromCurrency.getRateToDollar() == 0.0) {
            throw std::runtime_error("Невозможно конвертировать из валюты с нулевым курсом.");
        }

        if (toCurrency.getRateToDollar() == 0.0) {
            throw std::runtime_error("Невозможно конвертировать в валюту с нулевым курсом.");
        }

        double amountInDollars = amount * fromCurrency.getRateToDollar();

        // Вычисляем комиссию
        double fee = amountInDollars * commission;

        // Вычитаем комиссию из суммы в долларах
        amountInDollars -= fee;


        return amountInDollars / toCurrency.getRateToDollar();
    }

    void updateRate(const std::string &currencyName, double newRate) {
        Saving &currency = m_currencies.at(currencyName);
        currency.setRateToDollar(newRate);
    }
};

#endif
