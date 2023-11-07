#include <iostream> 

using namespace std;

int main() {
    int n;
    bool isSquare = false;

    cout << "Please enter an integer value: ";
    cin >> n;

    for(int i = 1; i * i <= n; i++) {
        if(n % i == 0 && n / i == i) {
            isSquare = true;
            break;
        } 
    }

    if(isSquare == true) {
        cout << n << " is a perfect sqare" << endl;
    } else {
        cout << n << " is not a perfect square" << endl;
    }

    return 0;
}