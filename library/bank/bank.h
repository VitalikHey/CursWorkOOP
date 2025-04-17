#ifndef CURSWORKOOP_BANK_H
#define CURSWORKOOP_BANK_H

#include <string>

class Bank {
private:
    std::string m_name;
    int m_commission;
    bool m_isWorkWithCrypto;
    bool m_isWorkWithMetal;

public:
    Bank(const std::string& name, int commission, bool isWorkWithCrypto, bool isWorkWithMetal);

    std::string getName() const;
    void setName(const std::string &newName);

    int getCommission() const;
    void setCommission(int newCommission);

    bool getIsWorkWithCrypto() const;
    void setIsWorkWithCrypto(bool newIsWorkWithCrypto);

    bool getIsWorkWithMetal() const;
    void setIsWorkWithMetal(bool newIsWorkWithMetal);
};

#endif