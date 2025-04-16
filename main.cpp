#include <iostream>
#include <string>
#include "library/cryptocurrency/cryptocurrency.h"
#include "library/currency/currency.h"
#include "library/transaction/transaction.h"
#include "library/user-input-handler/userInputHandler.h"
#include <windows.h>

int main() {
    SetConsoleOutputCP(CP_UTF8);
    Transaction transaction;
    UserInputHandler handler;

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

    Currency usd;
    usd.setName("USD");
    usd.setRateToDollar(1.0);

    Currency eur;
    eur.setName("EUR");
    eur.setRateToDollar(1.14);

    Currency rub;
    usd.setName("RUB");
    usd.setRateToDollar(0.012);

    Currency cny;
    eur.setName("CNY");
    eur.setRateToDollar(0.14);

    Currency kzt;
    usd.setName("KZT");
    usd.setRateToDollar(0.0019);

    Currency lir;
    eur.setName("LIR");
    eur.setRateToDollar(0.026);

    Cryptocurrency bitcoin;
    bitcoin.setName("Bitcoin");
    bitcoin.setRateToDollar(83464.11);

    Cryptocurrency ethereum;
    ethereum.setName("Ethereum");
    ethereum.setRateToDollar(1567.69);

    Cryptocurrency tether;
    tether.setName("Tether");
    tether.setRateToDollar(1.0);

    Cryptocurrency xrp;
    xrp.setName("XRP");
    xrp.setRateToDollar(2.06);

    Cryptocurrency bnb;
    bnb.setName("BNB");
    bnb.setRateToDollar(578.81);

    Metal gold;
    gold.setName("Золото");
    gold.setRateToDollar(89.337);

    Metal silver;
    gold.setName("Серебро");
    gold.setRateToDollar(1.05);

    Metal platinum;
    gold.setName("Платина");
    gold.setRateToDollar(30.567);

    std::vector<Bank> banks = {alphaBank, sberBank, metallinvestbank, gazpromBank, Rosselkhozbank, mtsbank, opened,
                               rosbank, youmoney, psb};

    std::vector<Currency> currency = {rub, usd, eur, lir, kzt, cny};

    std::vector<Cryptocurrency> cryptocurrency = {bitcoin, ethereum, tether, xrp, bnb};

    std::vector<Metal> metals = {gold, silver, platinum};

    Bank selectedBank = handler.selectBank(banks);

    std::string typeSaving = handler.getSavingType();

    Currency fromCurrency = handler.getItemFromInput<Currency>(metals, currency, cryptocurrency);

    std::cout << fromCurrency.getName() << std::endl;
    std::cout << fromCurrency.getCount() << std::endl;
    std::cout << fromCurrency.getRateToDollar() << std::endl;
    std::cout << fromCurrency.getTypeSaving() << std::endl;


    Currency toCurrency = handler.getItemToInput<Currency>(metals, currency, cryptocurrency);

    // Неправильно считает
    std::cout << transaction.conductCurrencyTransaction(fromCurrency, toCurrency, selectedBank)
              << std::endl;
    return 0;
}