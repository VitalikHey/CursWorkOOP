#include "../library/user-interface/userInterface.h"
#include "../library/test/test.h"
#include <windows.h>

int main() {
    SetConsoleOutputCP(CP_UTF8);

    std::cout << "Протестировать программу перед использованием? (y/n): ";
    std::string testChoice;
    std::getline(std::cin, testChoice);

    if (testChoice == "y" || testChoice == "Y") {
        bool testsPassed = ConverterTest::test();
        if (!testsPassed) {
            std::cout << "Тесты не пройдены. Запуск программы отменен." << std::endl;
            return 1;
        }
        std::cout << "Тесты пройдены. Приятного использования программы." << std::endl;
    } else {
        std::cout << "Пропуск тестирования." << std::endl;
    }

    UserInterface userInterface;
    userInterface.run();

    return 0;
}