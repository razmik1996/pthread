#include "customthread.hpp"

int main() {
    std::string name = "filename.txt"; 
    CustomThread pthread(name);
    pthread.writeFile();
    pthread.readFile();
    pthread.find("aaa");
    std::cout << "From main" << std::endl;
    pthread.join();
    return 0;
}
