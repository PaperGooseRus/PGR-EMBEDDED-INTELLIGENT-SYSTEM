#include <iostream>

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

int main(int argc, char *argv[]) {
    std::cout << "StartUp PaperGooseRus Net" << std::endl;

    Net net;

    return 0;
}