#include <iostream>

using size = signed int;

void fillSpiralMatrix(int** matrix, const size_t &n) {
    int element = 0;
    size rowStart = 0, rowEnd = n - 1, colStart = 0, colEnd = n - 1;

    while(rowStart <= rowEnd && colStart <= colEnd) {
        for(size j = colStart; j <= colEnd; ++j) {
            //*((matrix + rowStart * n) + j) = element;
            matrix[rowStart][j] = element % 10;
            ++element;
        }

        ++rowStart;

        for(size i = rowStart; i <= rowEnd; ++i) {
            //*((matrix + i * n) + colEnd) = element;
            matrix[i][colEnd] = element % 10;
            ++element;
        }

        --colEnd;

        if(rowStart <= rowEnd) {
            for(size x = colEnd; x >= colStart; --x) {
                //*((matrix + rowEnd * n) + x) = element;
                matrix[rowEnd][x] = element % 10;
                ++element;
            }

            --rowEnd;
        }

        if(colStart <= colEnd) {
            for(size y = rowEnd; y >= rowStart; --y) {
               //*((matrix + y * n) + colStart) = element;
               matrix[y][colStart] = element % 10;
                ++element;
            }

            ++colStart;
        }
    }
}

void printMatrix(int** matrix, size_t n) {
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    std::size_t n = 0;
    std::cout << "Please enter the size of the matrix: ";
    std::cin >> n;
    // 
    
    //Alocating new memeory for matrix
    int** matrix = new int*[n];
    for(size_t i = 0; i < n; ++i) {
        matrix[i] = new int[n];
    }
    
    fillSpiralMatrix(matrix, n);

    printMatrix(matrix, n);

    //Dealocating memory
    for(size_t i = 0; i < n; ++i) {
        delete[] matrix[i];
    }

    delete[] matrix;

    return 0;
}