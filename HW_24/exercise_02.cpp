#include <iostream>
#include <functional>

class Deleter {
    public:
    void operator()(int* ptr) const {
        delete ptr;
    }
};

class UniquePointer {
    public:
    explicit UniquePointer(int *p = nullptr) noexcept : m_ptr(p) {}

    ~UniquePointer() {
        deleter(m_ptr);
    }

    UniquePointer(const UniquePointer &) = delete;

    UniquePointer& operator=(const UniquePointer &) = delete;

    UniquePointer(UniquePointer&& p) noexcept : m_ptr(p.m_ptr) {
        p.m_ptr = nullptr;
    }

    UniquePointer& operator=(UniquePointer&& p) noexcept {
        if(this != &p) {
            delete m_ptr;
            m_ptr = p.m_ptr;
            p.m_ptr = nullptr;
        }

        return *this;
    }

    int operator*() {
        return *m_ptr;
    }

    const int operator*() const {
        return *m_ptr;
    }

    int* operator->() {
        return m_ptr;
    }

    private:
    int *m_ptr;
    Deleter deleter;
};

int main() {
    int a = 15;
    int* ptr = &a;

    UniquePointer unique1(ptr);

    UniquePointer unique2;

    unique2 = std::move(unique1);

    std::cout << *unique2 << std::endl;

    return 0;
}