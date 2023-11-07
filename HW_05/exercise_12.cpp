#include <iostream>
#include <vector>
#include <string>

enum gender {
    Male,
    Female,
};

class Person {
    public:
    std::string name = "";
    int age = 0;
    gender gen; 
    int height = 0;
};

using personContainer = std::vector<Person>;

void setPersonData(Person &p, std::string n, int age, int height, std::string gen) {
    p.name = n;
    p.age = age;
    p.height = height;
    if(gen == "male") {
        p.gen = Male;
    } else {
        p.gen = Female;
    }
}

std::string getName(Person p) {
    return p.name;
}

int getAge(Person p) {
    return p.age;
}

int getHeight(Person p) {
    return p.height;
}

gender getGender(Person p) {
    return p.gen;
}

int numberOfMen(personContainer pc) {
    int menCount = 0;
    for(int i = 0; i < pc.size(); ++i) {
        if(getGender(pc[i]) == 0) {
            ++menCount;
        } 
    }

    return menCount;
}

int numberOfWomen(personContainer pc) {
    int womenCount = 0;
    for(int i = 0; i < pc.size(); ++i) {
        if(getGender(pc[i]) == 1) {
            ++womenCount;
        } 
    }

    return womenCount;
}

int averageAge(personContainer pc) {
    int sum = 0, avg = 0;
    for(int i = 0; i < pc.size(); ++i) {
        sum += getAge(pc[i]);
    }

    return avg = sum / pc.size();
}

int averageHeight(personContainer pc) {
    int sum = 0, avg = 0;
    for(int i = 0; i < pc.size(); ++i) {
        sum += getHeight(pc[i]);
    }

    return avg = sum / pc.size();
}

void oldestManAndWoman(personContainer pc) {
    Person oldestMan = pc[0], oldestWoman = pc[0];
    for(int i = 0; i < pc.size(); ++i) {
        if(getGender(pc[i]) == 0) {
            if(getAge(oldestMan) < getAge(pc[i])) {
                oldestMan = pc[i];
            }
        } else {
            if(getAge(oldestWoman) < getAge(pc[i])) {
                oldestWoman = pc[i];
            }
        }
    }

    std::cout << "The oldest man is: " << oldestMan.name << " Age: " << oldestMan.age << " Height: " << oldestMan.height << " Gender: " << oldestMan.gen << std::endl;
    std::cout << "The oldest woman is: " << oldestWoman.name << " Age: " << oldestWoman.age << " Height: " << oldestWoman.height << " Gender: " << oldestWoman.gen << std::endl;

}

int main() {
    personContainer container = {};
    std::string n = "", g = "";
    int a = 0, h = 0;
    Person p;

    std::cout << "Please enter data fo a group of persons(name, age, height, gender): ";

    while(!std::cin.eof()) {
        std::cin >> n >> a >> h >> g;

        for(int i = 0; i < g.size(); ++i) {
            if(isupper(g[i])) {
                g[i] = tolower(g[i]);
            }
        }

        setPersonData(p, n, a, h, g);

        container.push_back(p);
    }

    std::cout << "The number of men and women in the group are: " << numberOfMen(container) << " and " << numberOfWomen(container) << std::endl;
    std::cout << "The average age in the group is: " << averageAge(container) << std:: endl;
    std::cout << "The average height in the group is: " << averageHeight(container) << std:: endl;
    oldestManAndWoman(container);

    return 0;
}