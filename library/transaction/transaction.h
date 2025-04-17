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
#include "../cryptocurrency/cryptocurrency.h"
#include "../currency/currency.h"

class Transaction {
private:
    std::map<std::string, Saving> m_currencies;

public:
    Transaction() = default;

    double conductTransaction(const std::variant<Metal, Cryptocurrency, Currency> &from,
                              const std::variant<Metal, Cryptocurrency, Currency> &to,
                              const Bank &bank) const;

    double conductCurrencyTransaction(const Currency &fromCurrency, const Currency &toCurrency,
                                      const Bank &bank) const;

    double conductMetalTransaction(const Metal &fromMetal, const Metal &toMetal,
                                   const Bank &bank) const;

    double
    conductCryptocurrencyTransaction(const Cryptocurrency &fromCryptocurrency, const Cryptocurrency &toCryptocurrency,
                                     const Bank &bank) const;
};

#endif
