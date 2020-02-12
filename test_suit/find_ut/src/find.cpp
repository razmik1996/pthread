#include <pthread.h>
#include <iostream>
#include <fstream>
#include <string>

extern std::ifstream m_file;



int find_helper(std::string word)
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

void* find_helper(void* ptr_word)
{
        //std::string* word = static_cast<std::string*>(ptr_word);
        char* ch_word = static_cast<char*>(ptr_word);
        std::string word(ch_word);
	unsigned int val = find_helper(word);
        unsigned int* found = new unsigned int(val);
	return static_cast<void*>(found);
	//pthread_exit(static_cast<void*>(found));
}


int find(const char* word)
{
	pthread_t thread;
	void* ret_val;
	pthread_create(&thread, NULL, find_helper, (void*)word);
	pthread_join(thread, &ret_val);
	return *(static_cast<int*>(ret_val));
}
