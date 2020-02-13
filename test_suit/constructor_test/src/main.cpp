#include "customthread.hpp"

int main() {
    char* name = "filename.txt"; 
    CustomThread pthread(name);
    return 0;
}
