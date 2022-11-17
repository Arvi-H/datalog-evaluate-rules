#include "Rule.h"

void Rule::setPredicateHeadID(Predicate p) {
    head_id = p;
}

void Rule::setPredicates(Predicate p) {
    predicates.push_back(p);
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
 