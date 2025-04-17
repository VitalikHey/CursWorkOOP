#include <iostream>
#include <vector>
#include "../../library/test/test.h"

    bool ConverterTest::test() {
    Transaction transaction;

    Bank testBank1("Тестовый банк 1", 5, true, true);
    Bank testBank2("Тестовый банк 2", 5, true, true);

    Currency testCurrency1("Тестовая валюта 1", 1.0);
    Currency testCurrency2("Тестовая валюта 2", 1.0);

    Cryptocurrency testCryptocurrency1("Тестовая криптовалюта 1", 2.0);
    Cryptocurrency testCryptocurrency2("Тестовая криптовалюта 2", 2.0);

    Metal testMetal1("Тестовый метал 1", 89.337);
    Metal testMetal2("Тестовый метал 2", 89.337);

    testCurrency1.setCount(1);
    testMetal1.setWeight(1);
    testCryptocurrency1.setCoins(1);

    std::vector<Bank> testBanks = {testBank1, testBank2};
    std::vector<Currency> testCurrencyMap = {testCurrency1, testCurrency2};
    std::vector<Cryptocurrency> testCryptocurrencyMap = {testCryptocurrency1, testCryptocurrency2};
    std::vector<Metal> testMetalMap = {testMetal1, testMetal2};

    try {
        try {
            transaction.conductMetalTransaction(testMetal1, testMetal2, testBank1);
        } catch (const std::exception &e) {
            std::cerr << "Ошибка при проведении транзакций с металлами: " << e.what() << std::endl;
        }

        try {
            transaction.conductCurrencyTransaction(testCurrency1, testCurrency2, testBank1);
        } catch (const std::exception &e) {
            std::cerr << "Ошибка при проведении транзакций с валютой: " << e.what() << std::endl;
        }

        try {
            transaction.conductCryptocurrencyTransaction(testCryptocurrency1, testCryptocurrency1, testBank1);
        } catch (const std::exception &e) {
            std::cerr << "Ошибка при проведении транзакций с криптовалютой: " << e.what() << std::endl;
        }
    } catch (const std::exception &e) {
        return false;
    }
    return true;
}
