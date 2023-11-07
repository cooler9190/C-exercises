#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Product {
    public:
    Product (std::string n, int p) {
        name = n;
        price = p;
    }

    inline std::string getName() { return name; }

    inline int getPrice() { return price; }

    private:
    std::string name;
    int price;
};

void printList(std::vector<Product> &vec) {
    for(size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i].getName() << std::endl; 
    }
}

int main() {
    Product p1("Banana", 15), p2("Chocolate", 20), p3("Meat", 8), p4("Salt", 3), p5("Melon", 3);

    std::vector<Product> productList = {p1, p2, p3, p4, p5};

    std::vector<Product> ascendingList = productList, descendingList = productList;

    std::stable_sort(ascendingList.begin(), ascendingList.end(), [](Product p1, Product p2) {return p1.getPrice() < p2.getPrice();});

    std::stable_sort(descendingList.begin(), descendingList.end(), [](Product p1, Product p2) {return p1.getPrice() > p2.getPrice();});

    printList(ascendingList);

    std::cout << std::endl;

    printList(descendingList);

    return 0;
}
