#include <iostream>

using namespace std;

int main() {
    double a, b, c;
    cout << "Please enter the value of a: ";
    cin >> a;

    cout << "Now enter the value of b: "; 
    cin >> b;

    cout << "Please enter the value of c: ";
    cin >> c;

    if(a < b && a < c) {
        cout << a << " is the smallest number" << endl;
    } else if(b < a && b < c) {
        cout << b << " is the smallest number" << endl;
    } else {
        cout << c << " is the smallest number" << endl;
    }
    
    return 0;
}