#include <iostream> 

using namespace std;

int main() {
    int left, right, i;
    int sum = 0;
    
    cout << "Please enter the left and rigth constraint of the interval: ";
    cin >> left >> right;

    i = left;

    while(i <= right) {
        if(i % 2 == 0) {
            sum += i;
        }
        i++;
    } 

    cout << "The sum of the positive numbers in the interval " << left << " to " << right << " is: " << sum << endl;

    return 0;
}