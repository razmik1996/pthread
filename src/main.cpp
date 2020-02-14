#include "customthread.hpp"

int main() {
    std::string name = "filename.txt"; 
    CustomThread pthread(name);
    pthread.writeFile();
    pthread.readFile();
    pthread.find("aaa");
    pthread.join();
    return 0;
}
