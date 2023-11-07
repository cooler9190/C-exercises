#include <iostream>
#include <cmath>

template <typename T> 
class Point2d {
    public:
    Point2d(const T& x, const T& y) : m_x(x), m_y(y) {}

    T getX() const {
        return m_x;
    }

    T getY() const {
        return m_y;
    }

    private:
    T m_x;
    T m_y;
};

template <typename T> 
void comparePoints(const Point2d<T>& pointA, const Point2d<T>& pointB) {
    if(pointA.getX() == pointB.getX() && pointA.getY() == pointB.getY()) {
        std::cout << "The points have equal coordinates" << std::endl;
    } else {
        std::cout << "The points don't have equal coordinates" << std::endl;
    }
}

template<>
void comparePoints<float>(const Point2d<float>& pointA, const Point2d<float>& pointB) {
    float epsilon = 1e-9;
    bool xCompare = false, yCompare = false; 
    if(std::abs(pointA.getX() - pointB.getX()) < epsilon) {
        xCompare = true;
    }

    if(std::abs(pointA.getY() - pointB.getY()) < epsilon) {
        yCompare = true;
    }

    if(xCompare && yCompare) {
        std::cout << "The points have equal coordinates" << std::endl;
    } else {
        std::cout << "The points don't have equal coordinates" << std::endl;
    }
}

int main() {
    Point2d<int> point1(5, 4), point2(6, 7);

    Point2d<float> pointF1(1.2, 5.4), pointF2(1.2, 5.4);

    comparePoints(point1, point2);

    comparePoints(pointF1, pointF2);

    return 0;
}