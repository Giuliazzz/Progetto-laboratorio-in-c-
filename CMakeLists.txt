cmake_minimum_required(VERSION 3.14)
project(EsLaboratorio)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_subdirectory(test)
link_libraries(stdc++fs)

set(SOURCE_FILES BankAccount.cpp BankAccount.h Transaction.cpp Transaction.h AccountManager.cpp AccountManager.h Exceptions.h)
add_executable(EsLaboratorio main.cpp)
add_library(core ${SOURCE_FILES})
target_link_libraries(EsLaboratorio core)