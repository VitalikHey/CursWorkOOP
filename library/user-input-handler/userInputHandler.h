#ifndef CURSWORKOOP_USERINPUTHANDLER_H
#define CURSWORKOOP_USERINPUTHANDLER_H

#include <iostream>
#include <string>
#include <limits>
#include <stdexcept>
#include <algorithm>
#include "../saving/saving.h"
#include "../currency/currency.h"
#include "../metal/metal.h"


class UserInputHandler {
private:
    std::string m_typeSaving;
public:

    Bank selectBank(const std::vector<Bank> &banks) {
        while (true) {
            std::cout << "Выберите банк:" << std::endl;
            for (size_t i = 0; i < banks.size(); ++i) {
                std::cout << i + 1 << ". " << banks[i].getName() << std::endl;
            }
            std::cout << "Введите номер выбранного банка: ";

            std::string choice;
            std::getline(std::cin, choice);

            choice.erase(0, choice.find_first_not_of(' '));
            choice.erase(choice.find_last_not_of(' ') + 1);

            try {
                int option = std::stoi(choice);

                if (option >= 1 && option <= static_cast<int>(banks.size())) {
                    return banks[option - 1];
                } else {
                    std::cout << "Некорректный ввод. Пожалуйста, выберите номер от 1 до " << banks.size() << "."
                              << std::endl;
                }
            } catch (const std::invalid_argument &e) {
                std::cerr << "Ошибка: Некорректный ввод. Пожалуйста, введите число." << std::endl;
            } catch (const std::out_of_range &e) {
                std::cerr << "Ошибка: Введенное число слишком велико или мало." << std::endl;
            }
        }
    }

    std::string getSavingType() {
        while (true) {
            std::cout << "Выберите тип сбережения:" << std::endl;
            std::cout << "1. Валюта" << std::endl;
            std::cout << "2. Металл" << std::endl;
            std::cout << "3. Криптовалюта" << std::endl;
            std::cout << "Введите номер выбранного типа: ";

            std::string choice;
            std::getline(std::cin, choice);

            choice.erase(0, choice.find_first_not_of(' '));
            choice.erase(choice.find_last_not_of(' ') + 1);

            try {
                int option = std::stoi(choice);

                switch (option) {
                    case 1:
                        m_typeSaving = "валюта";
                        break;
                    case 2:
                        m_typeSaving = "металл";
                        break;
                    case 3:
                        m_typeSaving = "криптовалюта";
                        break;
                    default:
                        std::cout << "Некорректный ввод. Пожалуйста, выберите номер от 1 до 3." << std::endl;
                        continue;
                }
                break;

            } catch (const std::invalid_argument &e) {
                std::cerr << "Ошибка: Некорректный ввод. Пожалуйста, введите число." << std::endl;
            } catch (const std::out_of_range &e) {
                std::cerr << "Ошибка: Введенное число слишком велико или мало." << std::endl;
            }
        }

        std::transform(m_typeSaving.begin(), m_typeSaving.end(), m_typeSaving.begin(), ::tolower);

        std::cout << "Выбранный тип сбережения: " << m_typeSaving
                  << std::endl;
        return m_typeSaving;
    }

    Currency getCurrencyFromInputHandler(const std::vector<Currency> &currencies, const bool isFrom) {
        while (true) {
            std::cout << "Выберите валюту:" << std::endl;
            for (size_t i = 0; i < currencies.size(); ++i) {
                std::cout << i + 1 << ". " << currencies[i].getName() << std::endl;
            }
            std::cout << "Введите номер выбранной валюты: ";

            std::string choice;
            std::getline(std::cin, choice);

            choice.erase(0, choice.find_first_not_of(' '));
            choice.erase(choice.find_last_not_of(' ') + 1);

            try {
                int option = std::stoi(choice);

                if (option >= 1 && option <= static_cast<int>(currencies.size())) {
                    Currency selectCurrency = currencies[option - 1];
                    if (isFrom) {
                        std::cout << "Введите количество сбережений: ";
                        double amount;
                        std::cin >> amount;
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        try {
                            selectCurrency.setCount(amount);
                        }
                        catch (const std::invalid_argument &e) {
                            std::cerr << "Ошибка: " << e.what() << std::endl;
                            continue;
                        }
                    }
                    return selectCurrency;
                } else {
                    std::cout << "Некорректный ввод. Пожалуйста, выберите номер от 1 до " << currencies.size()
                              << "." << std::endl;
                }
            } catch (const std::invalid_argument &e) {
                std::cerr << "Ошибка: Некорректный ввод. Пожалуйста, введите число." << std::endl;
            } catch (const std::out_of_range &e) {
                std::cerr << "Ошибка: Введенное число слишком велико или мало." << std::endl;
            }
        }
    }

