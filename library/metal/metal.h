#ifndef CURSWORKOOP_METAL_H
#define CURSWORKOOP_METAL_H

#include "../saving/saving.h"

class Metal: public Saving {
    double weight;
public:
    Metal();

    double getWeight() const {
        return weight;
    }

    static void setWeight(double weight) {
        weight = weight;
    }
};

#endif
