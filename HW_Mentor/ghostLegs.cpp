#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using matrix = std::vector<std::string>;

void printLabels(const matrix &matr) {
    for(size_t i = 0; i < matr[0].size(); ++i) {
        if(matr[0][i] != ' ') {
            size_t currentI = i;
            char topLabel = matr[0][i];

            for(size_t j = 1; j < matr.size(); ++j) {
                if(matr[j][i] == '|') {
                    if(i != (matr[0].size() - 1) && matr[j][i + 1] == '-') {
                        i += 3;
                    } else if(i != 0 && matr[j][i - 1] == '-') {
                        i -= 3;
                    } else {
                        continue;
                    }
                } else {
                    char bottomLabel = matr[j][i];
                    std::string label = "";
                    label += topLabel;
                    label += bottomLabel;
                    i = currentI + 2;

                    std::cout << label << std::endl;
                }
            }
        } else {
            continue;
        }
    }
}

int main() {
    int w;
    int h;
    std::cin >> w >> h; std::cin.ignore();
    matrix matrix;

    for (int i = 0; i < h; i++) {
        std::string line;
        std::getline(std::cin, line);
        matrix.push_back(line);
    }    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;    cout << "answer" << endl;

    printLabels(matrix);

    return 0;
}