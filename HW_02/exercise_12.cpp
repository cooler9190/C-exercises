#include <iostream>

using namespace std;

int main() {
    int a, digit;
    int sum = 0;

    cout << "Please enter an integer value: ";
    cin >> a;

    while(a > 0) {
        digit = a % 10;
        a /= 10;
        sum += digit;
    }

    cout << "The sum of the digits is: " << sum << endl;
    
    return 0;
}