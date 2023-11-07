#include <iostream>
#include <string>

template <typename T>
class TempClass {
    public:
    static std::string getInfo() {
        return "Unknown";
    }
};

template<>
class TempClass <float> {
    public:
    std::string getInfo() const {
        return "float";
    }
};

template<>
class TempClass <char> {
    public:
    std::string getInfo() const {
        return "char";
    }
};

template<>
class TempClass <int*> {
    public:
    std::string getInfo() const {
        return "pointer to int";
    }
};


int main() {
    TempClass<int> i;
    TempClass<char> c;
    TempClass<float> f;
    TempClass<double> d;
    TempClass<int*> intPtr;

    std::cout << i.getInfo() << " " << c.getInfo() << " " << f.getInfo() << " " << d.getInfo() << " " << intPtr.getInfo() << std::endl;

    return 0;
}