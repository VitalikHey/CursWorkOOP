#ifndef CURSWORKOOP_SAVING_H
#define CURSWORKOOP_SAVING_H

#include <string>

class Saving {
    double rateToDollar;
    std::string name;
    std::string typeSaving;
public:
    Saving();

    double getRateToDollar() const {
        return rateToDollar;
    };

    std::string getName() {
        return name;
    };

    std::string getTypeSaving() {
        return typeSaving;
    }
};

#endif
