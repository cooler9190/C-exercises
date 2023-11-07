#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

enum Priority {
    normalPrio = 1,
    highPrio
};

enum Status {
    UNPROCESSED = 1,
    PENDING,
};

class Order {
    public:
    Order(std::string id, Priority prio, Status stat) {
        orderID = id;
        priority = prio;
        status = stat;
    }

    std::string getID () {
        return orderID;
    }

    Priority getPriority() {
        return priority;
    }

    Status getStatus() {
        return status;
    }

    private:
    std::string orderID;
    Priority priority;
    Status status;
};

typedef bool (*sortByType)(Order &order1, Order &order2);

void bubbleSort(std::vector<Order> &vec, sortByType type) {
    bool inversion = true;
    int i = 0;

    while(inversion){

        inversion = false;
        for(size_t j = 0; j < vec.size() - (1 + i); ++j){
            if(type(vec[j], vec[j + 1]) == 1){
                std::swap(vec[j], vec[j + 1]);
                inversion = true;
            }
        }

        ++i;
    }
}

bool sortByPrio(Order &order1, Order &order2){
    if(order1.getPriority() < order2.getPriority()) {
        return true;
    } else {
        return false;
    }
}

bool sortByStat(Order &order1, Order &order2){
    if(order1.getStatus() < order2.getStatus()) {
        return true;
    } else {
        return false;
    }
}

void printOrders(std::vector<Order> &orders) {
    for(size_t i = 0; i < orders.size(); ++i) {
        std::cout << orders[i].getID() << " ";
    }

    std::cout << std::endl;
}
      

int main() {
    Order p1("0X1", highPrio, UNPROCESSED), p2("0X2", normalPrio, UNPROCESSED), p3("0X3", normalPrio, PENDING), p4("0X4", highPrio, PENDING), p5("0X5", highPrio, UNPROCESSED), p6("0X6", normalPrio, PENDING);
    std::vector<Order> vec = {p1, p2, p3, p4, p5, p6};

    printOrders(vec);

    bubbleSort(vec, sortByPrio);

    printOrders(vec);

    bubbleSort(vec, sortByStat);

    printOrders(vec);

    return 0;
}