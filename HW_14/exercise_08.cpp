#include <iostream>
#include <unordered_map>
#include <string>

int main(int argc, char *argv[]) {
    std::unordered_map<signed int, std::string> unMap;
    for(size_t i = 1; i <= argc - 1; ++i) {
        signed int key = atoi(argv[i]);
        std::string val = "*";

        if(unMap.find(key) == unMap.end()) {
            unMap.insert(make_pair(key, val));
        } else {
            unMap[key] += "*";
        }   
    }

    for(auto iter = unMap.begin(); iter != unMap.end(); ++iter) {
        std::cout << iter -> first << " " << iter -> second << std::endl;
    }

    std::cout << std::endl;

    return 0;
}