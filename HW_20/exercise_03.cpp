#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <algorithm>

class FileInfo {
    public:
    FileInfo(const std::string &name) : m_fileName(name) {}
    
    inline std::string getFileName() const{ return m_fileName; };

    private:
    std::string m_fileName;
};

using sharedPtr = std::shared_ptr<FileInfo>;

class FolderInfo {
    public:
    FolderInfo(const std::string &name) : m_folderName(name){}

    inline std::string getFolderName() const{ return m_folderName; };

    inline std::vector<sharedPtr> getFileList() const{ return m_flieList; };

    void addFile(const sharedPtr &file) {
        m_flieList.push_back(file);
    }

    void removeFile(const std::string &fileName) {
        auto iter = std::find_if(m_flieList.begin(), m_flieList.end(), [&](const sharedPtr& val){ return val->getFileName() == fileName; });

        if(iter != m_flieList.end()) {
            m_flieList.erase(iter);
        } else {
            std::cout << fileName << " cannot be found in this folder" << std::endl;
        }
    }

    private:
    std::string m_folderName;
    std::vector<sharedPtr> m_flieList;
};

int main() {
    FolderInfo folder("Homework");

    sharedPtr file1 = std::make_shared<FileInfo> ("HW_01.cpp");
    sharedPtr file2 = std::make_shared<FileInfo> ("HW_02.cpp");
    sharedPtr file3 = std::make_shared<FileInfo> ("HW_03.cpp");

    folder.addFile(file1);
    folder.addFile(file2);
    folder.addFile(file3);

    std::cout << folder.getFolderName() << " contains: " << std::endl;

    for(auto iter : folder.getFileList()) {
        std::cout << iter->getFileName() << std::endl;
    }

    folder.removeFile("HW_04.cpp");

    folder.removeFile("HW_03.cpp");

    for(auto iter : folder.getFileList()) {
        std::cout << iter->getFileName() << std::endl;
    }

    return 0;
}