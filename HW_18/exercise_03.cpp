#include <iostream>
#include <vector>
#include <string>

class Person {
    public:
    Person(std::string n, int a) {
        name = n;
        age = a;
    }

    inline std::string getName() { return name; }

    inline int getAge() {return age; }

    private:
    std::string name;
    int age;
};

void printPersonInAgeRange(std::vector<Person> &vec, const int &bottom, const int &upper) {
    int count = 0;
    for(auto iter = vec.begin(); iter != vec.end(); ++iter) {
        if(iter -> getAge() >= bottom && iter -> getAge() <= upper) {
            auto func = [count]() mutable { return ++count; };
            count = func();
            std::cout << iter->getName() << " is in the designated age range." << std:: endl;
        }
    } 

    std::cout << "There is/are " << count << " person/s in the designated age range." << std::endl;
}

int main() {
    Person p1("Nick", 22), p2("Andrea", 21), p3("John", 45), p4("Cindy", 36), p5("Mark", 60);
    std::vector<Person> personList = {p1, p2, p3, p4, p5};

    int bottomRange = 0, upperRange = 0;

    std::cout << "Please enter a number for the lower bound of the age range: ";
    std::cin >> bottomRange;

    std::cout << "Now enter a number for the upper bound of the age range: ";
    std::cin >> upperRange;

    printPersonInAgeRange(personList, bottomRange, upperRange);


    return 0;
}