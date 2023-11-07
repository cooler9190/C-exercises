#include <iostream>

using namespace std;

int main() {
    int a, exponent, b = 1;
    
    cout << "Please enter the value of a: ";
    cin >> a;


    cout << "Now enter the value of the exponent: ";
    cin >> exponent;

    cout << a << " raised to the power of " << exponent << " is: ";

    while(exponent != 0) {
        b *= a;
        exponent--;
    }

     cout <<  b << endl;

    return 0;
}