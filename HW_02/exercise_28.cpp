#include <iostream> 
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    double n, max2, min2;
    vector <double> numbers;
    
    cout << "Please enter any amount of numbers: ";
    while(true) {
        cin >> n;
        if(cin.fail()) {
            break;
        }
        numbers.push_back(n);
    }

    sort(numbers.begin(), numbers.end());

    min2 = numbers[1];
    max2 = numbers[numbers.size() - 2];

    cout << "The second smallest number is: " << min2 << " and the second biggest is: " << max2 << endl;

    return 0;
}