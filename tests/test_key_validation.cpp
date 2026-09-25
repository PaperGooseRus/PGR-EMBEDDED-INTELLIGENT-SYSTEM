#include "BaseData.hpp"

#include <cstdlib>
#include <iostream>
#include <string>

void check(bool actual, bool expected) {
    if (actual != expected) {
        std::cerr << "TEST FAILED\n";
        std::exit(EXIT_FAILURE);
    }
}

int main() {
    check(BaseData::is_valid_key("nn.layer[0].weight_1"), true);
    check(BaseData::is_valid_key("System.temperature"), false);
    check(BaseData::is_valid_key(std::string(129, 'a')), false);

    std::cout << "All tests passed\n";

    return EXIT_SUCCESS;
}