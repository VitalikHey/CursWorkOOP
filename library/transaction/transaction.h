#ifndef CURSWORKOOP_TRANSACTION_H
#define CURSWORKOOP_TRANSACTION_H

#include <map>
#include <stdexcept>
#include <limits>
#include <variant>
#include "../saving/saving.h"
#include "../bank/bank.h"
#include "../transaction-history/transactionHistory.h"
#include "../metal/metal.h"

class Transaction {
    std::map<std::string, Saving> m_currencies;
public:
    Transaction() = default;

    double conductTransaction(const std::variant<Metal, Cryptocurrency, Currency>& from,
                              const std::variant<Metal, Cryptocurrency, Currency>& to,
                              const Bank& bank) const {
        return std::visit([&](auto&& arg_from, auto&& arg_to) -> double {
            using FromType = std::decay_t<decltype(arg_from)>;
            using ToType = std::decay_t<decltype(arg_to)>;

            if constexpr (std::is_same_v<FromType, Currency> && std::is_same_v<ToType, Currency>) {
                return conductCurrencyTransaction(arg_from, arg_to, bank);
            }
            else if constexpr (std::is_same_v<FromType, Cryptocurrency> && std::is_same_v<ToType, Cryptocurrency>){
                return conductCryptocurrencyTransaction(arg_from, arg_to, bank);
            }

            else if constexpr (std::is_same_v<FromType, Metal> && std::is_same_v<ToType, Metal>){
                return conductMetalTransaction(arg_from, arg_to, bank);
            }
            else {
                throw std::runtime_error("Транзакции между разными типами активов не поддерживаются.");
            }
        }, from, to);
    }

    double conductCurrencyTransaction(const Currency &fromCurrency, const Currency &toCurrency,
                                      const Bank &bank) const {
        if (fromCurrency.getRateToDollar() == 0.0 || toCurrency.getRateToDollar() == 0.0) {
            throw std::runtime_error("Невозможно конвертировать из валюты с нулевым курсом.");
        }

        double amountInDollars = fromCurrency.getCount() * fromCurrency.getRateToDollar();
        double fee =
                amountInDollars * (bank.getCommission() / 100.0);

        amountInDollars -= fee;

        return amountInDollars / toCurrency.getRateToDollar();
    }

    double conductMetalTransaction(const Metal &fromMetal, const Metal &toMetal,
                                   const Bank &bank) const {
        if ((fromMetal.getTypeSaving() == "металл" || toMetal.getTypeSaving() == "металл") &&
            !bank.getIsWorkWithMetal()) {
            throw std::runtime_error("Выбранный банк не работает с металлами.");
        }

        if (fromMetal.getRateToDollar() == 0.0 || toMetal.getRateToDollar() == 0.0) {
            throw std::runtime_error("Невозможно конвертировать из валюты с нулевым курсом.");
        }

        double amountInDollars = fromMetal.getWeight() * fromMetal.getRateToDollar();
        double fee =
                amountInDollars * (bank.getCommission() / 100.0);

        amountInDollars -= fee;

        return amountInDollars / toMetal.getRateToDollar();
    }

    double
    conductCryptocurrencyTransaction(const Cryptocurrency &fromCryptocurrency, const Cryptocurrency &toCryptocurrency,
                                     const Bank &bank) const {
        if ((fromCryptocurrency.getTypeSaving() == "криптовалюта" || toCryptocurrency.getTypeSaving() == "криптовалюта") &&
            !bank.getIsWorkWithCrypto()) {
            throw std::runtime_error("Выбранный банк не работает с криптовалютой.");
        }

        if (fromCryptocurrency.getRateToDollar() == 0.0 || toCryptocurrency.getRateToDollar() == 0.0) {
            throw std::runtime_error("Невозможно конвертировать из криптовалюты с нулевым курсом.");
        }

        double amountInDollars = fromCryptocurrency.getCoins() * fromCryptocurrency.getRateToDollar();
        double fee =
                amountInDollars * (bank.getCommission() / 100.0);

        amountInDollars -= fee;

        return amountInDollars / toCryptocurrency.getRateToDollar();
    }
};

#endif
