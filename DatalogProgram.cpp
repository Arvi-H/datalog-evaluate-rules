#include "DatalogProgram.h"

// Push predicate to the schemes vectors.
void DatalogProgram::setSchemes(Predicate scheme) {
    DatalogProgram::schemes.push_back(scheme);
}

// Push predicate to the facts vectors.
void DatalogProgram::setFacts(Predicate fact) {
    DatalogProgram::facts.push_back(fact);
}

// Push to the facts domain
void DatalogProgram::setFactsDomain(std::string domain) {
    factsDomain.insert(domain);
}

// Push predicate to the queries vectors.
void DatalogProgram::setQueries(Predicate query) {
    DatalogProgram::queries.push_back(query);
}

// Push rule to the rules vector
void DatalogProgram::setRules(Rule rule) {
    DatalogProgram::rules.push_back(rule);
}
 
// Get Schemes
std::vector<Predicate> DatalogProgram::getSchemes() {
    return DatalogProgram::schemes;
}

// Get Facts
std::vector<Predicate> DatalogProgram::getFacts() {
    return DatalogProgram::facts;
}

// Get Rules
std::vector<Rule> DatalogProgram::getRules() {
    return DatalogProgram::rules;
}

// Get Queries
std::vector<Predicate> DatalogProgram::getQueries() {
    return DatalogProgram::queries;
}


// Print Datalog Program
std::string DatalogProgram::toString() {
    std::stringstream out;
    // Printing the schemes vector
    out << "Schemes(" << schemes.size() << "):" << std::endl;
    for (Predicate scheme : schemes) {
        out << "  " << scheme.toString() << std::endl;
    } 
    
    // Printing the facts vector
    out << "Facts(" << facts.size() << "):" << std::endl;
    for (Predicate fact : facts) {
        out << "  " << fact.toString() << "." << std::endl;
    }  

    // Printing the rules vector
    out << "Rules(" << rules.size() << "):" << std::endl;
    for (Rule rule : rules) {
        out << "  " << rule.toString() << "." << std::endl;
    } 

    // Printing the queries vector
    out << "Queries(" << queries.size() << "):" << std::endl;
    for (Predicate query : queries) {
        out << "  " << query.toString() << "?" << std::endl;
    }

    // Printing the domain set list
    out << "Domain(" << factsDomain.size() << "):" << std::endl;
    for (std::string s : factsDomain) {
        out << "  " << s << std::endl;
    }

    return out.str();
}