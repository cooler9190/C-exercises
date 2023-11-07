#include <iostream>
#include <cstring>
#include <exception>

class String {
    public:
    String() {
        m_str = new char[1];
        m_str[0] = '\0';
        m_length = 0;
    }

    String(const char* &val) {    
        if(val == nullptr) {
            m_str = new char[1];
            m_str[0] = '\0';
            m_length = 0;
        } else {
            m_length = std::strlen(val);
            m_str = new char[m_length + 1];
            std::strcpy(m_str, val);
            m_str[m_length] = '\0';
        }
    }

    String& operator=(const String &str) {
        if(this != &str) {
            free();
            m_length = str.m_length;
            m_str = new char[m_length + 1];
            std::strcpy(m_str, str.m_str);
        }

        return *this;
    }

    ~String() {
        std::cout << "String destroyed!" << std::endl;
        free();
    }

    int length() const { return m_length; };

    char& operator[](const int &index) {
        if(index >= 0 && index <= m_length) {
            return m_str[index];
        } else {
            throw std::out_of_range("Illegal index at function []");
        }
    }

    String operator+(const String &str) const {
        String result;
        result.m_length = m_length + str.m_length;
        result.m_str = new char[result.m_length + 1];
        std::strcpy(result.m_str, m_str);
        std::strcat(result.m_str, str.m_str);
        
        return result;
    }

    bool operator==(const String &str) const {
        return std::strcmp(m_str, str.m_str) == 0;
    }

    bool operator!=(const String &str) const {
        return !(*this == str);
    }

    char* c_str() const { return m_str; }

    void free() {
        if(m_str) {
            delete[] m_str;
            m_str = nullptr;
        }
    } 

    private:
    int m_length;
    char *m_str;
    friend std::ostream& operator<<(std::ostream &o, const String &str);
};

std::ostream& operator<<(std::ostream &o, const String &str) {
    o << str.m_str;
    return o;
}

int main() {
    const char* cstr = "Hello, CodeAcademy!";
    String str1(cstr);
    
    std::cout << str1.length() << std::endl;

    String str2;

    str2 = str1;

    bool isEqual = str2 == str1;

    std::cout << isEqual << std::endl;

    const char* cstr2 = "How are you today?";

    String str3(cstr2);

    str2 = str2 + str3;

    std::cout << str2.length() << " " << str2 << std::endl;

    std::cout << str2[18] << std::endl;     

    return 0;
}