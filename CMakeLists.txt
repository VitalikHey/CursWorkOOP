cmake_minimum_required(VERSION 3.26)
project(CursWorkOOP)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES
        src/main.cpp
        src/bank/bank.cpp
        src/cryptocurrency/cryptocurrency.cpp
        src/currency/currency.cpp
        src/local_db/local_db.cpp
        src/metal/metal.cpp
        src/saving/saving.cpp
        src/test/test.cpp
        src/transaction/transaction.cpp
        src/transaction-history/transaction-history.cpp
        src/user-input-handler/userInputHandler.cpp
        src/user-interface/userInterface.cpp
)

set(HEADER_FILES
        library/saving/saving.h
        library/currency/currency.h
        library/metal/metal.h
        library/cryptocurrency/cryptocurrency.h
        library/transaction/transaction.h
        library/bank/bank.h
        library/transaction-history/transactionHistory.h
        library/user-input-handler/userInputHandler.h
        library/local_db/local_db.h
        library/user-interface/userInterface.h
        library/test/test.h
)

add_executable(CursWorkOOP ${SOURCE_FILES})

add_library(CursWorkOOP_core STATIC ${SOURCE_FILES})

target_link_libraries(CursWorkOOP CursWorkOOP_core)

target_compile_features(CursWorkOOP_core PUBLIC cxx_std_17)

target_include_directories(CursWorkOOP_core PUBLIC
        library/saving
        library/currency
        library/metal
        library/cryptocurrency
        library/transaction
        library/bank
        library/transaction-history
        library/user-input-handler
        library/local_db
        library/user-interface
        library/test
)
