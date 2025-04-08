#include <iostream>
#include "library/cryptocurrency/cryptocurrency.h"
#include "library/currency/currency.h"
#include "library/converter/converter.h"

int main() {
    Converter converter;

    Currency usd;
    usd.setName("USD");
    usd.setRateToDollar(1.0);

    Currency eur;
    eur.setName("EUR");
    eur.setRateToDollar(1.10);

    Currency rub;
    rub.setName("RUB");
    rub.setRateToDollar(0.013);

    converter.addCurrency(usd);
    converter.addCurrency(eur);
    converter.addCurrency(rub);

    try {
        double dollars = converter.convert(100.0, "EUR", "USD");
        std::cout << "100 EUR = " << dollars << " USD" << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }

    return 0;
}
