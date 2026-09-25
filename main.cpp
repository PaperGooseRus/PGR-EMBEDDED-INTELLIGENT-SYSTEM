#include <iostream>

class Base_data {
    private:
        // pass

    public:
        Base_data() {
            std::cout << "Base data is init" << std::endl;
        };

        ~Base_data() {
            std::cout << "Base data is uninit" << std::endl;
        };
};

class Markov {
    private:
        // pass
    
    public:
        Markov() {
            std::cout << "Markov is init" << std::endl;
        };

        ~Markov() {
            std::cout << "Markov is uninit" << std::endl;
        };
};

class Net {
    private:
        // pass
    
    public:
        Net() {
            std::cout << "Net is init" << std::endl;
        };

        ~Net() {
            std::cout << "Net is uninit" << std::endl;
        };
};

class Simvolic_regression {
    private:
        // pass

    public:
        Simvolic_regression() {
            std::cout << "Simvolic regression is init" << std::endl;
        };

        ~Simvolic_regression() {
            std::cout << "Simvolic regression is uninit" << std::endl;
        };
};

int main(int argc, char *argv[]) {
    std::cout << "StartUp PaperGooseRus EMBEDDED NET" << std::endl;

    Base_data base_data;
    Markov markov;
    Net net;
    Simvolic_regression simvolic_regression;

    return 0;
}