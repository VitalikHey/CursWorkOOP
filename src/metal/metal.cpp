#include "../../library/metal/metal.h"
#include <stdexcept>

Metal::Metal(const std::string &name, const double rateToDollar) {
    setName(name);
    setRateToDollar(rateToDollar);
    setTypeSaving("металл");
}

Metal::Metal() : m_weight(0.0) {}

double Metal::getWeight() const noexcept {
    return m_weight;
}

void Metal::setWeight(double newWeight) {
    if (newWeight < 0) {
        throw std::invalid_argument("Вес металла не может быть отрицательным.");
    }
    if (newWeight > std::numeric_limits<double>::max()) {
        throw std::overflow_error("Слишком большое значение для веса металла.");
    }
    m_weight = newWeight;
}

