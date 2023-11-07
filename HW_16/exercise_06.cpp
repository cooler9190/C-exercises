#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <algorithm>

int main() {
    srand(time(0));
    std::vector<std::string> album = {"The grand parade of lifeless packaging", "In the cage", "Counting out time", "The lamb lies down on Broadway", "Fly on a windshield", "Back in NYC"};
    std::string choice = "";

    while(true) {
        std::cout << "Do you want to play album shuffled: ";
        std::cin >> choice;

        if(choice == "yes") {
            std::random_shuffle(album.begin(), album.end());
            int n = 1;

            for(auto iter = album.begin(); iter != album.end(); ++iter) {
                std::cout << "Song " << n << ": "<< std::endl;
                std::cout << *iter << std::endl;
                std::cout << std::endl;
                ++n;
            }
        } else {
            std::cout << "Ok, goodby!" << std::endl;
        }
    }

    return 0;
}