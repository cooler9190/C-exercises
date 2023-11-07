#include <iostream>
#include <cmath>

using si = signed int;

class Point {
public:
    si x = 0;
    si y = 0;
};

class Rectangle {
public:
    Point a;
    Point b;
    Point c;
    Point d;
};

void setPoint(Point &p, si x, si y) {
    p.x = x;
    p.y = y;
}

void setRectangle(Rectangle &rect, Point a, Point b, Point c, Point d) {
    rect.a = a;
    rect.b = b;
    rect.c = c;
    rect.d = d;
}

void printRectangle(Rectangle rect) {
    std::cout << "The coordinates of the rectangle are: " << std::endl;
    std::cout << "A(" << rect.a.x << ", " << rect.a.y << ")";
    std::cout << "B(" << rect.b.x << ", " << rect.b.y << ")";
    std::cout << "C(" << rect.c.x << ", " << rect.c.y << ")";
    std::cout << "D(" << rect.d.x << ", " << rect.d.y << ")" << std:: endl;
}

int perimeter(Rectangle rect) {
    si height = abs(rect.a.y) + abs(rect.c.y);
    si length = abs(rect.a.x) + abs(rect.b.x);

    si perimeter = 2*(height + length);

    return perimeter;
}

int area(Rectangle rect) {
    si height = abs(rect.a.y) + abs(rect.c.y);
    si length = abs(rect.a.x) + abs(rect.b.x);

    si area = height * length;

    return area;
}

int main() {
    Rectangle Rectangle;
    Point A, B, C, D;
    si x = 0, y = 0;

    std::cout << "Please enter the coordinates of point A (x / y): ";
    std::cin >> x >> y;

    setPoint(A, x, y);

    std::cout << "Please enter the coordinates of point B (x / y): ";
    std::cin >> x >> y;

    setPoint(B, x, y);

    std::cout << "Please enter the coordinates of point C (x / y): ";
    std::cin >> x >> y;

    setPoint(C, x, y);

    std::cout << "Please enter the coordinates of point D (x / y): ";
    std::cin >> x >> y;

    setPoint(D, x, y);

    setRectangle(Rectangle, A, B, C, D);

    printRectangle(Rectangle);

    std::cout << "The perimeter of the rectangle is: " << perimeter(Rectangle) << std::endl;
    std::cout << "The area of the rectangle is: " << area(Rectangle) << std::endl;

    return 0;
}