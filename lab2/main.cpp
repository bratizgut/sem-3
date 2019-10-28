#include "worker.h"

int main() {
    worker w;
    try {
        w.parce("text.txt");
    }

    catch (const std::exception &ex){
        std::cout << ex.what() << std::endl;
    }

    w.makeSequence();
    
    return 0;
}