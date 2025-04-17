#ifndef CURSWORKOOP_METAL_H
#define CURSWORKOOP_METAL_H

#include <stdexcept>
#include <limits>
#include "../saving/saving.h"

class Metal : public Saving {
private:
    double m_weight;

public:
    Metal(const std::string &name, const double rateToDollar);

    Metal();

    double getWeight() const noexcept;

    void setWeight(double newWeight);
};

#endif
