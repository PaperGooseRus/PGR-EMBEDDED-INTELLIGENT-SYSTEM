#pragma once

#include "Component.hpp"

class BaseData;

class Net final: public Component {
    public:
        explicit Net(BaseData& db);

        void init() override;
        void shutdown() override;

    private:
        BaseData& db_;
};