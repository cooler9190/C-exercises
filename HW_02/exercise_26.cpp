#include <iostream> 
#include <vector>

using namespace std;

int main() {
    double n = 0.0, avg = 0.0;
    double sum = 0.0;
    vector <double> numbers;
    
    cout << "Please enter any amount of numbers: ";
    while(true) {
        cin >> n;
        if(cin.fail()) {
            break;
        }
        numbers.push_back(n);
    }

    for(int i = 0; i < numbers.size(); i++) {
        sum += numbers[i];
    }

    avg = sum / numbers.size();

    cout << "The average of the numbers is: " << avg << endl;

    return 0;
}