#ifndef TUPLE
#define TUPLE

#include "Header.h"
#include <vector>
#include <string>
#include <sstream>

class Tuple {
public:
    Tuple() = default;
    Tuple (std::vector<std::string> values) : rowValues(values) {}
    
    bool operator< (const Tuple t) const {
        return rowValues < t.rowValues;
    }
    
    std::string findValue(int index) {
        int size = rowValues.size();

        if (index > size) {
            throw "Ouf of bounds";
        }
        return rowValues.at(index);
    }

    void addValue(std::string value) {
        rowValues.push_back(value);
    }

    int getTupleSize() {
        return rowValues.size();
    }

    std::string toString(Header header) {
        if (getTupleSize() != header.getHeaderSize()) {
            throw "Tuple size has to equal Header size!";
        }
        std::stringstream out;
        std::string sep = "";
        for (int i = 0; i < getTupleSize(); i++) {
            out << sep << " " << header.findAttribute(i) << "=" << findValue(i);
            sep = ",";
        }
        return out.str();
    }
       
private:
    std::vector<std::string> rowValues;
};

#endif