#include <iostream>
#include "math_function.h"

int main(){

    double num = 25.0;
    double result = compute_sqr_root(num);
    std:: cout << "Square root of " << num << " is " << result << std::endl;
    return 0;
}

