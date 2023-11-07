#include <iostream>
#include <memory>
#include <string>
#include <vector>

using sharedPtr = std::shared_ptr<std::string>;

class Cache {
    public:
    sharedPtr getName(const std::string &name) {
        auto myIter = namesPtrList.end();
        for(auto iter = namesPtrList.begin(); iter != namesPtrList.end(); ++iter) {
            if(**iter == name) {
                myIter = iter;
                break;
            }
        }

        if(myIter != namesPtrList.end()) {
            return *myIter;
        } else {
            sharedPtr newName = std::make_shared<std::string> (name);
            namesPtrList.push_back(newName);
            
            return newName;
        }
    }
    
    private:
    std::vector<sharedPtr> namesPtrList;
};


int main() {
    Cache nameCache;

    sharedPtr name1 = nameCache.getName("Nick");
    sharedPtr name2 = nameCache.getName("Mary");
    sharedPtr name3 = nameCache.getName("John");
    sharedPtr name4 = nameCache.getName("Nick");
    sharedPtr name5 = nameCache.getName("Linda");

    std::cout << *name1 << " " << *name2 << " " << *name3 << " " << *name4 << " " << *name5 << std::endl;

    *name1 = "Roger";

    std::cout << *name1 << " " << *name2 << " " << *name3 << " " << *name4 << " " << *name5 << std::endl;

    return 0;
}