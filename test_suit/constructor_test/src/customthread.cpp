#include "customthread.hpp"

CustomThread::CustomThread(std::string fileName) :
    m_fileName(fileName) 
{
    std::cout << "Constructor called.." << std::endl;
    m_file.open(m_fileName); 
    if(m_file.is_open()){
        std::cout << "File succesfuly opened" << std::endl;
    }
    if(!m_file.is_open()) {
        std::cout << "Unable to open file" << std::endl;
        std::ofstream outfile(m_fileName);
        outfile.close();
        std::cout << "New file with name \"" << m_fileName << "\" created" << std::endl;
        m_file.open(m_fileName);
    }
}    
     
CustomThread::CustomThread(const CustomThread& other) {
    m_fileName = other.m_fileName;
}

CustomThread::~CustomThread() {
    std::cout << "Destructor called.." << std::endl;
    m_file.close();
}
