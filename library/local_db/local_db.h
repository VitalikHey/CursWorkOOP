#ifndef CURSWORKOOP_LOCAL_DB_H
#define CURSWORKOOP_LOCAL_DB_H

#include <vector>
#include <map>
#include <mutex>
#include <iostream>
#include "../bank/bank.h"
#include "../currency/currency.h"
#include "../cryptocurrency/cryptocurrency.h"
#include "../metal/metal.h"

struct LocalDatabase {
private:
    LocalDatabase();

    LocalDatabase(const LocalDatabase &) = delete;

    LocalDatabase &operator=(const LocalDatabase &) = delete;

    static LocalDatabase *instance;
    static std::mutex mutex;

    void initializeData();

public:
    std::vector<Bank> banks;
    std::vector<Currency> currencyMap;
    std::vector<Cryptocurrency> cryptocurrencyMap;
    std::vector<Metal> metalMap;

    static LocalDatabase *getInstance();

    ~LocalDatabase();

    static void destroyInstance();
};

#endif
