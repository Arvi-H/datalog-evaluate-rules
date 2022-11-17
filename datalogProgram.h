#ifndef DATALOG_PROGRAM
#define DATALOG_PROGRAM

#include <vector>
#include <set>

#include "Predicate.h"
#include "Rule.h"
#include "Token.h"

class DatalogProgram {
public:
// Set Vectors
    void setSchemes(Predicate scheme);
    void setFacts(Predicate fact);
    void setQueries(Predicate queries);
    void setRules(Rule rule);

    void setFactsDomain(std::string domain);

// Get Vectors
    std::vector<Predicate> getSchemes();

    std::vector<Predicate> getFacts();

    std::vector<Rule> getRules();

    std::vector<Predicate> getQueries();


// Print DataLog Program
    std::string toString();

private:
// Parser Vectors
    std::vector<Predicate> schemes;
    std::vector<Predicate> facts;
    std::vector<Predicate> queries;
    std::vector<Rule> rules;

    std::set<std::string> factsDomain;
};

#endif