#include "BaseData.hpp"

#include <iostream>
#include <cstddef>

namespace {
    constexpr std::size_t MAX_KEY_LENGTH = 128;

    constexpr bool is_allowed_key_char(char ch) noexcept {
        return
            (ch >= 'a' && ch <= 'z') ||
            (ch >= '0' && ch <= '9') ||
            ch == '.' ||
            ch == '_' ||
            ch == '[' ||
            ch == ']';
    }
}

void BaseData::init() {
    std::cout << "BaseData init\n";
}

void BaseData::shutdown() {
    std::cout << "BaseData shutdown\n";
}

bool BaseData::is_valid_key(std::string_view key) noexcept {
    if (key.empty() || key.size() > MAX_KEY_LENGTH) {
        return false;
    }

    for (char ch : key) {
        if (!is_allowed_key_char(ch)) {
            return false;
        }
    }

    return true;
}

void BaseData::writeData(int value) {
    std::cout << "Write: " << value << '\n';
}