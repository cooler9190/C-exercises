#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

//stacks, for cycle from 1 to the number of disks 

class Towers {
    public:
    Towers() = default;

    void setRods(const int &numberOfDisks) {
        for(signed int i = numberOfDisks; i > 0; --i) {
            srcRod.push_back(i);
        }
    }

    void printTowers() {
        for(signed int i = srcRod.size() - 1; i >= 0; --i) {
            std::cout << srcRod[i] << " " << "|" << " " << "|" << std::endl;
        }
        std::cout << std::endl;
        std::cout << 1 << " " << 2 << " " << 3 << std::endl;
    }

    void moveDisk(std::vector<int> &vec1, std::vector<int> &vec2) {
        if(vec2.empty() || (!vec1.empty() && vec1.back() < vec2.back())) {
            vec2.push_back(vec1.back());
            vec1.pop_back();
        } else {
            moveDisk(vec2, vec1);
        }
    }

    void solvePuzzle(const int &numOfDisks) {
        int move = 1, totalMoves = pow(2, srcRod.size()) - 1;
        bool flag = false;

        if(numOfDisks % 2 == 0) {
            flag = true;
        }
        while(move <= totalMoves) {
            if(move % 3 == 0) {
                if(flag == true) {
                    moveDisk(destRod, tmpRod);
                } else {
                    moveDisk(tmpRod, destRod);
                }
            } else if(move % 3 == 1) {
                if(flag == true) {
                    moveDisk(srcRod, tmpRod);
                } else {
                    moveDisk(srcRod, destRod);
                }
            } else {
                if(flag == true) {
                    moveDisk(srcRod, destRod);
                } else {
                    moveDisk(srcRod, tmpRod);
                }
            }
            ++move;
        }

        for(signed int i = destRod.size() - 1; i >= 0; --i) {
            std::cout << "| " << destRod[i] << " |" << std::endl;
        }
        std::cout << std::endl;
        std::cout << 1 << " " << 2 << " " << 3 << std::endl;
    }

    private:
    std::vector<int> srcRod, destRod, tmpRod;
    int rodNum;
};


int main() {
    Towers hanoi;
    int diskNumber = 0;

    std::cout << "Please enter the number of disks: ";
    std::cin >> diskNumber;

    hanoi.setRods(diskNumber);

    hanoi.printTowers();

    std::cout << std::endl;

    hanoi.solvePuzzle(diskNumber);

    return 0;
}