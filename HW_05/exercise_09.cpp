#include <iostream>
#include <string>
#include <vector>

void delimiterString(const std::string& s, const std::string& delim, std::vector<std::string>& v) {
    std::string subs = "";
    char currentDelim = '0';
    for(int i = 0; i < s.size(); ++i) {
        for(int j = 0; j < delim.size(); ++j) {
            if(s[i] == delim[j]) {
                currentDelim = delim[j];
                v.push_back(subs);
                subs = "";
                break;
            } 
        }
        if(s[i] == currentDelim) {
            continue;
        } else {
            subs += s[i];
        }
    }

    if(!subs.empty()) {
        v.push_back(subs);
    }
}

int main() {
    std::vector<std::string> vec = {};
    std::string word = "Hello;My name&is-Roger.", delimiters = "; -";

    delimiterString(word, delimiters, vec);

    for(int i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }

    std::cout << std::endl;    

    return 0;
}