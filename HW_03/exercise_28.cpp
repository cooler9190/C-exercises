#include <iostream>
#include <string>
#include <cctype>

double addToShoppingCart(int quantity, std::string product) {
    double total = 0;
    
    if(product == "avocado") {
        total += quantity * 1.23;
    } else if(product == "oil") {
        total += quantity * 2.53;
    } else if(product == "tomatoes") {
        total += quantity * 0.27;
    } else if(product == "onions") {
        total += quantity * 0.15;
    } else if(product == "lemons") {
        total += quantity * 8.99;
    } else {
        std::cout << "There is no such product" << std::endl;
    }

    return total;
}

int main () {
    int quantity = 0; 
    double total = 0;
    std::string product = "";

    std::cout << "Welcome to C++ super market!" << std::endl;
    std::cout << "Out list of products include: Avocado, bottle of oil, tomatoes, onions and lemons" << std::endl;

    while(true) {
        std::cout << "Please choose a product and quantity to add to your shopping cart:" << std::endl;
        std::cin >> product >> quantity;
    
        if(std::cin.fail()) {
            bool flag = false;
            while(!flag) {
                flag = true;
                std::cin.clear();
                std::cin.ignore();
                std::cout << "Wrong input!" << std::endl;
                std::cout << "Please try again: ";
                std::cin >> quantity;

                if(std::cin.fail()) {
                    std::cout << "Please enter only integers for the quantity!" << std::endl;
                    flag = false;
                }
            }
        }

        for(int i = 0; i < product.size(); i++) {
            if(isupper(product[i])) {
                product[i] = tolower(product[i]);
            }
        }

        total += addToShoppingCart(quantity, product); 

        std::cout << "Total amount of shopping cart is: "<< total << std::endl;

    }

    return 0;
}