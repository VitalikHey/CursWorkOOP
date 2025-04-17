#ifndef CURSWORKOOP_SAVING_H
#define CURSWORKOOP_SAVING_H

#include <string>
#include <stdexcept>

class Saving {
private:
    double m_rateToDollar;
    std::string m_name;
    std::string m_typeSaving;
public:
    Saving() : m_rateToDollar(0.0), m_name(""), m_typeSaving("") {}

    double getRateToDollar() const noexcept {
        return m_rateToDollar;
    }

    std::string getName() const {
        return m_name;
    }

    std::string getTypeSaving() const {
        return m_typeSaving;
    }

    void setRateToDollar(double rate) {
        if (rate < 0) {
            throw std::invalid_argument("Курс не может быть отрицательным");
        }
        m_rateToDollar = rate;
    }

    void setName(const std::string &name) {
        if (name.empty()) {
            throw std::invalid_argument("Имя не может быть пустым");
        }
        m_name = name;
    }

    void setTypeSaving(const std::string &type) {
        if (type.empty()) {
            throw std::invalid_argument("Тип не может быть пустым");
        }
        m_typeSaving = type;
    }
};

#endif
