#include <iostream>

using namespace std;

int main() {
    int numbers1[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int numbers2[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            cout << numbers1[i] << " x " << numbers2[j] << " = " << numbers1[i] * numbers2[j] << endl;
        }
        cout << endl;
    }
    
    return 0;
}