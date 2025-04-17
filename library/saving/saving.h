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
    Saving();

    double getRateToDollar() const noexcept;

    std::string getName() const;

    std::string getTypeSaving() const;

    void setRateToDollar(double rate);

    void setName(const std::string &name);

    void setTypeSaving(const std::string &type);
};

#endif
