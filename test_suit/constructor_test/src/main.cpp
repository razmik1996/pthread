#include "customthread.hpp"

int main() {
    std::string name = "filename.txt"; 
    CustomThread pthread(name);
    return 0;
}
