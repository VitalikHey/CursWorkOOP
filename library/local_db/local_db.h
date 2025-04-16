#ifndef CURSWORKOOP_LOCAL_DB_H
#define CURSWORKOOP_LOCAL_DB_H

#include <vector>
#include <map>
#include "../bank/bank.h"
#include "../currency/currency.h"
#include "../cryptocurrency/cryptocurrency.h"
#include "../metal/metal.h"

struct LocalDatabase {
    std::vector<Bank> banks;
    std::vector<Currency> currencyMap;
    std::vector<Cryptocurrency> cryptocurrencyMap;
    std::vector<Metal> metalMap;
};

LocalDatabase initializeLocalDatabase();

#endif //CURSWORKOOP_LOCAL_DB_H
