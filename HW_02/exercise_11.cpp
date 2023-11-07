#include <iostream>

using namespace std;

int main() {
    int a, digit;

    cout << "Please enter an integer value: ";
    cin >> a;

    while(a > 0) {
        digit = a % 10;
        a /= 10;

        cout << digit << endl;
    }

    return 0;
}