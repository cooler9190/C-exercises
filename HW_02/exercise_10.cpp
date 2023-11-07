#include <iostream>

using namespace std;

int main() {
    int a;
    int numCount = 0;

    cout << "Please enter an integer value: ";
    cin >> a;

    while(a != 0) {
        a /= 10;
        numCount++;
    }

    cout <<"The number consists of " << numCount << " digit/s" << endl;

    return 0;
}