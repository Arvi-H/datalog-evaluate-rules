#ifndef HEADER
#define HEADER

#include <iostream>
#include <vector>
#include <string>

class Header {
public:
    // Set attributes
    Header() = default;
    Header(std::vector<std::string> attributes) : columnNames(attributes) {}
    
    void addAttribute(std::string attribute) {
        columnNames.push_back(attribute);
    }
    
    std::string findAttribute(int index) {
        int size = columnNames.size();

        if (index > size) {
            throw "Out of Bounds";
        } 

        return columnNames.at(index);
    }

    int getHeaderSize() {
        return columnNames.size();
    }
    
private:
    std::vector<std::string> columnNames;
};
 

#endif