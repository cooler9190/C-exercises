/*Exercise 01: Generic Stack ClassCreate a generic Stack class. This Stack should be able to store any data type, 
including classes and structures.
It should have the following methods:push(T item): Adds an item to the top of the stack.
T pop(): Removes and returns the top item from the stack.
bool isEmpty(): Returns true if the stack is empty, false otherwise.
Try creating stacks of different types and use the push and pop methods.*/

#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>

template <typename T>
class Stack {
    public:
    Stack() = default;

    void push(const T& item) {
        m_container.push_back(item);
    }

    T pop() {
        if(m_container.empty()) {
            throw std::out_of_range("The stack is empty, unable to use operation pop!");
        }
        
        T item = m_container.back();
        m_container.pop_back();

        return item;
    }

    bool isEmpty() {
        return m_container.empty();
    }

    private:
    std::vector<T> m_container;
};

int main() {
    Stack<int> iStack;
    Stack<float> fStack;
    Stack<std::string> strStack;
    Stack<char> cStack;

    iStack.push(10);
    iStack.push(20);
    iStack.push(30);

    iStack.pop();

    std::cout << iStack.isEmpty() << std::endl;

    fStack.push(3.14);
    fStack.pop();

    std::cout << fStack.isEmpty() << std::endl;

    strStack.push("Hello!");
    strStack.pop();

    return 0;
}