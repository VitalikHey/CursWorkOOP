#ifndef CURSWORKOOP_METAL_H
#define CURSWORKOOP_METAL_H

#include <stdexcept>
#include <limits>
#include "../saving/saving.h"

class Metal : public Saving {
private:
    double m_weight;
public:
    Metal() : m_weight(0.0) {};

    double getWeight() const noexcept {
        return m_weight;
    }

    void setWeight(double newWeight) {
        if (newWeight < 0) {
            throw std::invalid_argument("Вес металла не может быть отрицательным.");
        }
        if (newWeight > std::numeric_limits<double>::max()) {
            throw std::overflow_error("Слишком большое значение для веса металла.");
        }
        m_weight = newWeight;
    }
};

#endif
