#include <iostream>

using namespace std;

int main() {
    int a, b, tmp;
    
    cout << "Please enter the value of a: ";
    cin >> a;

    cout << "Now enter the value of b: ";
    cin >> b;

    tmp = a;
    a = b;
    b = tmp;

    cout << "The value of a is: " << a << " and the value of b is: " << b << endl;

    return 0;
}