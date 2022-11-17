#include "Parameter.h"

void Parameter::setID(std::string ID) {
    parameter_id = ID;
}

std::string Parameter::getID() {
    return Parameter::parameter_id;
}

// Is the parameter surrounded by single quotes?
bool Parameter::isConstant() {
    return (parameter_id.at(0) == '\'') && (parameter_id.at(parameter_id.size() - 1) == '\'');
}

std::string Parameter::toString() const {
    return parameter_id;
}