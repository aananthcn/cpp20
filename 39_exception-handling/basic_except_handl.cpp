#include <iostream>
#include <chrono>

int main() {
	try {
		// get some random number
		auto epoch_dur = std::chrono::system_clock::now().time_since_epoch().count()/1000000;

		// throw some random exception using the random number
		int ex_t = epoch_dur % 100;
		if(ex_t & 0x1) {
			std::cout << "Throwing integer exception " << ex_t << std::endl;
			throw ex_t;
		}
		else {
			std::cout << "Throwing string exception " << ex_t << std::endl;
			throw std::to_string(ex_t);
		}
	}
	catch (int ex_c) { // catch that random integer exception
		std::cout << "Catching exception number: " << ex_c << std::endl;
	}
	catch (std::string ex_c) { // catch that random string exception
		std::cout << "Catching exception string: " << ex_c << std::endl;
	}

	return 0;
}