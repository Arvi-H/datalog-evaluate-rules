#ifndef FACTS_AUTOMATON_H
#define FACTS_AUTOMATON_H

#include "Automaton.h"

class FactsAutomaton : public Automaton {
public:
    FactsAutomaton() : Automaton(TokenType::FACTS) {}  // Call the base constructor

    void S0(const std::string& input);
    void S1(const std::string& input);
    void S2(const std::string& input);
    void S3(const std::string& input);
    void S4(const std::string& input);
};

#endif // FACTS_AUTOMATON_H


