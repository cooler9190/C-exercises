#include <iostream>

using namespace std;

int main() {
    int height, width;
    char ch;

    cout << "Please enter the symbol, height and width of the recrangle you wish to build: ";
    cin >> ch >> height >> width;

    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            cout << ch;
        }
        cout << endl;
    }
    
    return 0;
}