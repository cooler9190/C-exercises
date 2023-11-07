#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

using matrix = std::vector<std::vector<int>>;

int main() {
    int n; // the total number of nodes in the level, including the gateways
    int l; // the number of links
    int e; // the number of exit gateways
    std::cin >> n >> l >> e; std::cin.ignore();
    for (int i = 0; i < l; i++) {
        int n1; // N1 and N2 defines a link between these nodes
        int n2;
        std::cin >> n1 >> n2; std::cin.ignore();
    }

    for (int i = 0; i < e; i++) {
        int ei; // the index of a gateway node
        std::cin >> ei; std::cin.ignore();
    }

    // game loop
    while(1) {
        int si; // The index of the node on which the Bobnet agent is positioned this turn
        std::cin >> si; std::cin.ignore();

        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;


        // Example: 0 1 are the indices of the nodes you wish to sever the link between
        std::cout << "0 1" << std::endl;
    }
}