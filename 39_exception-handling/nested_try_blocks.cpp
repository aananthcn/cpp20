#include <iostream>

void exception_thrower() {
	throw 'z';
}


int main() {
	for (int i = 0; i < 5; i++) {
		try {
			std::cout << "ENTERING OUTER try BLOCK" << std::endl;
			if (i == 0) {
				throw "2";
			}
			try {
				std::cout << "ENTERING INNER try BLOCK" << std::endl;
				if (i == 1) {
					exception_thrower();
				}
				if (i == 2) {
					throw 5;
				}
				if (i == 3) {
					throw 8.0;
				}
				std::cout << "EXITING INNER try BLOCK" << std::endl;
			}
			catch (int ex) {
				std::cout << "INNER: catching integer exception: " << ex << std::endl;
			}
			std::cout << "EXITING OUTER try BLOCK" << std::endl;
		}
		catch (const char *ex) {
			std::cout << "OUTER: catching const char* exception: " << ex << std::endl;
		}
		catch (double ex) {
			std::cout << "OUTER: catching double exception: " << ex << std::endl;
		}
		catch (char ex) {
			std::cout << "OUTER: catching char exception: " << ex << std::endl;
		} // outer try
	} // for loop
}