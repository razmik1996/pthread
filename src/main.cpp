#include "customthread.hpp"

int main() {
    std::string name = "filename.txt"; 
    CustomThread pthread(name);
    pthread.writeFile();
    pthread.readFile();
    pthread.join();
    //    std::cout << pthread.find("Hello") << std::endl;
    //  std::cout << "From main" << std::endl;
    return 0;
}
