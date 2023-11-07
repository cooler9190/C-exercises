#include <iostream> 

using namespace std;

int main() {
    double a, b;

    cout << "Please enter the value of a: ";
    cin >> a;

    cout << "Now enter the value of b: "; 
    cin >> b;

    if(a > b) {
        cout << a << " is the bigger number" << endl;
    } else {
        cout << b << " is the biggest number" << endl;
    }

    return 0;
}