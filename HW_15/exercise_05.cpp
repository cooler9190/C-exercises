#include <iostream>
#include <vector>
#include <string>

class Person {
    public:
    Person(std::string n) {
        name = n;
    }

    std::string getName() {
        return name;
    }

    private:
    std::string name;
};

int dichoSearch(std::vector<Person> &vec, const std::string &val) {
    int low = 0, high = vec.size() - 1;
    while(high - low > 1) {
        int mid = (high + low) / 2;

        if(vec[mid].getName() < val) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }

    if(vec[low].getName() == val) {
        return low;
    } else if(vec[high].getName() == val){
        return high;
    } else {
        return -1;
    }
}

int main() {
    Person p1("Alfred"), p2("Andy"), p3("John"), p4("Marry"), p5("Nick"), p6("Simon");
    std::vector<Person> vec = {p1, p2, p3, p4, p5, p6};
    std::string value = "";

    std::cout << "Please enter the name you wish to search for: ";
    std::cin >> value;

    int index = dichoSearch(vec, value);

    if(index != -1) {
        std::cout << value << " is present at index " << index << std::endl;
    } else {
        std::cout << value << " is not present in the container" << std::endl;
    }

    return 0;
}