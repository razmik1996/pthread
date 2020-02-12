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

void* CustomThread::readFile(void * filename) {
    char* s = (char*)filename;
    return 0;
}

void* CustomThread::writeFile(void * filename)
{
    return 0;
}



int CustomThread::find_helper_str(std::string word)
{
        std::string line;
        unsigned int found = 0;
        while (std::getline(m_file, line)) {
                if (line.find(word) != std::string::npos) {
			++found;
                }
        }
        if (found) {
                std::cout << word << " is found. (number of occurances is: " 
			<< std::to_string(found) << std::endl;
        }
        return found;
}

void* CustomThread::find_helper(void* ptr_word)
{
        //std::string* word = static_cast<std::string*>(ptr_word);
        char* ch_word = static_cast<char*>(ptr_word);
        std::string word(ch_word);
	unsigned int val = find_helper_str(word);
        unsigned int* found = new unsigned int(val);
        return static_cast<void*>(found);
	//pthread_exit(static_cast<void*>(found));
}


int CustomThread::find(const char* word)
{
	pthread_t thread;
	void* ret_val;

	typedef void * (*THREADFUNCPTR)(void *);
 
	pthread_create(&thread, NULL, (THREADFUNCPTR) &CustomThread::find_helper, (void*)word);
	pthread_join(thread, &ret_val);
	return *(static_cast<int*>(ret_val));
}
