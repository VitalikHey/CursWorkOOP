#ifndef CURSWORKOOP_CRYPTOCURRENCY_H
#define CURSWORKOOP_CRYPTOCURRENCY_H

#include <stdexcept>
#include <limits>
#include "../saving/saving.h"

class Cryptocurrency : public Saving {
private:
    double m_coins;
public:
    Cryptocurrency(const std::string& name, const double rateToDollar) {
        setName(name);
        setRateToDollar(rateToDollar);
        setTypeSaving("металл");
    }
    Cryptocurrency() : m_coins(0.0) {}

    double getCoins() const noexcept {
        return m_coins;
    }

    void setCoins(double newCoins) {
        if (newCoins < 0) {
            throw std::invalid_argument("Количество криптовалюты не может быть отрицательным.");
        }
        if (newCoins > std::numeric_limits<double>::max()) {
            throw std::overflow_error("Слишком большое значение для количества криптовалюты.");
        }
        m_coins = newCoins;
    }
};

#endif
