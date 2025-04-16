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

            // Убираем пробелы в начале и конце строки.
            choice.erase(0, choice.find_first_not_of(' '));
            choice.erase(choice.find_last_not_of(' ') + 1);


            try {
                int option = std::stoi(choice);

                if (option >= 1 && option <= static_cast<int>(banks.size())) {
                    return banks[option - 1]; // Возвращаем выбранный Bank. Вычитаем 1, т.к. индексация начинается с 0.
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

            // Убираем пробелы в начале и конце строки.
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
                        continue; // Возвращаемся к началу цикла while.
                }
                break; // Выходим из цикла, если ввод корректен.

            } catch (const std::invalid_argument &e) {
                std::cerr << "Ошибка: Некорректный ввод. Пожалуйста, введите число." << std::endl;
            } catch (const std::out_of_range &e) {
                std::cerr << "Ошибка: Введенное число слишком велико или мало." << std::endl;
            }
        }

        // Преобразуем sentTypeSaving в нижний регистр для согласованности.
        std::transform(m_typeSaving.begin(), m_typeSaving.end(), m_typeSaving.begin(), ::tolower);

        std::cout << "Выбранный тип сбережения: " << m_typeSaving
                  << std::endl;  // Выводим выбранный тип для подтверждения
        return m_typeSaving;
    }

    std::string getNameToSaving() {
        std::string nameToSaving;
        while (true) {
            std::cout << "Введите название сбережения в которое хотите перевести: ";
            try {
                std::getline(std::cin, nameToSaving);
                break;
            } catch (const std::invalid_argument &e) {
                std::cerr << "Ошибка: " << e.what() << std::endl;
            }
        }
        return nameToSaving;
    }

    template<typename T>
    // Используем шаблон для обобщения типа
    T getItemToInput(const std::vector<Metal> &metals,
                     const std::vector<Currency> &currencies,
                     const std::vector<Cryptocurrency> &cryptocurrencies
    ) {
        if (m_typeSaving == "валюта") {
            while (true) {
                std::cout << "Выберите валюту в которую хотите перевести:" << std::endl;
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
                        return currencies[option - 1];
                    } else {
                        std::cout << "Некорректный ввод. Пожалуйста, выберите номер от 1 до " << currencies.size()
                                  << "."
                                  << std::endl;
                    }
                } catch (const std::invalid_argument &e) {
                    std::cerr << "Ошибка: Некорректный ввод. Пожалуйста, введите число." << std::endl;
                } catch (const std::out_of_range &e) {
                    std::cerr << "Ошибка: Введенное число слишком велико или мало." << std::endl;
                }
            }
        }
    }

    template<typename T>
    T getItemFromInput(const std::vector<Metal> &metals,
                       const std::vector<Currency> &currencies,
                       const std::vector<Cryptocurrency> &cryptocurrencies
    ) {
        if (m_typeSaving == "валюта") {
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
        } else if (m_typeSaving == "металл") {
            std::string name;
            double weight, pricePerGram;

            std::cout << "Доступные металлы:" << std::endl;
            std::cout << "1. Золото" << std::endl;
            std::cout << "2. Серебро" << std::endl;
            std::cout << "3. Платина" << std::endl;
            std::cout << "Введите номер металла: ";
            std::string metalChoice;
            std::getline(std::cin, metalChoice);

            int metalOption;
            try {
                metalOption = std::stoi(metalChoice);
                switch (metalOption) {
                    case 1:
                        name = "Золото";
                        break;
                    case 2:
                        name = "Серебро";
                        break;
                    case 3:
                        name = "Платина";
                        break;
                    default:
                        std::cout << "Некорректный выбор металла.  Используется Золото." << std::endl;
                        name = "Золото";
                }
            } catch (const std::invalid_argument &e) {
                std::cout << "Некорректный ввод. Используется Золото." << std::endl;
                name = "Золото";
            }

            // Ввод веса
            while (true) {
                std::string weightStr;
                std::cout << "Введите вес в граммах: ";
                std::getline(std::cin, weightStr);
                try {
                    weight = std::stod(weightStr);
                    if (weight <= 0) {
                        std::cerr << "Ошибка: Вес должен быть положительным числом." << std::endl;
                        continue;
                    }
                    break;
                } catch (const std::invalid_argument &e) {
                    std::cerr << "Ошибка: Некорректный ввод веса." << std::endl;
                }
            }

            // Ввод цены за грамм
            while (true) {
                std::string priceStr;
                std::cout << "Введите цену за грамм в долларах: ";
                std::getline(std::cin, priceStr);
                try {
                    pricePerGram = std::stod(priceStr);
                    if (pricePerGram <= 0) {
                        std::cerr << "Ошибка: Цена должна быть положительным числом." << std::endl;
                        continue;
                    }
                    break;
                } catch (const std::invalid_argument &e) {
                    std::cerr << "Ошибка: Некорректный ввод цены." << std::endl;
                }
            }

//            Metal metal(name, weight, pricePerGram);
//            std::cout << "Введенные данные:" << std::endl;
//            std::cout << "Тип сбережений: " << metal.getTypeSaving() << std::endl;
//            std::cout << "Металл: " << metal.getName() << std::endl;
//            std::cout << "Вес: " << metal.getWeight() << " грамм" << std::endl;
//            std::cout << "Цена за грамм: " << metal.getPricePerGram << " долларов" << std::endl;

//            return static_cast<T>(metal);

        } else if (m_typeSaving == "криптовалюта") {
            std::string name;
            double amount, price;

            std::cout << "Доступные криптовалюты:" << std::endl;
            std::cout << "1. Bitcoin" << std::endl;
            std::cout << "2. Ethereum" << std::endl;
            std::cout << "3. Litecoin" << std::endl;
            std::cout << "Введите номер криптовалюты: ";
            std::string cryptoChoice;
            std::getline(std::cin, cryptoChoice);

            int cryptoOption;
            try {
                cryptoOption = std::stoi(cryptoChoice);
                switch (cryptoOption) {
                    case 1:
                        name = "Bitcoin";
                        break;
                    case 2:
                        name = "Ethereum";
                        break;
                    case 3:
                        name = "Litecoin";
                        break;
                    default:
                        std::cout << "Некорректный выбор криптовалюты. Используется Bitcoin." << std::endl;
                        name = "Bitcoin";
                }
            } catch (const std::invalid_argument &e) {
                std::cout << "Некорректный ввод. Используется Bitcoin." << std::endl;
                name = "Bitcoin";
            }

            // Ввод количества
            while (true) {
                std::string amountStr;
                std::cout << "Введите количество: ";
                std::getline(std::cin, amountStr);
                try {
                    amount = std::stod(amountStr);
                    if (amount <= 0) {
                        std::cerr << "Ошибка: Количество должно быть положительным числом." << std::endl;
                        continue;
                    }
                    break;
                } catch (const std::invalid_argument &e) {
                    std::cerr << "Ошибка: Некорректный ввод количества." << std::endl;
                }
            }

            // Ввод цены
            while (true) {
                std::string priceStr;
                std::cout << "Введите цену за единицу в долларах: ";
                std::getline(std::cin, priceStr);
                try {
                    price = std::stod(priceStr);
                    if (price <= 0) {
                        std::cerr << "Ошибка: Цена должна быть положительным числом." << std::endl;
                        continue;
                    }
                    break;
                } catch (const std::invalid_argument &e) {
                    std::cerr << "Ошибка: Некорректный ввод цены." << std::endl;
                }
            }
//
//            Cryptocurrency crypto(name, amount, price);
//
//            std::cout << "Введенные данные:" << std::endl;
//            std::cout << "Тип сбережений: " << crypto.getTypeSaving() << std::endl;
//            std::cout << "Криптовалюта: " << crypto.getName() << std::endl;
//            std::cout << "Количество: " << crypto.getAmount() << std::endl;
//            std::cout << "Цена за единицу: " << crypto.getPrice() << " долларов" << std::endl;
//
//            return static_cast<T>(crypto);

        } else {
            std::cout << "Неизвестный тип сбережения.  Возвращается пустой объект." << std::endl;
            return T(); // Возвращаем объект типа T, сконструированный по умолчанию
        }
    }
};

#endif