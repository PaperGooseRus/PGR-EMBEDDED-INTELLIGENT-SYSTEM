#include "Markov.hpp"
#include "BaseData.hpp"

#include <iostream>

Markov::Markov(BaseData& db): db_(db) {
}

void Markov::init() {
    std::cout << "Markov init\n";

    db_.writeData(10);
}

void Markov::shutdown() {
    std::cout << "Markov shutdown\n";
}