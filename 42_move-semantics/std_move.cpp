#include <iostream>
#include <chrono>

template <typename T>
void normal_swap(T& a, T& b) {
	T temp {a};
	a = b;
	b = temp;
}

template <typename T>
void fast_swap(T& a, T& b) {
	T temp {std::move(a)};
	a = std::move(b);
	b = std::move(temp);
}

std::string R_Text {
    R"(The silver key, cold and intricate, rested on the basalt pedestal. Its presence
	pulsed with a low, resonant hum, disturbing the dust that had settled over centuries.
	Elara, shielding her eyes from the sudden burst of bioluminescent spores, recognized
	the specific craftsmanship—it belonged to the Order of the Silent Watchers. She knew
	this relic was the catalyst for activating the ancient sky-gate, a device dormant
	since the $\text{Aethelred}$ era. The air crackled with potential energy; the convergence
	angle of the shadows was precisely $45^{\circ}$. She had only moments before the lunar
	eclipse finished its cycle. The fate of the entire valley hinged on her next, precise
	movement.)"
};

std::string J_Text {
	R"(The Great Red Spot, a colossal anticyclonic storm on Jupiter, churned like a
	permanent wound, a vortex wider than Earth itself. Its sheer scale dominated the
	banded atmosphere, a mix of hydrogen and helium swirling in turbulent zones and
	belts. Io, the innermost Galilean moon, continuously ejects plumes of sulfurous
	material, constantly reshaping its surface due to intense tidal heating. The
	gravitational forces exerted by this gas giant are immense, influencing the dynamics
	of the entire inner solar system.)"
};


void print_timediff(auto start, auto end, int iter, std::string label) {
	auto duration = end - start;
	long long microseconds = std::chrono::duration_cast<std::chrono::microseconds>(duration).count();

	std::cout << label << " (total): " << microseconds << " usecs." << std::endl;
	std::cout << label << " (average): " << (double)microseconds/iter << " usecs." << std::endl;
}

const int ITERATIONS = 100000;

int main() {
	// normal swap
	auto start1 = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < ITERATIONS; ++i) {
		normal_swap(R_Text, J_Text); // Swap back and forth
	}
	auto end1 = std::chrono::high_resolution_clock::now();
	print_timediff(start1, end1, ITERATIONS, "normal swap");

	// fast swap
	auto start2 = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < ITERATIONS; ++i) {
		fast_swap(R_Text, J_Text); // Swap back and forth
	}
	auto end2 = std::chrono::high_resolution_clock::now();
	print_timediff(start2, end2, ITERATIONS, "fast swap");

	return 0;
}
