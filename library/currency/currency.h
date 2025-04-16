#ifndef CURSWORKOOP_CURRENCY_H
#define CURSWORKOOP_CURRENCY_H

#include "../saving/saving.h"
#include <limits>
#include <stdexcept>

class Currency : public Saving {
private:
    double m_count{};

public:
    Currency(const std::string& name, const double rateToDollar) {
        setName(name);
        setRateToDollar(rateToDollar);
    }
    Currency() : m_count(0.0) {}

    double getCount() const noexcept {
        return m_count;
    }

    void setCount(double newCount) {
        if (newCount < 0) {
            throw std::invalid_argument("Количество валюты не может быть отрицательным.");
        }
        if (newCount > std::numeric_limits<double>::max()) {
            throw std::overflow_error("Слишком большое значение для количества валюты.");
        }
        m_count = newCount;
    }
};

#endif
