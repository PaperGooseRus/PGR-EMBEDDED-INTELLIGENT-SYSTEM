#include "Net.hpp"
#include "BaseData.hpp"

#include <iostream>

Net::Net(BaseData& db): db_(db) {
}

void Net::init() {
    std::cout << "Net init\n";
}

void Net::shutdown() {
    std::cout << "Net shutdown\n";
}