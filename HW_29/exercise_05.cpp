#include <iostream>
#define FORBIDDEN delete;

class Test {
    public:
    Test(const int& data) : m_data(data) {};

    Test(const Test&) = FORBIDDEN;

    Test operator=(const Test&) = FORBIDDEN;

    Test(Test&&) noexcept = FORBIDDEN;

    Test& operator=(Test&&) noexcept = FORBIDDEN;

    private:
    int m_data;
};

int main() {
    int x = 20;

    Test test(x);

    //Test test2(test);

    return 0;
}