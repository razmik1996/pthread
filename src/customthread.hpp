#include <vector>
#include <iostream>
#include <pthread.h>
#include <fstream>
#include <string>

class CustomThread {
private:///members
    std::fstream file;
    pthread_t thread;
public:///constructors and destructor
    CustomThread(std::string fileName);
    CustomThread(const &CustomThread);
    ~CustomThread();
public:///member functions
    void* readFile(void *);
    void* writeFile(void *);
    void* find(void *);
};
