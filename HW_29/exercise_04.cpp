#include <iostream>
#define IS_IN_RANGE(begin, end, number) if(number >= begin && number <= end) std::cout << "In range \n"; else std::cout << "Not in range \n";


int main() {
    double begin = 100, end = 100.25, num = 100.26;

    IS_IN_RANGE(begin, end, num); 

    return 0;
}