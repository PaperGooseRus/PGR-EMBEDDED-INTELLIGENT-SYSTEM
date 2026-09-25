#include "BaseData.hpp"
#include "Markov.hpp"
#include "Net.hpp"
#include "SymbolicRegression.hpp"

#include <array>
#include <iostream>

// class Component {
//     private:
//         // pass

//     public:
//         /**
//          * Зачем virtual ~Component()
//          * Потому что вы можете обращаться к объекту-наследнику через указатель базового класса:
//          * ```cpp
//          * Component* component = &markov;
//          * ```
//          * Если когда-нибудь появится:
//          * ```cpp
//          * delete component;
//          * ```
//          * без виртуального деструктора это приведёт к неправильному уничтожению объекта.
//          */
//         virtual ~Component() = default;

//         virtual void init() = 0;
//         virtual void shutdown() = 0;
// };

/**
 * `public Component` означает публичное наследование.
 * 
 * Теперь компилятор требует, чтобы класс наследования реализовал:
 * - void init() override;
 * - void shutdown() override;
 * 
 * `overrid`e очень желательно использовать всегда. Если случайно ошибиться:
 * ```cpp
 * void Init() override;
 * ```
 * компилятор сразу сообщит, что такой виртуальной функции в родителе нет.
 */

// class BaseData final : public Component {
//     private:
//         // pass

//     public:
//         void init() override {
//             std::cout << "Base data is init\n";
//         }

//         void shutdown() override {
//             std::cout << "Base data is uninit\n";
//         }
// };

/**
 * А связь с БД — не наследование
 * Обратите внимание на:
 * ```cpp
 * class Markov final : public Component {
 *     private:
 *         BaseData& db_;
 * };
 * ```
 * и:
 * ```cpp
 * explicit Markov(BaseData& db): db_(db) {
 *    // pass
 * }
 * ```
 * Таким образом:
 *          Component
 *       /      |       \
 * BaseData   Markov     Net
 *              |
 *              | uses
 *              v
 *           BaseData
 * То есть: Markov IS-A Component
 * но: Markov USES BaseData
 * 
 * БД является фундаментом, а Markov/NN/символическая регрессия работают поверх неё.
 */

/**
 * Я бы не строил архитектуру на new, delete, shared_ptr и большом количестве динамических объектов.
 * В документации прямо заложены требования детерминизма и отсутствия динамических аллокаций в горячем пути.
 * Поэтому вариант:
 * ```cpp\
 * BaseData db;
 * Markov markov(db);
 * Net net(db);
 * SymbolicRegression symbolic_regression(db);
 * ```
 * для такого проекта значительно уместнее, чем:
 * ```cpp
 * auto markov = std::make_unique<Markov>(...);
 * ```
 * А массив:
 * ```cpp
 * std::array<Component*, 4>
 * ```
 * даёт полиморфизм без динамического выделения памяти.
 */

// class Markov final : public Component {
//     private:
//         BaseData& db_;

//     public:
//         explicit Markov(BaseData& db): db_(db) {
//         }

//         void init() override {
//             std::cout << "Markov is init\n";
//         }

//         void shutdown() override {
//             std::cout << "Markov is uninit\n";
//         }
// };


// class Net final : public Component {
//     private:
//         BaseData& db_;

//     public:
//         explicit Net(BaseData& db): db_(db) {
//         }

//         void init() override {
//             std::cout << "Net is init\n";
//         }

//         void shutdown() override {
//             std::cout << "Net is uninit\n";
//         }
// };


// class SymbolicRegression final : public Component {
//     private:
//         BaseData& db_;

//     public:
//         explicit SymbolicRegression(BaseData& db): db_(db) {
//         }

//         void init() override {
//             std::cout << "Symbolic regression is init\n";
//         }

//         void shutdown() override {
//             std::cout << "Symbolic regression is uninit\n";
//         }
// };


int main() {
    std::cout << "StartUp PaperGooseRus EMBEDDED NET\n";

    BaseData db;

    Markov markov(db);
    Net net(db);
    SymbolicRegression symbolicRegression(db);

    std::array<Component*, 4> components {
        &db,
        &markov,
        &net,
        &symbolicRegression
    };

    for (Component* component : components) {
        component->init();
    }

    for (auto it = components.rbegin(); it != components.rend(); ++it) {
        (*it)->shutdown();
    }

    return 0;
}
/**
 * Microsoft Windows [Version 10.0.17763.9245]
 * (c) Корпорация Майкрософт (Microsoft Corporation), 2018. Все права защищены.
 * C:\Users\d.gusev\Documents\Project\NN>g++ -std=c++17 -Wall -Wextra -Wpedantic -Iinc -c src/BaseData.cpp -o build/BaseData.o
 * C:\Users\d.gusev\Documents\Project\NN>g++ -std=c++17 -Wall -Wextra -Wpedantic -Iinc -c src/Markov.cpp -o build/Markov.o
 * C:\Users\d.gusev\Documents\Project\NN>g++ -std=c++17 -Wall -Wextra -Wpedantic -Iinc -c src/Net.cpp -o build/Net.o
 * C:\Users\d.gusev\Documents\Project\NN>g++ -std=c++17 -Wall -Wextra -Wpedantic -Iinc -c src/SymbolicRegression.cpp -o build/SymbolicRegression.o
 * C:\Users\d.gusev\Documents\Project\NN>g++ -std=c++17 -Wall -Wextra -Wpedantic -Iinc -c src/main.cpp -o build/main.o
 * C:\Users\d.gusev\Documents\Project\NN>g++ build/main.o build/BaseData.o build/Markov.o build/Net.o build/SymbolicRegression.o -o build/main
 */