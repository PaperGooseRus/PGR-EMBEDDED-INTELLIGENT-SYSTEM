#pragma once

#include "Component.hpp"

class BaseData;

class Markov final : public Component {
    public:
        explicit Markov(BaseData& db);

        void init() override;
        void shutdown() override;

    private:
        BaseData& db_;
};