#include <iostream>

using namespace std;

int main() {
    int length;
    char ch1, ch2;

    cout << "Please enter two symbol and length of the triangle's cathetus you wish to build: ";
    cin >> ch1 >> ch2 >> length;

    for(int i = 0; i < length; i++) {
        for(int j = length; j > i; j--) {
            cout << ch1;
        }
        for(int j = 0; j < i; j++) {
            cout << ch2;
        } 
        cout << endl;
    }
    
    return 0;
}