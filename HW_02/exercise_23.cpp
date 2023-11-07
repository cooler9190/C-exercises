#include <iostream>

using namespace std;

int main() {
    int number;

    cout << "Please enter an integer number: ";
    cin >> number;

    for(int i = 0; i <= number; i++) {
        int progression = 0;
        for(int j = number; j >= i; j--) {
            cout << progression;
            progression++;
        }
        cout << endl;
    }
    
    return 0;
}