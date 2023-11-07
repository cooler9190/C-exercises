#include <iostream> 
#include <vector>

using namespace std;

int main() {
    double n = 0.0, max = 0.0, min = 0.0;
    vector <double> numbers;
    
    cout << "Please enter any amount of numbers: ";
    while(true) {
        cin >> n;
        if(cin.fail()) {
            break;
        }
        numbers.push_back(n);
    }

    min = numbers[0];
    max = numbers[0];
    for(int i = 0; i < numbers.size(); i++) {
        if(min > numbers[i]) {
            min = numbers[i];
        }
        if(max < numbers[i]) {
            max = numbers[i];
        }
    }

    cout << "The smallest number is: " << min << " and the biggest is: " << max << endl;

    return 0;
}