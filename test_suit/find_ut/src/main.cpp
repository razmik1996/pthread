#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <string>


const char* file_name = "A.txt";
std::ifstream m_file;
const char* word = "test"; 
int count = 1; 


int find(const char* word);

int interactive_testing(int argc, char **argv)
{
	if (2 == argc) {

		if (!std::strcmp(argv[1], "--help")) {
			std::cout << "Pass 3 arguments:\n[filename] - name of the file to look in\n"
				<< "[word] - word to look for in file\n"
				<< "[count] - count of \"word\" in file]\n";
			return 0;
		}
	} else if (argc == 1) {
		//std::cerr << "Command line arguments count must be 3 or 0!\nPass [--help] to see more.\n";
		return 0;
	} else if (argc != 4 || argc != 1) {
		std::cerr << "Command line arguments count must be 3 or 0!\nPass [--help] to see more.\n";
		exit(1);
	}
	count = atoi(argv[3]);

	if (0 == count) {
		std::cerr << "Count must not be zero!\n";
		exit(2);
	}
	//char *
	file_name = argv[1];
	word = argv[2];

}

int find_test(int count, const char* word)
{
	m_file.open(file_name);
	std::ofstream out_file("output.txt");
	int found_count = find(word);
	if (count == found_count) {
		out_file << word << ' ' << count << std::endl;
		//std::clog << "test succesfully passed!\n";
	} else {
		//std::clog << "test faild.\n";
		out_file << "test faild" << std::endl;
	}
	return 0;
}

int main(int argc, char** argv)
{
	interactive_testing(argc, argv);
	find_test(count, word);
	return 0;
}
