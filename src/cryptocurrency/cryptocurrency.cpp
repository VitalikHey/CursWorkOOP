#include <stdexcept>
#include "../../library/cryptocurrency/cryptocurrency.h"

Cryptocurrency::Cryptocurrency(const std::string& name, const double rateToDollar) {
    setName(name);
    setRateToDollar(rateToDollar);
    setTypeSaving("криптовалюта");
}

Cryptocurrency::Cryptocurrency() : m_coins(0.0) {}

double Cryptocurrency::getCoins() const noexcept {
    return m_coins;
}

void Cryptocurrency::setCoins(double newCoins) {
    if (newCoins < 0) {
        throw std::invalid_argument("Количество криптовалюты не может быть отрицательным.");
    }
    if (newCoins > std::numeric_limits<double>::max()) {
        throw std::overflow_error("Слишком большое значение для количества криптовалюты.");
    }
    m_coins = newCoins;
}

