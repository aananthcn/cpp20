#include <iostream>
#include <string>
#include <cstring>


// Generic template function to hunt down a value in a collection
template <typename T>
int hunt_down(const T& value, const T* collection, size_t size) {
	for (size_t i = 0; i < size; ++i) {
		if (collection[i] == value) {
			return static_cast<int>(i); // Return the index if found
		}
	}
	return -1; // Return -1 if not found
}

// WRONG: template specialization for const char* type
// template <>
// int hunt_down<const char*>(const char* value, const char** collection, size_t size) {
// 	for (size_t i = 0; i < size; ++i) {
// 		if (std::strcmp(collection[i], value) == 0) {
// 			return static_cast<int>(i); // Return the index if found
// 		}
// 	}
// 	return -1; // Return -1 if not found
// }

// CORRECT: template specialization for const char* type
template <>
int hunt_down<const char*>(const char* const& value, const char* const* collection, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        if (std::strcmp(collection[i], value) == 0) {
            return static_cast<int>(i);
        }
    }
    return -1;
}


int main() {
	// Example usage: String search
	const std::string students[] {"Steve","Karly","Sally","Salim"} ;
	std::string to_find{"Steve"};
	if (-1 != hunt_down(to_find, students, 4)) {
		std::cout << to_find << " found in the collection!" << std::endl;
	} else {
		std::cout << to_find << " NOT found in the collection!" << std::endl;
	}

	// Example usage: Integer search;
	const unsigned int ids[] {1122,4432,7828,9022,3903,3015,2072};
    unsigned int id_to_find {2222};
    if (-1 != hunt_down(id_to_find, ids, 7)) {
		std::cout << id_to_find << " found in the collection!" << std::endl;
	} else {
		std::cout << id_to_find << " NOT found in the collection!" << std::endl;
	}

	// Example usage: C-style string search
	const char* student_to_find {"Kumar"};
    const char* students_cstr[] {"Mary", "Steve", "Kumar", "Ahmed"};
    if (-1 != hunt_down(student_to_find, students_cstr, 4)) {
		std::cout << student_to_find << " found in the collection!" << std::endl;
	} else {
		std::cout << student_to_find << " NOT found in the collection!" << std::endl;
	}
}

