#include <iostream>
#include <string>
#include <vector>

class InventoryProduct {
public:
    std::string productName;
    double price;
    int quantity;
};

class Innventory {
public:
    std::vector<InventoryProduct> produtcs;
};

void setProduct(InventoryProduct &product, std::string name, double price, int quantity) {
    product.productName = name;
    product.price = price;
    product.quantity = quantity;
}

void setInventory(Innventory &inv, InventoryProduct product) {
    inv.produtcs.push_back(product);
}

void addProduct(InventoryProduct &product) {
    std::string name = " ";
    double price = 0;
    int quantity = 0;

    std::cout << "Enter the name, price and quantity of the product you wish to add: ";
    std::cin >> name >> price >> quantity;

    setProduct(product, name, price, quantity);
}

void changeQuantity(Innventory &inv) {
    std::string product = "";
    int amount = 0;
    std::cout << "Which product's quantity do you want to change? ";
    std::cin >> product;
    std::cout << "And what is the amount you wish to set? ";
    std::cin >> amount;

    for(int i = 0; i < inv.produtcs.size(); ++i) {
        if(inv.produtcs[i].productName == product) {
            inv.produtcs[i].quantity = amount;
        }
    }
}

double printTotalSum(Innventory inv) {
    double sum = 0;
    for(int i = 0; i < inv.produtcs.size(); ++i) {
        sum += inv.produtcs[i].price * inv.produtcs[i].quantity;
    }

    return sum;
}

int main() {
    Innventory inventory;
    InventoryProduct pepper, bottleOfOil, bread, chilli, meat, product;
    std::string command = "";

    setProduct(pepper, "Pepper", 4.69, 5);
    setProduct(bottleOfOil, "Oil", 69, 36);
    setProduct(bread, "Bread", 3.3, 30);
    setProduct(chilli, "Chilli", 1.89, 20);
    setProduct(meat, "Meat", 7.85, 40);

    setInventory(inventory, pepper);
    setInventory(inventory, bottleOfOil);
    setInventory(inventory, bread);
    setInventory(inventory, chilli);
    setInventory(inventory, meat);

    std::cout << "Welcome to our console inventory!" << std::endl;

    while(true) {
        std::cout << "What action would you like to perform? (Add, Total, Change, End): ";
        std::cin >> command;

        if(command == "Add") {
            addProduct(product);
            setInventory(inventory, product);
        } else if(command == "Total") {
            std::cout << "The total sum of the whole inventory is: " << printTotalSum(inventory) << std::endl;
        } else if(command == "Change") {
            changeQuantity(inventory);
        } else if(command == "End") {
            std::cout << "Goodbye!" << std::endl;
            break;
        } else {
            std::cout << "There is no such command!" << std::endl;
            break;
        }
    }

    return 0;
}