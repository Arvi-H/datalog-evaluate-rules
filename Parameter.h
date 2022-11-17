#ifndef PARAMETER
#define PARAMETER

#include <vector>
#include <string>

class Parameter {
private:
    std::string parameter_id;

public:
    // Set Parameter ID  
    void setID(std::string ID);

    // Get Parameter ID  
    std::string getID();

    // Return ID
    std::string toString() const;

    // Is the parameter surrounded by single quotes?
    bool isConstant();
};

#endif