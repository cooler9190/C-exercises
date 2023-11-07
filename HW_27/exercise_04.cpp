#include <iostream>

template <class T>
class UniquePointer {
    public:
    UniquePointer<T>(T *p = nullptr) noexcept : m_ptr(p) {}

    ~UniquePointer() {
        delete m_ptr;
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

    T operator*() {
        return *m_ptr;
    }

    const T operator*() const {
        return *m_ptr;
    }

    T* operator->() {
        return m_ptr;
    }

    private:
    T *m_ptr;
};

int main() {
    int a = 15;
    int* ptr = &a;

    int* ptr2 = nullptr;

    //pass class 
    UniquePointer unique1(ptr);

    UniquePointer unique2(ptr2);

    unique2 = std::move(unique1);

    std::cout << *unique2 << std::endl;

    return 0;
}