    Metal getMetalFromInputHandler(const std::vector<Metal> &metals, const bool isFrom) {
        while (true) {
            std::cout << "Выберите металл:" << std::endl;
            for (size_t i = 0; i < metals.size(); ++i) {
                std::cout << i + 1 << ". " << metals[i].getName() << std::endl;
            }
            std::cout << "Введите номер выбранного металла: ";

            std::string choice;
            std::getline(std::cin, choice);

            choice.erase(0, choice.find_first_not_of(' '));
            choice.erase(choice.find_last_not_of(' ') + 1);

            try {
                int option = std::stoi(choice);

                if (option >= 1 && option <= static_cast<int>(metals.size())) {
                    Metal selectMetal = metals[option - 1];
                    if (isFrom) {
                        std::cout << "Введите количество грамм: ";
                        double gram;
                        std::cin >> gram;
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        try {
                            selectMetal.setWeight(gram);
                        }
                        catch (const std::invalid_argument &e) {
                            std::cerr << "Ошибка: " << e.what() << std::endl;
                            continue;

                        }
                    }
                    return selectMetal;
                } else {
                    std::cout << "Некорректный ввод. Пожалуйста, выберите номер от 1 до " << metals.size()
                              << "." << std::endl;
                }
            } catch (const std::invalid_argument &e) {
                std::cerr << "Ошибка: Некорректный ввод. Пожалуйста, введите число." << std::endl;
            } catch (const std::out_of_range &e) {
                std::cerr << "Ошибка: Введенное число слишком велико или мало." << std::endl;
            }
        }
    }

    Cryptocurrency
    getCryptoCurrencyFromInputHandler(const std::vector<Cryptocurrency> &cryptocurrencies, const bool isFrom) {
        while (true) {
            std::cout << "Выберите криптовалюту:" << std::endl;
            for (size_t i = 0; i < cryptocurrencies.size(); ++i) {
                std::cout << i + 1 << ". " << cryptocurrencies[i].getName() << std::endl;
            }
            std::cout << "Введите номер выбранной криптовалюты: ";

            std::string choice;
            std::getline(std::cin, choice);

            choice.erase(0, choice.find_first_not_of(' '));
            choice.erase(choice.find_last_not_of(' ') + 1);

            try {
                int option = std::stoi(choice);

                if (option >= 1 && option <= static_cast<int>(cryptocurrencies.size())) {
                    Cryptocurrency selectCryptocurrency = cryptocurrencies[option - 1];
                    if (isFrom) {
                        std::cout << "Введите количество коинов: ";
                        double gram;
                        std::cin >> gram;
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        try {
                            selectCryptocurrency.setCoins(gram);
                        }
                        catch (const std::invalid_argument &e) {
                            std::cerr << "Ошибка: " << e.what() << std::endl;
                            continue;
                        }
                    }
                    return selectCryptocurrency;
                } else {
                    std::cout << "Некорректный ввод. Пожалуйста, выберите номер от 1 до " << cryptocurrencies.size()
                              << "." << std::endl;
                }
            } catch (const std::invalid_argument &e) {
                std::cerr << "Ошибка: Некорректный ввод. Пожалуйста, введите число." << std::endl;
            } catch (const std::out_of_range &e) {
                std::cerr << "Ошибка: Введенное число слишком велико или мало." << std::endl;
            }
        }
    }
};

#endif