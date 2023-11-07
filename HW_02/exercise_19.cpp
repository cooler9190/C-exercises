#include <iostream>

using namespace std;

int main() {
    int height, width;
    char ch1, ch2;

    cout << "Please enter two symbols, height and width of the recrangle you wish to build: ";
    cin >> ch1 >> ch2 >> height >> width;

    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            if((i + j) % 2 == 0) {
                cout << ch1;
            } else {
                cout << ch2;
            }
        }
        cout << endl;
    }
    
    return 0;
}