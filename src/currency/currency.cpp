#include <stdexcept>
#include "../../library/currency/currency.h"

Currency::Currency(const std::string &name, const double rateToDollar) {
    setName(name);
    setRateToDollar(rateToDollar);
}

Currency::Currency() : m_count(0.0) {}

double Currency::getCount() const noexcept {
    return m_count;
}

void Currency::setCount(double newCount) {
    if (newCount < 0) {
        throw std::invalid_argument("Количество валюты не может быть отрицательным.");
    }
    if (newCount > std::numeric_limits<double>::max()) {
        throw std::overflow_error("Слишком большое значение для количества валюты.");
    }
    m_count = newCount;
}

