#include "customthread.hpp"

CustomThread::CustomThread(std::string fileName) :
    m_fileName(fileName) 
{
    m_file.open(m_fileName); 
    if(!m_file.is_open()) {
        std::cout << "Unable to open file" << std::endl;
        std::ofstream outfile(m_fileName);
        outfile.close();
        std::cout << "New file with name \"" << m_fileName << "\"created" << std::endl;
        m_file.open(m_fileName);
    }
}    
     
CustomThread::CustomThread(const CustomThread& other) {
    m_fileName = other.m_fileName;
}

CustomThread::~CustomThread() {
    m_file.close();
}

void* CustomThread::readFile(void) {
}

void* CustomThread::writeFile(void *) {
}

void* CustomThread::find(void * ptrword) {

}
