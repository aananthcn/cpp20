#include <iostream>
#include <vector>

template <typename T>
void print_vector(std::vector<T>& vec) {
	for (int i {}; i < vec.size(); i++) {
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;
}

int main() {
	std::vector<int> vec1 {2, 4, 6, 1, 49, 2};
	std::vector<int> vec2 (10, 55);

	vec1.push_back(33);
	vec2.at(0) = 10;
	vec2[1] = 1;

	// inserting Elements in Vector
	std::vector<int>::iterator it = vec2.begin() + 3;
	vec2.insert(it, 7);
	vec2.push_back(97);
	it = vec1.end() - 1;
	vec1.insert(it, 51);

	auto it2 = vec2.end() - 1;
	std::cout << "\nVector2 end: " << *it2 << std::endl;
	it2++;
	std::cout << "One past end: " << *it2 << "\n" << std::endl;

	print_vector(vec1);
	print_vector(vec2);

	return 0;
}