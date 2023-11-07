#include <iostream>
#include <vector>
#include <cmath>

class Shape {
    public:
    virtual double area() = 0;
    virtual double perimeter() = 0;
    virtual std::string getShape() = 0;
    virtual ~Shape() = default;
};

class Circle : public Shape {
    public:
    Circle(const double &r) : m_radius(r) {}

    double area() override {
        return M_PI * pow(m_radius, 2);
    }

    double perimeter() override {
        return 2 * M_PI * m_radius;
    }

    std::string getShape() override {
        return "Circle";
    }

    private:
    double m_radius;
};

class Triangle : public Shape {
    public:
    Triangle(const double &a, const double &b, const double &c, const double &hA = 0, const double &hB = 0, const double &hC = 0) : 
    m_sideA(a), m_sideB(b), m_sideC(c), m_heightA(hA), m_heightB(hB), m_heightC(hC) {}

    double area() override {
        if(m_heightA != 0) {
            return (m_sideA * m_heightA) / 2;
        } else if(m_heightB != 0) {
            return (m_sideB * m_heightB) / 2;
        } else if(m_heightC != 0) {
            return (m_sideC * m_heightC) / 2;
        } else {
            double halfP = (m_sideA + m_sideB + m_sideC) / 2;

            return std::sqrt(halfP * (halfP - m_sideA) * (halfP - m_sideB) * (halfP - m_sideC));
        }
    }

    double perimeter() override {
        return m_sideA + m_sideB + m_sideC;
    }

    std::string getShape() override {
        return "Triangle";
    }
    
    private:
    double m_sideA, m_sideB, m_sideC, m_heightA, m_heightB, m_heightC;
};

class Square : public Shape {
    public:
    Square(const double &a) : m_side(a) {}

    double area() override {
        return m_side * m_side;
    }

    double perimeter() override {
        return m_side * 4;
    }

    std::string getShape() override {
        return "Square";
    }

    private:
    double m_side;
};

class Rectangle : public Shape {
    public:
    Rectangle(const double &a, const double &b) : m_sideA(a), m_sideB(b) {}

    double area() override {
        return m_sideA * m_sideB;
    }

    double perimeter() override {
        return m_sideA * 2 +  m_sideB * 2;
    }

    std::string getShape() override {
        return "Rectangle";
    }

    private:
    double m_sideA, m_sideB;
};

int main() {
    std::vector<Shape*> shapes;
    Circle circle(13.5);
    Triangle triangle1(12, 14, 16), triangle2(12.3, 4.5, 3.8, 0, 15);
    Square square(8);
    Rectangle rectangle(14, 15.8);

    Shape* circ(&circle); 
    shapes.push_back(circ);

    Shape* triang1(&triangle1);
    shapes.push_back(triang1);

    Shape* triang2(&triangle2);
    shapes.push_back(triang2);

    Shape* sqr(&square);
    shapes.push_back(sqr);

    Shape* rect(&rectangle);
    shapes.push_back(rect);

    for(size_t i = 0; i < shapes.size(); ++i) {
        std::cout << shapes[i]->getShape() << std::endl;
        std::cout << "Area: " << shapes[i]->area() << " Perimeter: " << shapes[i]->perimeter() << std::endl;
        std::cout << std::endl;
    }

    return 0;
}