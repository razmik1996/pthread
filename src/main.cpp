#include "customthread.hpp"

int main() {
    pthread_t thread;
    std::string name = "filename.txt"; 
    CustomThread pthread(name);

    return 0;
}
