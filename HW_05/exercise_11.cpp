#include <iostream>
#include <string>
#include <vector>

enum Months {
    January,
    February,
    March,
    April,
    May,
    June,
    July,
    August,
    September,
    October,
    November,
    December,
};

enum isLeapYear {
    LEAP,
    NON_LEAP,
};

struct MonthInfo {
    std::vector<std::string> monthNames = {};
    int daysInLeap = 0;
    int daysInNonLeap = 0;
};

int numberOfDays(isLeapYear leap, Months month) {
    std::vector<MonthInfo> months = {
        {{"jan", "january"}, 31, 31},
        {{"feb", "february"}, 29, 28},
        {{"mar", "march"}, 31, 31},
        {{"apr", "april"}, 30, 30},
        {{"ma", "may"}, 31, 31},
        {{"jun", "june"}, 30, 30},
        {{"jul", "july"}, 31, 31},
        {{"aug", "august"}, 31, 31},
        {{"sep", "september"}, 30, 30},
        {{"oct", "october"}, 31, 31},
        {{"nov", "november"}, 30, 30},
        {{"dec", "december"}, 31, 31},
    };

    if(leap == LEAP) {
        return months[month].daysInLeap;
    } else {
        return months[month].daysInNonLeap;
    }
    

}


int main() {
    std::string month = "";
    Months m;
    char answer = ' ';
    isLeapYear year;

    std::cout << "Please enter a month: ";
    std::cin >> month;

//convert the name of the month to lowercase letters
    for(int i = 0; i < month.size(); ++i) {
        if(isupper(month[i])) {
            month[i] = tolower(month[i]);
        }
    }

    if(month == "jan" || month == "january") {
        m = January;
    } else if(month == "feb" || month == "february") {
        m = February;
    } else if(month == "mar" || month == "march") {
        m = March;
    } else if(month == "ma" || month == "may") {
        m = May;
    } else if(month == "jun" || month == "june") {
        m = June;
    } else if(month == "jul" || month == "july") {
        m = July;
    } else if(month == "aug" || month == "august") {
        m = August;
    } else if(month == "sep" || month == "september") {
        m = September;
    } else if(month == "oct" || month == "october") {
        m = October;
    } else if(month == "nov" || month == "november") {
        m = November;
    } else if(month == "dec" || month == "december") {
        m = December;
    } else {
        std::cout << "You have entered an invalid month or format!" << std::endl;
        return 0;
    }

    std::cout << "Do you want to check number of days for a leap year? (y / n): ";
    std::cin >> answer;

    if(answer == 'y' || answer == 'Y') {
        year = LEAP;
    } else {
        year = NON_LEAP;
    }


    if(year == LEAP) {
        std::cout << "The number of days in a leap year for " << month << " are " << numberOfDays(year, m) << std::endl;
    } else {
        std::cout << "The number of days in a non leap year for " << month << " are " << numberOfDays(year, m) << std::endl;
    }

    return 0;
}