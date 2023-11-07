#include <iostream>
#include <string>
#include <cctype>

int main() {
    std::string gender = "";
    int age = 0;

    while(std::cin) {
        std::cout << "Please enter the gender and age of the participant: ";
        std::cin >> gender >> age;

        if(std::cin.fail()) {
            std::cout << "Wrong input!" << std::endl;
            return 0;
        }

        if(islower(gender[0])) {
            gender[0] = toupper(gender[0]);

        }

        for(int i = 1; i < gender.size(); i++) {
            if(isupper(gender[i])) {
                gender[i] = tolower(gender[i]);
            }
        }

        if(gender == "Male") {
            if(age >= 30 && age <= 40) {
                std::cout << "The participant is eligable for the study" << std::endl;
            } else {
                std::cout << "The participant is not eligable for the study" << std::endl;

            }
        } else if(gender == "Female") {
            if(age >= 25 && age <= 35) {
                std::cout << "The participant is eligable for the study" << std::endl;
            } else {
                std::cout << "The participant is not eligable for the study" << std::endl;

            }
        } else {
            std::cout << "Please enter a gender(male or female)" << std::endl;
        }

    }

    return 0;
}