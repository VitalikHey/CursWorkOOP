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

    double conductCurrencyTransaction(const Currency &fromCurrency, const Currency &toCurrency,
                                      const Bank &bank) const {

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

        // Тут может ошибка в вычислениях

        double amountInDollars = fromCurrency.getCount() * fromCurrency.getRateToDollar();
        double fee =
                amountInDollars * (bank.getCommission() / 100.0);


        amountInDollars -= fee;

        return amountInDollars / toCurrency.getRateToDollar();
    }
};

#endif
