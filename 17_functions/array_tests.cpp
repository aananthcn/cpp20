#include <iostream>
#include <array>

double sum( double scores[4], unsigned int count){
 
    double score_sum{};
    // unsigned int count = sizeof(scores) / sizeof(double);
    // unsigned int count = std::size(scores); // this will not work as scores is decayed to pointer
 
   for(size_t i{0} ; i < count ; ++i){
       score_sum += scores[i];
   }
    return score_sum;
}
 
 
// int main(){
 
// //    double my_scores[]{10.0,20.0,30.0,40.0};
//    double my_scores[]{10.5,34.3,4.8,6.5};
//    double result = sum(my_scores, std::size(my_scores));
//    std::cout << "result : " << result << std::endl;
 
//     return 0;
// }

 
void sum( int* a,   int* b){
    a+=b;
    std::cout << "sum : " << a << std::endl;
}
 
 
int main(){
 
    double x{3.5};
    double y{5.5};
 
    std::cout << "x : " << x << " y : "<< y << std::endl;
    sum(&x,&y);
    std::cout << "x : " << x << " y : "<< y << std::endl;
 
    return 0;
}