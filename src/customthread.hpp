#include <iostream>
#include <pthread.h>
#include <fstream>
#include <string>

///@file customthread.hpp

///@class CustomThread 
///@details The class is used to demonstrate how reading from /n and writing in a file can be done using "pthreads".
///@date 12.02.2020
class CustomThread {
private:///members
    std::fstream m_file;
    std::string m_fileName;
public:///constructors and destructor
    CustomThread(std::string fileName);
    CustomThread(const CustomThread&);
    ~CustomThread();
public:///member functions
<<<<<<< HEAD
    static void* readFile_wrapper(void*);
    void* readFile(void);
=======
	///@brief Function to read from file. \n
	///If there's no file with such name, the file is created.
	///@param --- is the name of the file.
    void* readFile(void *);
	///@brief Function to write the integers in range of [0,99] in file.
	///If there's no file with such name, .....
	///@param --- is the name of the file in which should be written.
>>>>>>> a5e26074242aedcf3752f87759fabc55d9ceb770
    void* writeFile(void *);
	///@brief Function to find the specified word in the file.
	///If there's no such word in a file, .....
	///@param ---is the word that must be searched in the file.
    void* find(void *);
};
