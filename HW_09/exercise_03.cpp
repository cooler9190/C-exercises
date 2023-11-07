#include <iostream>
#include <string>

struct Person{
    std::string name;
    int age;
    float heightInKm;
};

bool isEqual(const float &a, const float &b) {
    float epsilon = 0.000001;

    if(std::abs(a - b) < epsilon) {
        return true;
    } else {
        return false;
    }
}

bool areHeightsEqual(const Person (&pArr1)[6], const Person (&pArr2)[6]) {
    for(size_t i = 0; i < 6; ++i) {
        if(isEqual(pArr1[i].heightInKm, pArr2[i].heightInKm) == 0) {
            return false;
        }
    }

    return true;
}

int main() {
    Person person1{"George", 28, 0.0017};
    Person person2{"Victor", 18, 0.00168};
    Person person3{"John", 26, 0.0017};
    Person person4{"Stavri", 50, 0.00168};
    Person person5{"Lucy", 32, 0.00189};
    Person person6{"Linda", 22, 0.0019};

    Person personArr1[6] = {person1, person2, person3, person4, person5, person6};

    Person personArr2[6] = {person3, person4, person1, person2, person6, person5};

    if(areHeightsEqual(personArr1, personArr2) == 1) {
        std::cout << "All of the presons have equal height to their corresponding index." << std::endl;
    } else {
        std::cout << "Not all of the presons have equal height to their corresponding index." << std::endl;
    }


    return 0;
}