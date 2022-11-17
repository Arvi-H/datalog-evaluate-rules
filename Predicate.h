#ifndef PREDICATE
#define PREDICATE

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "Parameter.h"

class Predicate {
private:
    std::vector<Parameter> parameters;
    std::string predicate_id;

public:
    // Add parameter to the paramteres vector
    void addParameter(Parameter p); 

    // Set Predicate ID
    void setID(std::string ID);
    
    // Return predicate_id
    std::string getID();

    // Return parameter list
    std::vector<Parameter> getParameters();

    // Print Parameters
    std::string toString() const; 
};

#endif