#include <iostream>

using namespace std;

int main() {
    double a = 0.0, b = 0.0, avg = 0.0;

    cout << "Please enter a value for a: ";
    cin >> a;

    cout << "Please enter a value for b: ";
    cin >> b;

    avg = (a + b) / 2;

    cout << "The average of " << a << " and " << b << " is: " << avg << endl;
    
    return 0;
}