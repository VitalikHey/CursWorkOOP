#ifndef CURSWORKOOP_USERINPUTHANDLER_H
#define CURSWORKOOP_USERINPUTHANDLER_H

#include <iostream>
#include <string>
#include <limits>
#include <stdexcept>
#include <algorithm>
#include "../saving/saving.h"
#include "../currency/currency.h"
#include "../metal/metal.h"
#include "../bank/bank.h"
#include "../cryptocurrency/cryptocurrency.h"
#include <vector>

class UserInputHandler {
private:
    std::string m_typeSaving;
public:
    Bank selectBank(const std::vector<Bank> &banks);

    std::string getSavingType();

    Currency getCurrencyFromInputHandler(const std::vector<Currency> &currencies, bool isFrom);

    Metal getMetalFromInputHandler(const std::vector<Metal> &metals, bool isFrom);

    Cryptocurrency getCryptoCurrencyFromInputHandler(const std::vector<Cryptocurrency> &cryptocurrencies, bool isFrom);
};

#endif