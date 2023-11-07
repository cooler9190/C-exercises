#include <iostream>

using namespace std;

int main() {
    double a, b, s;

    cout << "Please enter the value of side A: ";
    cin >> a;

    cout << "Now enter the value of side B: "; 
    cin >> b;

    s = a * b;
    cout << "The area of the rectangle is: " << s;

    return 0;

}