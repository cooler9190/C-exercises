#include <iostream>
#include <cmath>

bool isEqual(const float &a, const float &b, float &epsilon) {
    if(std::abs(a - b) < epsilon) {
        return true;
    } else {
        return false;
    }
}

bool compareMatrix(const float (&matrix1)[3][3], const float (&matrix2)[3][3], float defaultEpsilon = 1e-9) {
    for(size_t i = 0; i < 3; ++i) {
        for(size_t j = 0; j < 3; ++j) {
            if(isEqual(matrix1[i][j], matrix2[i][j], defaultEpsilon) == false) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    float allowableError = 0;
    
    const float matr1[3][3] = {{0.030042, 2.1783, 8.7},
                         {0.03022, 6.98, 3.8},
                         {9.9, 76.9073, 17}};
    
    const float matr2[3][3] = {{0.0308962, 2.83, 8.797},
                         {0.0322, 9.986, 3.0},
                         {9.9, 76.90730, 17}};

    float** matrix1 = new float*[3];


    std::cout << "Please enter an allowable error number: ";
    std::cin >> allowableError;

    if(std::cin.fail()) {
        std::cerr << "Wrong input!" << std::endl;
        std::cout << "Function will use defalt value." << std::endl;
        
        if(compareMatrix(matr1, matr2) == true) {
            std::cout << "The matrixes are equal" << std::endl;
        } else {
            std::cout << "The matrixes are not equal" << std::endl;
        }
    } else {
        if(compareMatrix(matr1, matr2, allowableError) == true) {
            std::cout << "The matrixes are equal" << std::endl;
        } else {
            std::cout << "The matrixes are not equal" << std::endl;
        }
    }

    
    
    return 0;
}