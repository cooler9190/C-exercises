#include <iostream>

using namespace std;

int main() {
    int a;

    cout << "Please enter an integer value: ";
    cin >> a;

    int lastNumber = a % 10;
    
    cout <<"Last number of " << a << " is " << lastNumber << endl;
   

    return 0;
}