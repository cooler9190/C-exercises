#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

class FileHanlder {
    public:
    FileHanlder(const std::string &file) : m_file(file) {
        if(!m_file.is_open()) {
            std::cout << "Unable to open file!" << std::endl;
        }
    }

    ~FileHanlder() {
        if(m_file.is_open()) {
            m_file.close();
        }
    }

    FileHanlder(const FileHanlder &file) = delete;
    FileHanlder& operator=(const FileHanlder &file) = delete;

    FileHanlder(FileHanlder&& otherFile) noexcept : m_file{std::move(otherFile.m_file)} {}

    FileHanlder& operator=(FileHanlder&& otherFile) noexcept {
        if(this != &otherFile) {
            m_file = std::move(otherFile.m_file);
        }

        return *this;
    }

    void printContent() {
        if(m_file.is_open()) {
            std::string line = "";
            while(std::getline(m_file, line)) {
                std::cout << line << std::endl;
            }

            m_file.clear();
            m_file.seekg(0);
        } else {
            std::cout << "Unable to open file!" << std::endl;
        }
    }

    void changeContent(const std::string &newLine, const std::string &lineToChange = "") {
        if(m_file.is_open()) {
            std::vector<std::string> data;
            std::string line = "";

            while(std::getline(m_file, line)) {
                data.push_back(line);
            }

            m_file.clear();
            m_file.seekg(0);

            auto pos = std::find_if(data.begin(), data.end(), [&](const std::string &val){ return val == lineToChange; });
            if(pos != data.end()) {
                *pos = newLine;
            } else {
                data.push_back(newLine);
            }

            for(auto iter = data.begin(); iter != data.end(); ++iter) {
                m_file << *iter << std::endl;
            }

            m_file.clear();
            m_file.seekg(0);

        } else {
            std::cout << "Unable to open file!" << std::endl;
        }
    }

    private:
    std::fstream m_file;
};

int main() {
    FileHanlder file("test.txt");
    file.printContent();
    std::cout << std::endl;
    file.changeContent("What's up?", "How are you doing?");
    file.changeContent("There's a lot of work to do :(");
    file.printContent();

    return 0;
}