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

void selectionSort(std::vector<Person> &vec) {
    for(size_t i = 0; i < vec.size(); ++i) {
        Person smallest = vec[i];
        size_t flag = i;

        for(size_t j = i + 1; j < vec.size(); ++j) {
         if(vec[j].getName() < smallest.getName()) {
             smallest = vec[j];
             flag = j;
            }
        }

        vec[flag] = vec[i];
        vec[i] = smallest;
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
    
    printPersons(vec);

    selectionSort(vec);

    std::cout << std::endl;

    printPersons(vec);

    std::cout << std::endl;

    return 0;
}