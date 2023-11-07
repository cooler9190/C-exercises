#include <iostream>
#include <queue>
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

void addPersonToQueue(std::queue<Person> &q) {
    std::string name = "";
    std::cout << "Enter the name of the person: ";
    std::cin >> name;

    Person p(name);
    q.push(p);
}

void removePersonFromQueue(std::queue<Person> &q) {
    q.pop();
}

void printQueue(const std::queue<Person> &q) {
    std::queue<Person> tmp = q;

    if(q.empty()) {
        std::cout << "The queue is empty" << std::endl;
        return;
    }

    while(!tmp.empty()) {
        std::cout << tmp.front().getName() << " ";
        tmp.pop();
    }

    std::cout << std::endl;
}

int main() {
    int command = 0;
    std::queue<Person> q;

    while(true) {
        std::cout << "Please choose a command(1, 2 or 3): " << std::endl;
        std::cout << "1. Add person to the queue." << std::endl;
        std::cout << "2. Remove person from the queue." << std::endl;
        std::cout << "3. Print the queue." << std::endl;
        std::cin >> command;

        if(command == 1) {
            addPersonToQueue(q);
            std::cout << std::endl;
        } else if(command == 2) {
            removePersonFromQueue(q);
            std::cout << std::endl;
        } else if(command == 3) {
            printQueue(q);
            std::cout << std::endl;
        } else {
            std::cout << "Invalid input!" << std::endl;
            break;
        }
    }

    return 0;
}