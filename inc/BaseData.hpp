#pragma once

#include "Component.hpp"

class BaseData final: public Component {
    public:
        BaseData() = default;
        ~BaseData() override = default;

        void init() override;
        void shutdown() override;

        void writeData(int value);
};