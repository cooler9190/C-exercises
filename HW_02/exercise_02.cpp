#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double s, r;

    cout << "Please enter the value of the radius: ";
    cin >> r;

    s = M_PI * pow(r, 2);

    cout << "The area of a circle is: " << s << endl;
    
    return 0;
}