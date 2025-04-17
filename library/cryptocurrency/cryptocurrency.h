#ifndef CURSWORKOOP_CRYPTOCURRENCY_H
#define CURSWORKOOP_CRYPTOCURRENCY_H

#include <string>
#include <limits>
#include "../saving/saving.h"

class Cryptocurrency : public Saving {
private:
    double m_coins;

public:
    Cryptocurrency(const std::string& name, const double rateToDollar);
    Cryptocurrency();

    double getCoins() const noexcept;
    void setCoins(double newCoins);
};

#endif
