#ifndef RULE
#define RULE

#include <vector>
#include <string>
#include <sstream>

#include "Predicate.h"

class Rule {
private:
    Predicate head_id;
    std::vector<Predicate> predicates;
public: 
    // Set the head_id predicate
    void setPredicateHeadID(Predicate ID);

    // Set the predicates vector
    void setPredicates(Predicate ID);
   
    // Get the head ID
    Predicate getID();
   
    // Get the predicates vector
    std::vector<Predicate> getPredicates();

    // Print Predicates
    std::string toString() const;
};

#endif