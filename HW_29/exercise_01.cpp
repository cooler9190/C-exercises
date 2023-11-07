#include <iostream>
#include <cmath>
#define DEG_TO_RAD(x) (x * M_PI/180);
#define RAD_TO_DEG(x) (x * 180/M_PI)


int main() {
    double deg = 90;

    double rad = DEG_TO_RAD(deg);

    double rad2 = 45;

    double deg2 = RAD_TO_DEG(rad2);

    std::cout << "Converting " << deg << " dgrees to radians: " << rad << std::endl;

    std::cout << "Converting " << rad2 << " radians to degrees: " << deg2 << std::endl;

    return 0;
}