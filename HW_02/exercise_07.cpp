#include <iostream>

using namespace std;

int main() {
    int a;

    cout << "Please enter an integer value: ";
    cin >> a;

    if(a % 2 == 0) {
        cout << a << " is a positive number" << endl;
    } else {
        cout << a << " is a negative number" << endl;
    }
    
    return 0;
}