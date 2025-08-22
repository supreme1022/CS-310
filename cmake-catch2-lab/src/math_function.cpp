#include "math_function.h"
#include <cmath>


double compute_sqr_root_(double number){

    if(number < 0){
        return -1;
    } 

    return std::sqrt(number);
}