#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <filesystem>

namespace fs = std::filesystem;

void read_from_file(std::string_view filename, size_t size, int * data)
{
    std::ifstream fstrem_in{ filename.data() }; // We may fail to open the file
    
    //We failed to open the file
    if (fstrem_in.fail()) {
        // We failed to open the file: throw an exception.
		throw fs::filesystem_error(std::string("File '") + filename.data() + "' doesn't exist or cannot be opened!",
    								filename.data(), std::make_error_code(std::errc::no_such_file_or_directory));
    }
     
    int value;
    int index{};
    while (fstrem_in >> value) {
		if (index >= size) {
			throw std::overflow_error("Data Overflow Error! Array index limit reached!");
		}
        data[index++] = value;
    }
    //Something might go wrong in the process of reading the file.
 
    if (!fstrem_in.eof()) {
		throw std::ios_base::failure("Exiting before EOF reached. Not all data are read!");
    }
}

int main(int argc, char* argv[]) {
 	int data[4]{};

	try {
    	read_from_file("numbers.txt", std::size(data), data);
	}
	catch (fs::filesystem_error fe) {
		std::cout << "Caught Exception: " << fe.what() << std::endl;
	}
	catch (std::system_error e) {
		std::cout << "Caught Exception: " << e.what() << std::endl;
	}
	catch (std::runtime_error e) {
		std::cout << "Caught Exception: " << e.what() << std::endl;
	}
	catch (std::exception e) {
		std::cout << "Caught Exception: " << e.what() << std::endl;
	}

    for(auto i : data){
        std::cout << "value : " << i << std::endl;
    }
    
    return 0;
}