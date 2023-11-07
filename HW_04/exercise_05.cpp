#include <iostream>

float max(float first, float second) {
//     if(a > b) {
//         return a;
//     } 
    
//     return b;

    
    return (first > second ? first : second);
}

int main() {
    float a = 25.7, b = 25.74;

    std::cout << max(a, b) << " is the bigger number" << std::endl;

    return 0;
}