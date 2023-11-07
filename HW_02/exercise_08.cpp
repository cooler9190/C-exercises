#include <iostream>

using namespace std;

int main() {
    int a;

    cout << "Please enter an integer value: ";
    cin >> a;

    if(a % 10 == 0) {
        cout <<"Last number of " << a << " is 0" << endl;
    } else {
        cout <<"Last number of " << a << " is not 0" << endl;
    }

    return 0;
}