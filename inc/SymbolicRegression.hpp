#pragma once

#include "Component.hpp"

class BaseData;

class SymbolicRegression final: public Component {
    public:
        explicit SymbolicRegression(BaseData& db);

        void init() override;
        void shutdown() override;

    private:
        BaseData& db_;
};