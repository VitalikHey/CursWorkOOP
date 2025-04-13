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
    Bank(const std::string& name, int commission, bool isWorkWithCrypto, bool isWorkWithMetal) :
            m_name(name),
            m_commission(commission),
            m_isWorkWithCrypto(isWorkWithCrypto),
            m_isWorkWithMetal(isWorkWithMetal) {
    }

    std::string getName() const {
        return m_name;
    }

    void setName(const std::string &newName) {
        m_name = newName;
    }

    int getCommission() const {
        return m_commission;
    }

    void setCommission(int newCommission) {
        m_commission = newCommission;
    }

    bool getIsWorkWithCrypto() const {
        return m_isWorkWithCrypto;
    }

    void setIsWorkWithCrypto(bool newIsWorkWithCrypto) {
        m_isWorkWithCrypto = newIsWorkWithCrypto;
    }

    bool getIsWorkWithMetal() const {
        return m_isWorkWithMetal;
    }

    void setIsWorkWithMetal(bool newIsWorkWithMetal) {
        m_isWorkWithMetal = newIsWorkWithMetal;
    }
};


#endif