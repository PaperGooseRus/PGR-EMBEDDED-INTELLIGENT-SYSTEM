#include "SymbolicRegression.hpp"
#include "BaseData.hpp"

#include <iostream>

SymbolicRegression::SymbolicRegression(BaseData& db): db_(db) {
}

void SymbolicRegression::init() {
    std::cout << "SymbolicRegression init\n";
}

void SymbolicRegression::shutdown() {
    std::cout << "SymbolicRegression shutdown\n";
}