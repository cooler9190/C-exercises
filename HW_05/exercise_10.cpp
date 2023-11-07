#include <iostream>
#include <string>

enum WeekDays {
    Monday = 1,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
    Sunday,

    dayCount,
};

WeekDays inputDay() {
    int day = 0;

    std::cout << "Please enter the number of week day(from 1 to 7): ";
    std::cin >> day;

    if(day < 1 || day > 7) {
        std::cout << "Invalid day! Please enter again: ";
        return inputDay();
    }

    return static_cast<WeekDays>(day);
}

std::string dayToString(int day) {
    std::string days[dayCount] = {" ","Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

    return days[day];
}

int main() {
    WeekDays startDay = inputDay(), endDay = inputDay();
    int difference = 0;

        for(int i = startDay; i < endDay; ++i) {
            if(i != startDay && i != endDay) {
                ++difference;
                std::cout << dayToString(i) << " ";
            }
        }

        std::cout << difference << std::endl;

    return 0;
}