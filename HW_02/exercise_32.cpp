#include <iostream>

using namespace std;

int main() {
    double x, y;
    char op;

    while(true) {
        cout << ">>> ";
        cin >> x;

        LOOP:cout << ">>> ";
        cin >> op;

        cout << ">>> ";
        cin >> y;

        if(cin.fail()) {
            return 0;
        }

        if(op == '+') {
            x += y;
        } else if(op == '-') {
            x -= y;
        } else if(op == '*') {
            x *= y;
        } else if(op == '/') {
            while(y == 0) {
                cout << "Cannot divide by 0!" << endl;
                cout << "Please enter y again: ";
                cin >> y;
            }
            x /= y;
        } else {
            return 0;
        }

        cout << x << endl;
        goto LOOP;
    }
    return 0;
}