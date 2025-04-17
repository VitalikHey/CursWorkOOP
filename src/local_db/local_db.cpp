#include "../../library/local_db/local_db.h"
#include <iostream>

LocalDatabase *LocalDatabase::instance = nullptr;
std::mutex LocalDatabase::mutex;

LocalDatabase::LocalDatabase() {
    initializeData();
}

void LocalDatabase::initializeData() {
    Bank alphaBank("Альфа Банк", 2, true, false);
    Bank sberBank("Сбербанк", 7, true, true);
    Bank metallinvestbank("МЕТАЛЛИНВЕСТБАНК", 5, false, true);
    Bank gazpromBank("Газпромбанк", 4, false, true);
    Bank Rosselkhozbank("Россельхозбанк", 5, false, true);
    Bank mtsbank("МТС банк", 6, true, false);
    Bank opened("Открытие", 5, false, false);
    Bank rosbank("Росбанк", 7, false, true);
    Bank youmoney("IO money", 3, true, false);
    Bank psb("Промсвязьбанк", 8, false, true);

    Currency usd("USD", 1.0);
    Currency eur("EUR", 1.14);
    Currency rub("RUB", 0.012);
    Currency cny("CNY", 0.14);
    Currency kzt("KZT", 0.0019);
    Currency lir("LIR", 0.026);
    Currency aed("AED", 0.36);
    Currency usz("USZ", 0.00007);
    Currency jpy("JPY", 0.007);
    Currency thb("THB", 0.03);
    Currency gel("GEL", 0.36);
    Currency gbp("GBP", 1.32);

    Cryptocurrency bitcoin("Bitcoin", 83464.11);
    Cryptocurrency ethereum("Ethereum", 1567.69);
    Cryptocurrency tether("Tether", 1.0);
    Cryptocurrency xrp("XRP", 2.06);
    Cryptocurrency bnb("BNB", 578.81);

    Metal gold("Золото", 89.337);
    Metal silver("Серебро", 1.05);
    Metal platinum("Платина", 30.567);

    banks = {alphaBank, sberBank, metallinvestbank, gazpromBank, Rosselkhozbank, mtsbank, opened, rosbank, youmoney,
             psb};

    currencyMap = {
            usd,
            eur,
            rub,
            cny,
            kzt,
            lir,
            aed,
            usz,
            jpy,
            thb,
            gel,
            gbp
    };

    cryptocurrencyMap = {
            bitcoin,
            ethereum, tether, xrp, bnb
    };

    metalMap = {
            gold,
            silver,
            platinum
    };
}

LocalDatabase *LocalDatabase::getInstance() {
    std::lock_guard<std::mutex> lock(mutex);
    if (instance == nullptr) {
        instance = new LocalDatabase();
    }
    return instance;
}

LocalDatabase::~LocalDatabase() {
    std::cout << "LocalDatabase destructed" << std::endl;
}

void LocalDatabase::destroyInstance() {
    delete instance;
    instance = nullptr;
}
