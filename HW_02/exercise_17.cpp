#include <iostream>

using namespace std;

int main() {
    int numbers1[9] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    int numbers2[9] = {9, 8, 7, 6, 5, 4, 3, 2, 1};

    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            cout << numbers1[i] << " x " << numbers2[j] << " = " << numbers1[i] * numbers2[j] << endl;
        }
        cout << endl;
    }
    
    return 0;
}