#pragma once

#include "Component.hpp"
#include <string_view>

class BaseData final: public Component {
    public:
        BaseData() = default;
        ~BaseData() override = default;

        void init() override;
        void shutdown() override;
        
        static bool is_valid_key(std::string_view key) noexcept;

        void writeData(int value);
};