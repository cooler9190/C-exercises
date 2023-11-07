#include <iostream>

template <typename T>
class SharedPointer {
    public:
    SharedPointer(T *p = nullptr) : m_ptr(p), m_counter(new int(1)) {}

    SharedPointer(const SharedPointer &p) : m_ptr(p.m_ptr), m_counter(p.m_counter) {
        ++*m_counter;
    }

    SharedPointer operator=(const SharedPointer &p) {
        if(this != &p) {
            free();

            m_ptr = p.m_ptr;
            m_counter = p.m_counter;
            ++*m_counter;
        }

        return *this; 
    }

    int getCount() const {
        return *m_counter;
    }

    T& operator*() {
        return *m_ptr;
    }

    const T& operator*() const {
        return *m_ptr;
    }

    T* operator->() {
        return m_ptr;
    }  

    ~SharedPointer() {
        free();
    }

    private:
    T* m_ptr;
    int *m_counter;

    void free() {
        *m_counter--;
        if(*m_counter == 0) {
            if(m_ptr) {
                delete m_ptr;
            }
            delete m_counter;
        }
    }
};

int main() {
    int a = 12;
    int* ptr = &a;

    SharedPointer shared1(ptr);

    SharedPointer shared2(shared1);

    std::cout << shared1.getCount() << " " << *shared2 << std::endl;

    return 0;
}