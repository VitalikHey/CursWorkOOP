#include <stdexcept>
#include "../../library/saving/saving.h"

Saving::Saving() : m_rateToDollar(0.0), m_name(""), m_typeSaving("") {}

double Saving::getRateToDollar() const noexcept {
    return m_rateToDollar;
}

std::string Saving::getName() const {
    return m_name;
}

std::string Saving::getTypeSaving() const {
    return m_typeSaving;
}

void Saving::setRateToDollar(double rate) {
    if (rate < 0) {
        throw std::invalid_argument("Курс не может быть отрицательным");
    }
    m_rateToDollar = rate;
}

void Saving::setName(const std::string &name) {
    if (name.empty()) {
        throw std::invalid_argument("Имя не может быть пустым");
    }
    m_name = name;
}

void Saving::setTypeSaving(const std::string &type) {
    if (type.empty()) {
        throw std::invalid_argument("Тип не может быть пустым");
    }
    m_typeSaving = type;
}

