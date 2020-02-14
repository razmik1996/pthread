#include <iostream>
#include <pthread.h>
#include <fstream>
#include <string>

class CustomThread {
private:///members
    std::fstream m_file;
    std::string m_fileName;
public:///constructors and destructor
    CustomThread(std::string fileName);
    CustomThread(const CustomThread&);
    ~CustomThread();
public:///member functions
};
