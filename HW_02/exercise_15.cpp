#include <iostream>

using namespace std;

int main() {
    int number;
    int i = 1;

    cout << "Please enter an integer number: ";
    cin >> number;

    while(i <= 9) {
        cout << number << " x " << i << " = " << number * i << endl;
        i++;
    }
    
    return 0;
}