#include <iostream>
#include <string>


using string = std::string;

string printStringInReverse(string &str) {
    string reverse = "";
    for(string::iterator iter = str.end(); iter >= str.begin(); --iter) {
        reverse += *iter;
    }
    
    return reverse;
}

int main() {
    string sentance = "";

    std::cout << "Please enter a sentance: ";
    std::getline(std::cin, sentance);

    std::cout << printStringInReverse(sentance) << std::endl;

    return 0;
}