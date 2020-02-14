#include <iostream>
#include <fstream>
#include <pthread.h>
#include "writeFile.hpp"
#include <string>

std::ofstream m_file("file.txt");
pthread_mutex_t mutex1;
void* writeWrapperFile(void* ptr)
{
   	pthread_mutex_lock(&mutex1);
	
	std::string message = "Hello world";
//	std::getline(std::cin, message);
// 	m_file.seekg(0, m_file.end);
    m_file << message << std::endl;
   	
	pthread_mutex_unlock(&mutex1);
}

void* writeFileHelper(void* ptr)
{
    return writeWrapperFile(ptr);
}

void* writeFile(void)
{	
	void* ptr = NULL;
	pthread_t pthread;
    pthread_create(&pthread, NULL, &writeFileHelper, ptr); 
    pthread_join(pthread, NULL);
}
