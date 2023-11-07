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

void print(const std::vector<Point> &vec) {
    for(auto iter = vec.begin(); iter != vec.end(); ++iter) {
        std::cout << "(" << iter->getXaxis() << ", " << iter->getYaxis() << ") ,"; 
    }

    std::cout << std::endl;
}

float calculateDistance(const Point &p) {
    float distance = 0;

    distance = std::pow(std::pow((p.getXaxis() - 0), 2) + std::pow((p.getYaxis() - 0), 2), 2);

    return distance;
}

int main() {
    Point p1(0.3f, 0.8f), p2(2.4f, 1.7f), p3(1.8f, 3.7f), p4(0.4f, 0.9f), p5(1.8f, 3.7f);

    std::vector<Point> pointList = {p1, p2, p3, p4, p5};

    std::stable_sort(pointList.begin(), pointList.end(), [](const Point &p1, const Point &p2) { return calculateDistance(p1) < calculateDistance(p2);});

    print(pointList);

    return 0;
}