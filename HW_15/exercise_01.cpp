#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

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

void bubbleSort(std::vector<Person> &vec, Person *begin, Person *end){
    for(size_t i = 0; i < vec.size(); ++i){
        for(Person *j = begin; j <= end - (1 + i); ++j){
            if(j->getName() > (j + 1)->getName()){
                std::swap(*j, *(j + 1));
            }
        }
    }
}

void printPersons(std::vector<Person> &vec) {
    for(size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i].getName() << " ";
    }

    std::cout << std::endl;
}

int main() {
    Person p1("John"), p2("Nick"), p3("Andy"), p4("Marry"), p5("Simon"), p6("Alfred");
    std::vector<Person> vec = {p1, p2, p3, p4, p5, p6};
    Person *ptrBegin = &vec[0], *ptrEnd = &vec[5];

    printPersons(vec);

    bubbleSort(vec, ptrBegin, ptrEnd);

    std::cout << std::endl;

    printPersons(vec);

    std::cout << std::endl;

    return 0;
}