#include "../../library/bank/bank.h"

Bank::Bank(const std::string &name, int commission, bool isWorkWithCrypto, bool isWorkWithMetal) :
        m_name(name),
        m_commission(commission),
        m_isWorkWithCrypto(isWorkWithCrypto),
        m_isWorkWithMetal(isWorkWithMetal) {
}

std::string Bank::getName() const {
    return m_name;
}

void Bank::setName(const std::string &newName) {
    m_name = newName;
}

int Bank::getCommission() const {
    return m_commission;
}

void Bank::setCommission(int newCommission) {
    m_commission = newCommission;
}

bool Bank::getIsWorkWithCrypto() const {
    return m_isWorkWithCrypto;
}

void Bank::setIsWorkWithCrypto(bool newIsWorkWithCrypto) {
    m_isWorkWithCrypto = newIsWorkWithCrypto;
}

bool Bank::getIsWorkWithMetal() const {
    return m_isWorkWithMetal;
}

void Bank::setIsWorkWithMetal(bool newIsWorkWithMetal) {
    m_isWorkWithMetal = newIsWorkWithMetal;
}

