#include <iostream>
#include <stdexcept>

class Vector {
    public:
    Vector() {
        m_size = 0;
        m_capacity = 0;
        m_elements = new int[m_capacity];
    };

    Vector(const int &size) : m_size(size), m_capacity(size), m_elements(new int[m_capacity]{0}) {}

    Vector(const Vector &v) {
        m_size = v.m_size;
        m_elements = new int[m_size];

        for(size_t i = 0; i < m_size; ++i) {
            m_elements[i] = v.m_elements[i];
        }
    }

    Vector& operator=(const Vector &v) {
        if(this != &v) {
            m_size = v.m_size;
            m_elements = new int[m_size];

            for(size_t i = 0; i < m_size; ++i) {
                m_elements[i] = v.m_elements[i];
            }
        }
        return *this;
    }

    ~Vector() {
        std::cout << "Vector destroyed!" << std::endl;
        free();
    }

    int size() const { return m_size; };

    int capacity() const { return m_capacity; };

    int at(const int &i) const {
        if(i >= 0 && i < m_size) {
            return m_elements[i];
        } else {
            throw std::out_of_range("Illegal index at function at()!");
        }
    };

    //valgrind
    //cout destructor
    void swap(Vector &v) {
        Vector temp;
        temp = *this;
        *this = v;
        v = temp;
    }

    void reserve(const int &new_capacity) {
        if(m_capacity >= new_capacity) {
            return;
        } else {
            m_capacity = new_capacity;
            int* new_elements = new int[m_capacity];
            for(size_t i = 0; i < m_size; ++i) {
                new_elements[i] = m_elements[i];
            }

            free();
            m_elements = new_elements;
        }
    }

    void push_back(const int &el) {
        if(m_size >= m_capacity) {
            reserve(m_size * 2);
        }

        m_elements[m_size] = el;
        ++m_size;
    }

    void print() {
        for(size_t i = 0; i < m_size; ++i) {
            std::cout << m_elements[i] << " ";
        }

        std::cout << std::endl;
    }

    void free() {
        if(m_elements) {
            delete[] m_elements;
            m_elements = nullptr;
        }
    }

    private:
    int m_size;
    int m_capacity;
    int* m_elements;
};

int main() {
    Vector v1;

    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);
    v1.push_back(5);

    std::cout << v1.size() << " " << v1.capacity() << std::endl;

    Vector v2(10);

    std::cout << v2.size() << " " << v2.capacity() << std::endl;

    v2 = v1;

    v1.print();
    v2.print();

    v2.reserve(5);

    std::cout << v2.size() << " " << v2.capacity() << std::endl;

    v2.push_back(6);
    v2.push_back(7);
    v2.push_back(8);
    v2.push_back(9);
    v2.push_back(10);

    v1.print();
    v2.print();

    std::cout << v2.size() << " " << v2.capacity() << std::endl;

    v1.swap(v2);

    v1.print();
    v2.print();

    std::cout << v1.at(9) << std::endl;

    std::cout << v2.at(9) << std::endl;


    return 0;
}