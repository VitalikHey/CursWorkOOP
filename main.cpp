#include <iostream>
#include "library/cryptocurrency/cryptocurrency.h"
#include "library/currency/currency.h"
#include "library/converter/transaction.h"

int main() {
    Transaction converter;

    Currency usd;
    usd.setName("USD");
    usd.setRateToDollar(1.0);

    Currency eur;
    eur.setName("EUR");
    eur.setRateToDollar(1.10);

    Currency rub;
    rub.setName("RUB");
    rub.setRateToDollar(0.011);

    converter.addCurrency(usd);
    converter.addCurrency(eur);
    converter.addCurrency(rub);

    try {
        double dollars = converter.conductTransaction(91, "RUB", "USD", 0.05);
        std::cout << "91 RUB = " << dollars << " USD" << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }

    return 0;
}
