CustomThread::CustomThread(std::string fileName) {
i
}

CustomThread::CustomThread(const &CustomThread) {

}

CustomThread::~CustomThread() {

}

void* CustomThread::readFile(void * filename) {
    std::string s = (std::string)filename;
    file.open(s);
    if(!file.is_open()) {
        file(s); 
    }
    
}

void* CustomThread::writeFile(void *) {

}

void* CustomThread::find(void *) {

}
