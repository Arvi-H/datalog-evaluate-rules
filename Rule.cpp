#include "Rule.h"

void Rule::setPredicateHeadID(Predicate p) {
    head_id = p;
}

void Rule::setPredicates(Predicate p) {
    predicates.push_back(p);
}

// Get the head ID
Predicate Rule::getID() {
    return Rule::head_id;
}

// Get the predicates vector
std::vector<Predicate> Rule::getPredicates() {
    return Rule::predicates;
}

std::string Rule::toString() const {
    std::string seperator = "";
    std::stringstream out;
   
    out << head_id.toString() << " :- ";
    for (Predicate currPred : predicates) {
        out << seperator << currPred.toString();
        seperator = ",";
    }
    
    return out.str();
}
 