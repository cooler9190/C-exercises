#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

class Point {
    public:
    Point(float abscissa, float ordinate) {
        x = abscissa;
        y = ordinate;
    }

    inline float getXaxis() const { return x; }
    inline float getYaxis() const { return y; }

    private:
    float x, y;
};

int printNumOfClosePoints(const std::vector<Point> &vec, const float &epsilon = 1e-9) {
    int count = 0;
    for(auto iter = vec.begin(); iter != vec.end(); ++iter) {
        std::for_each(iter + 1, vec.end(), [&iter, &count, epsilon](const Point &p1){
            float distance = std::pow(std::pow((iter->getXaxis() - p1.getXaxis()), 2) + std::pow((iter->getYaxis() - p1.getYaxis()), 2), 2);
            if(distance < epsilon) {
                ++count;
            }
        });
    }

    return count;
}

int main() {
    Point p1(0.3f, 0.8f), p2(2.4f, 1.7f), p3(1.8f, 3.7f), p4(0.4f, 0.9f), p5(1.8f, 3.7f);
    std::vector<Point> pointList = {p1, p2, p3, p4, p5};

    float epsilon = 0;

    std::cout << "Enter a value for the epsilon: ";
    std::cin >> epsilon;

    std::cout << printNumOfClosePoints(pointList) << std::endl;

    std::cout << printNumOfClosePoints(pointList, epsilon) << std::endl;

    return 0;
}