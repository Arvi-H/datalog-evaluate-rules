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

    std::vector<std::string> getAttributes() {
        return columnNames;
    }

    unsigned int findColumn(std::string column) const {
        for (unsigned int i = 0; i < columnNames.size(); i++) {
            if (columnNames.at(i) == column) {
                return i;
            }
        }

        return 0;
    }
    
private:
    std::vector<std::string> columnNames;
};
 

#endif