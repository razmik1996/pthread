#include "readFile.hpp"
#include <iostream>
#include <fstream>
#include <pthread.h>
#include <string>

std::fstream m_file("file.txt");
pthread_mutex_t mutex1;
void* readWrapperFile(void* ptr)
{
    pthread_mutex_lock(&mutex1);
    
	m_file.clear();
    m_file.seekg(0, m_file.beg);
    std::string line;
    while(std::getline(m_file, line)) {
            std::cout << line << "\n";
    }
    
	pthread_mutex_unlock(&mutex1);
}

void* readFileHelper(void* ptr)
{
        return readWrapperFile(ptr);
}

void* readFile(void)
{	
	void* ptr = NULL;
	pthread_t pthread;
    pthread_create(&pthread, NULL, &readFileHelper, ptr); 
    pthread_join(pthread, NULL);
}

