#include "customthread.hpp"

int main() {
    std::string name = "filename.txt"; 
    CustomThread pthread(name);
    pthread.writeFile();
    pthread.readFile();
    pthread.writeFile();
//    std::cout << pthread.find("Hello") << std::endl;
    std::cout << "From main" << std::endl;
    pthread.join();
    return 0;
}
