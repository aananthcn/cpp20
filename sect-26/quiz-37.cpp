#include <iostream>
#include <concepts>
 
template <typename T>
T add_up( const T collection[] , unsigned int size) 
requires (std::integral<T> || std::floating_point<T>) {
    T sum{};
    for(unsigned int i{0} ; i < size ; ++i){
        sum += collection[i];
    }
    return sum;
}
 
int main(){
 
   double scores[] {40UL,50UL,60UL};
   auto result = add_up(scores,3);
   std::cout << "result : " << result << std::endl;

   return 0;
}