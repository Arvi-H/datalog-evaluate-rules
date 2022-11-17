#include "Predicate.h"

void Predicate::setID(std::string ID) {
    Predicate::predicate_id = ID;
}

void Predicate::addParameter(Parameter p) {
    Parameter param = Parameter(p);
    parameters.push_back(param);
}

std::string Predicate::getID() {
    return Predicate::predicate_id;
}

std::vector<Parameter> Predicate::getParameters() {
    return Predicate::parameters;
}

std::string Predicate::toString() const {
    std::stringstream out;

    std::string seperate = "";
    out << predicate_id << "(";
    for (Parameter curr : parameters) {
        out << seperate << curr.toString();
        seperate = ",";
    }
    out << ")";

    return out.str();
}
