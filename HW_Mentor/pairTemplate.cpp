/*Exercise 02: Pair Class TemplateCreate a Pair class template that takes two different types and stores one object of each type.
Your Pair class should have getters and setters for each object, and a method print that prints both objects.*/

#include <iostream>
#include <string>

template <typename T, typename K>
class Pair {
    public:
    Pair(const T& first, const K& second) : m_firstPair(first), m_secondPair(second) {}

    T getFirst() const {
        return m_firstPair;
    }

    K getSecond() const {
        return m_secondPair;
    }

    void setFirst(const T& newFirst) {
        m_firstPair = newFirst;
    }

    void setSecond(const K& newSecond) {
        m_secondPair = newSecond;
    }

    void printPair() {
        std::cout << "(" << m_firstPair << ", " << m_secondPair << ")" << std::endl;
    }

    private:
    T m_firstPair;
    K m_secondPair;
};

int main() {
    Pair<double, std::string> pair(0, "Hello!");

    std::cout << pair.getFirst() << " " << pair.getSecond() << std::endl;

    pair.setFirst(3.14);

    pair.setSecond("Hello, World!");

    pair.printPair();

    return 0;
}