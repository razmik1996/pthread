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
    pthread_join(threadWrite, NULL);
    m_file.close();
}

void* CustomThread::readFileHelper(void* object)
{
	return ((CustomThread*)object)->readWrapperFile();
}

void* CustomThread::readWrapperFile(void)
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

void* CustomThread::readFile()
{
	pthread_create(&threadRead, NULL, &CustomThread::readFileHelper, this);
}

void* CustomThread::writeFileHelper(void* object) 
{
	return (void *)((CustomThread*)object)->writeWrapperFile();

}

void* CustomThread::writeWrapperFile(void)
{
	pthread_mutex_lock(&mutex1);
	std::string message;
	std::getline(std::cin, message);
    m_file.clear();
	m_file.seekg(0, m_file.end);
    m_file << message << std::endl;
	pthread_mutex_unlock(&mutex1);
}

void CustomThread::join(){
    pthread_join(threadWrite, NULL);
    pthread_join(threadRead, NULL);
    //pthread_join(threadFind, NULL);
}

void* CustomThread::writeFile()
{	
	pthread_create(&threadWrite, NULL, &CustomThread::writeFileHelper, this);
   // pthread_join(threadWrite, NULL);
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
 
	pthread_create(&threadFind, NULL, (THREADFUNCPTR) &CustomThread::find_helper, (void*)word);
	pthread_join(threadFind, &ret_val);
	return *(static_cast<int*>(ret_val));
}
