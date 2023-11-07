#include <iostream>

using namespace std;

int main() {
    int length;
    char ch1;

    cout << "Please enter a symbol and length of the triangle's cathetus you wish to build: ";
    cin >> ch1 >> length;

    for(int i = 0; i < length; i++) {
        for(int j = length; j > i; j--) {
            cout << ch1;
        }
        cout << endl;
    }
    
    return 0;
}