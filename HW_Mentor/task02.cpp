/*Task2: Design a simple "Box" class that uses templates, so it can hold different data types.
Your class should have the following characteristics:1. A private variable "content" that holds the item inside the box.
2. A public function "setItem()" that sets the value of the item.
3. A public function "getItem()" that gets the value of the item.
Use your Box class to store and retrieve an integer, a float, and a string.*/

/*Task3: Specialize your Box class for a boolean type so that when you try to retrieve the item,
instead of directly returning the content, it prints "The box is empty" when the value is false
and "The box is full" when the value is true.*/

#include <iostream>
#include <string>

template <typename T>
class Box {
    public:
    void setItem(const T& content) {
        m_content = content;
    }

    T getItem() {
        return m_content;
    }

    private:
    T m_content;
};

template <>
class Box<bool> {
    public:
    void setItem(bool content) {
        m_content = content;
    }

    void getItem() {
        if(m_content == true) {
            std::cout << "The box is full" << std::endl;
        } else {
            std::cout << "The box is empty" << std::endl;
        }
    }

    private:
    bool m_content;
};

int main() {
    int a = 0;
    float b = 24.6;
    std::string c = "";

    Box<int> boxInt; 
    Box<float> boxFloat; 
    Box<std::string> boxStr;

    boxInt.setItem(a);
    boxFloat.setItem(b);
    boxStr.setItem(c);

    boxInt.getItem();
    boxFloat.getItem();
    boxStr.getItem();

    Box<bool> boxBool;
    boxBool.setItem(-1);
    boxBool.getItem();

    return 0;
}