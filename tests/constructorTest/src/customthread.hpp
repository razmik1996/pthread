#include <vector>
#include <iostream>
#include <pthread.h>
#include <fstream>
#include <string>
#include <stdexcept>
#include <cassert>

class CustomThread {
private:///members
    std::fstream m_file;
    char* m_fileName;
public:///constructors and destructor
    CustomThread(char* fileName);
    CustomThread(const CustomThread&);
    ~CustomThread();
public:///member functions
};
