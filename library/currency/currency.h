#ifndef CURSWORKOOP_CURRENCY_H
#define CURSWORKOOP_CURRENCY_H

#include <string>
#include <limits>
#include "../saving/saving.h"

class Currency : public Saving {
private:
    double m_count;

public:
    Currency(const std::string& name, const double rateToDollar);
    Currency();

    double getCount() const noexcept;
    void setCount(double newCount);
};

#endif
