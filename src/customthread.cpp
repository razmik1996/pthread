CustomThread::CustomThread(std::string fileName) {

}

CustomThread::CustomThread(const CustomThread&) {

}

CustomThread::~CustomThread() {

}

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
}

void* CustomThread::find(void *) {

}
