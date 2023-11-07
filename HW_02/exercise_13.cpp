#include <iostream>

using namespace std;

int main() {
    int a;
    double digit, avg;
    int digitCount = 0;
    double sum = 0;

    cout << "Please enter an integer value: ";
    cin >> a;

    while(a > 0) {
        digit = a % 10;
        digitCount++;
        a /= 10;
        sum += digit;
        avg = sum / digitCount;
    }

    cout << "The average of the digits is: " << avg << endl;
    
    return 0;
}