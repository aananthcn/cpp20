#include <iostream>
#include <cassert>

namespace CU {

	class Point_nD {
		public : 
		Point_nD(std::initializer_list<double> list) {
			m_size= list.size();
			m_data = new double[m_size];
			for(unsigned int i{} ;  i < m_size; ++i){
				m_data[i] = *(list.begin() + i) ;
			}
		}

		Point_nD(const Point_nD& source) {
			m_size = source.size();
			m_data = new double[m_size];
			for(unsigned int i{} ;  i < m_size; ++i){
              		m_data[i] = source.m_data[i] ; // FIX NEEDED HERE
					 
        	}
		}


		~Point_nD(){
			delete[] m_data;
		}


		// void set( unsigned int index, double value){
		// 	m_data[index] = value;
		// }

		unsigned int size() const{
			return m_size;
		}

		void print() const{
			std::cout << "Point [ ";
			for(unsigned int i{} ;  i < m_size; ++i){
               std::cout << m_data[i] << " ";
        	}
			std::cout << "]";
		}
		
		//YOU WILL PUT YOUR SUBSCRIPT OPERATOR BELOW THIS LINE
		//DON'T MODIFY ANYTHING ABOVE THIS LINE

        // double operator[](unsigned int i) const {
        double& operator[](unsigned int i) {
			assert(i < m_size);
            return m_data[i];
        }

		friend Point_nD operator+(const Point_nD& left_operand, const Point_nD& right_operand);

		//YOU WILL PUT YOUR SUBSCRIPT OPERATOR ABOVE THIS LINE
		//DON'T MODIFY ANYTHING BELOW THIS LINE

		private : 
		unsigned int m_size;
		double* m_data;
	};


	Point_nD operator+(const Point_nD& left_operand, const Point_nD& right_operand);

}

namespace CU {
    Point_nD operator+(const Point_nD& left_operand, const Point_nD& right_operand) {
		Point_nD tmp(left_operand);
		for(unsigned int i{} ;  i < left_operand.size(); ++i) {
			// tmp.set(i, tmp[i] + right_operand.m_data[i]); 	 // FIX NEEDED HERE
			tmp[i] = tmp[i] + right_operand.m_data[i]; 	 // FIX NEEDED HERE
        }
		return tmp;
	}
}


int main() {
    CU::Point_nD p1 {1.1,2.2,3.3};
    std::cout << "value [0] : " << p1[0] << std::endl;
    std::cout << "value [1] : " << p1[1] << std::endl;
    std::cout << "value [2] : " << p1[2] << std::endl;
}