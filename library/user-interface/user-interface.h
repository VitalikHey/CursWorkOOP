#ifndef CURSWORKOOP_USER_INTERFACE_H
#define CURSWORKOOP_USER_INTERFACE_H

#include "../transaction/transaction.h"
#include "../user-input-handler/userInputHandler.h"
#include "../local_db/local_db.h"
#include <windows.h>
class UserInterface {
private:
    Transaction transaction;
    TransactionHistory transactionHistory;
    UserInputHandler handler;
    LocalDatabase database;

public:
    UserInterface() : database(initializeLocalDatabase()) {}

    void run() {
        SetConsoleOutputCP(CP_UTF8);

        while (true) {
            Bank selectedBank = handler.selectBank(database.banks);

            std::variant<Metal, Cryptocurrency, Currency> from, to;

            std::string fromTypeSaving = handler.getSavingType();

            try {
                if (fromTypeSaving == "металл") {
                    from = handler.getMetalFromInputHandler(database.metalMap, true);
                } else if (fromTypeSaving == "криптовалюта") {
                    from = handler.getCryptoCurrencyFromInputHandler(database.cryptocurrencyMap, true);
                } else if (fromTypeSaving == "валюта") {
                    from = handler.getCurrencyFromInputHandler(database.currencyMap, true);
                } else {
                    std::cout << "Неизвестный тип сбережения (from)." << std::endl;
                    continue;
                }
            } catch (const std::exception &e) {
                std::cerr << "Ошибка при получении актива from: " << e.what() << std::endl;
                continue;
            }

            try {
                if (fromTypeSaving == "металл") {
                    to = handler.getMetalFromInputHandler(database.metalMap, false);
                } else if (fromTypeSaving == "криптовалюта") {
                    to = handler.getCryptoCurrencyFromInputHandler(database.cryptocurrencyMap, false);
                } else if (fromTypeSaving == "валюта") {
                    to = handler.getCurrencyFromInputHandler(database.currencyMap, false);
                } else {
                    std::cout << "Неизвестный тип сбережения (to)." << std::endl;
                    continue;
                }
            } catch (const std::exception &e) {
                std::cerr << "Ошибка при получении актива to: " << e.what() << std::endl;
                continue;
            }

            try {
                double result = transaction.conductTransaction(from, to, selectedBank);

                transactionHistory.addTransaction(from, to, result);

                std::cout << "Транзакция успешно проведена. Результат: " << result << std::endl;
            } catch (const std::exception &e) {
                std::cerr << "Ошибка при проведении транзакции: " << e.what() << std::endl;
            }

            while (true) {
                std::cout << "\nВыберите действие:\n";
                std::cout << "1. Провести еще одну транзакцию\n";
                std::cout << "2. Посмотреть историю транзакций\n";
                std::cout << "3. Остановить программу\n";
                std::cout << "Введите номер действия: ";

                std::string choice;
                std::getline(std::cin, choice);

                try {
                    int option = std::stoi(choice);

                    switch (option) {
                        case 1:
                            goto next_transaction;
                        case 2:
                            transactionHistory.printTransactionHistory();
                            while (true) {
                                std::cout << "\nВернуться в главное меню? (y/n): ";
                                std::string backChoice;
                                std::getline(std::cin, backChoice);
                                if (backChoice == "y" || backChoice == "Y") {
                                    goto next_transaction;
                                } else if (backChoice == "n" || backChoice == "N") {
                                } else {
                                    std::cout << "Некорректный ввод. Введите 'y' или 'n'." << std::endl;
                                }
                            }
                        case 3:
                            std::cout << "Программа завершена." << std::endl;
                            exit(0);
                        default:
                            std::cout << "Некорректный ввод. Пожалуйста, выберите номер от 1 до 3." << std::endl;
                    }
                } catch (const std::invalid_argument &e) {
                    std::cerr << "Ошибка: Некорректный ввод. Пожалуйста, введите число." << std::endl;
                } catch (const std::out_of_range &e) {
                    std::cerr << "Ошибка: Введенное число слишком велико или мало." << std::endl;
                }
            }

            next_transaction:;
        }
    }
};

#endif
