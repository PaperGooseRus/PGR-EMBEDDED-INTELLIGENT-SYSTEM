#include "BaseData.hpp"

#include <iostream>

void BaseData::init() {
    std::cout << "BaseData init\n";
}

void BaseData::shutdown() {
    std::cout << "BaseData shutdown\n";
}

void BaseData::writeData(int value) {
    std::cout << "Write: " << value << '\n';
}