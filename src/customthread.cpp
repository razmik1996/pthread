<<<<<<< HEAD
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
=======
CustomThread::CustomThread(std::string fileName) {

}

CustomThread::CustomThread(const CustomThread&) {

>>>>>>> a5e26074242aedcf3752f87759fabc55d9ceb770
}

CustomThread::~CustomThread() {
    m_file.close();
}

<<<<<<< HEAD
void* CustomThread::readFile(void) {
}

void* CustomThread::writeFile(void *) {
=======
void* CustomThread::readFile(void * filename) {
    char* s = (char*)filename;
    file.open(s);
    if(!file.is_open()) {
        ifstream file(s); 
    }
}

void* CustomThread::writeFile(void * filename)
{
	char* s = (char*)filename;
	for (int i = 0; i < 100; ++i) {
		file << i << " ";
	}
>>>>>>> a5e26074242aedcf3752f87759fabc55d9ceb770
}

void* CustomThread::find(void * ptrword) {

}
