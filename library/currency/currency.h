#ifndef CURSWORKOOP_CURRENCY_H
#define CURSWORKOOP_CURRENCY_H

#include "../saving/saving.h"

class Currency: public Saving {
    double count;
public:
    Currency();

    double getCount() const {
        return count;
    }

    static void setCount(double count) {
        count = count;
    }
};

#endif
