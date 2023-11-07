#include <iostream>

inline int bestMatch (int a) { return a; };
inline double bestMatch (double a) { return a; };

inline int constReferenceConv (int &a) { return a; };
inline int constReferenceConv (const int &a) { return a; };

inline int typePromotion (int a) { return a; };
inline double typePromotion (double c) { return c; };

inline void ptrTypePromotion (int* x) {};
inline void ptrTypePromotion (long* x) {};


int main() {
    std::cout << bestMatch(3) << std::endl;

    int a = 5;
    std::cout << constReferenceConv(a) << std::endl;

    std::cout << typePromotion('c') << std::endl;

    ptrTypePromotion(&a);


    return 0;
}