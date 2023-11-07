#include <iostream>
#include <vector>

using vectorDouble = std::vector<double>;

bool isEqual(const double &a, const double &b) {
    //very small number
    double epsilon = 1e-9;

    if(abs(a - b) < epsilon) {
        return true;
    } else {
        return false;
    }
}

vectorDouble rearrangeVector(vectorDouble &vec, const double &n) {
    int flag = 0;
    for(size_t i = 0; i < vec.size(); ++i) {
        if(isEqual(vec[i], n)) {
            flag = i;
        }
    }

    for(size_t j = 0; j < vec.size(); ++j) {
        if(isEqual(vec[j], vec[flag])) {
               
        }
    }
}


int main() {

    
    
    return 0;
}