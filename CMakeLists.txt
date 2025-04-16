cmake_minimum_required(VERSION 3.26)
project(CursWorkOOP)

set(CMAKE_CXX_STANDARD 17)

add_executable(CursWorkOOP src/main.cpp
        library/saving/saving.h
        library/currency/currency.h
        library/metal/metal.h
        library/cryptocurrency/cryptocurrency.h
        library/transaction/transaction.h
        library/bank/bank.h
        library/transaction-history/transactionHistory.h
        library/user-input-handler/userInputHandler.h
        src/local_db/local_db.cpp
        library/local_db/local_db.h
)
