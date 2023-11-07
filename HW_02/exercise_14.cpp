#include <iostream>
#include <string>

using namespace std;

int main() {
    string name = "0";
    int years;
    
    cout << "Please enter your name and years: ";
    cin >> name >> years;

    if(years % 10 == 0) {
        cout << name << " is " << years << " years old and has a an anniversary" << endl;
    } else {
        int remainder = 10 - (years % 10);
        cout << name << " is " << years << " years old and will have an anniversary after " << remainder << " year/s and will be " << years + remainder << " years old" << endl;
    }
    
    return 0;
}