#ifndef CURSWORKOOP_CRYPTOCURRENCY_H
#define CURSWORKOOP_CRYPTOCURRENCY_H

#include "../saving/saving.h"

class Cryptocurrency: Saving {
    double coins;
public:
    Cryptocurrency();


    double getCoins() const {
        return coins;
    }

    static void setCoins(double coins) {
        coins = coins;
    }

};

#endif
