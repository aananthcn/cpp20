#include <string>
#include <iostream>
#include <cassert>



class Scores{
    public : 
        Scores() = delete;
        Scores(const std::string& course_name)
            : m_course_name{course_name}
        {}

    double& operator[](size_t index){
        assert((index >= 0) &&(index < 20));
        return m_scores[index];
    }

    double operator[](size_t index) const{
        assert((index >= 0) &&(index < 20));
        return m_scores[index];
    }

    void print_info()const{
        std::cout << m_course_name << " : [ ";
        for(size_t i{}; i < 20; ++i){
            std::cout << m_scores[i] << " ";
        }
        std::cout << "]" << std::endl;
    }

    private: 
        std::string m_course_name;
        double m_scores[20]{};
};

int main() {
	Scores s1("Math");
	s1.print_info();
	s1[5] = 88.3;
	s1.print_info();

	std::cout << std::endl;
	const Scores s2("Geography");
	std::cout << "Geo score: " << s2[5] << std::endl;

	return 0;
}