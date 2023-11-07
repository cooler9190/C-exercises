#include <iostream>

inline bool isFloatEqual(const float &a, const float &b, const float &epsilon = 1e-9) { return (std::abs(a - b)) < epsilon; }

inline float fmin(const float &a, const float &b) { return a < b ? a : b; }

inline float max(const float &first, const float &second) { return (first > second ? first : second); }

inline double abs(float &a) { return a < 0 ? (a *= -1) : a; }

inline int ciel(float &a) { return static_cast<int>(a + 1); }

inline int floor(float &a) { return static_cast<int>(a - 1); }

inline int round(float &a) { return static_cast<int>(a + 0.5); }

inline float clampAbove(const float &value, const float &maxValue) { return value > maxValue ? maxValue : value; }

inline float clampBelow(const float &value, const float &minValue) { return value < minValue ? value : minValue; }

inline int fibSequence(int n) { return n <= 1 ? n : (fibSequence(n - 1) + fibSequence(n - 2)); }

inline bool isPositive(const int &n) { return (n % 2 == 0) ? true : false; }


int main() {
    float a = 0.0000435, b = 0.0000436;
    int n = 10;

    std::cout << isFloatEqual(a, b) << std::endl;
    std::cout << fmin(a, b) << std::endl;
    std::cout << max(a, b) << std::endl;
    std::cout << abs(a) << std::endl;
    std::cout << ciel(a) << std::endl;
    std::cout << floor(a) << std::endl;
    std::cout << clampAbove(a, b) << std::endl;
    std::cout << clampBelow(a, b) << std::endl;
    std::cout << fibSequence(n) << std::endl;
    std::cout << isPositive(n) << std::endl;

    return 0;
}