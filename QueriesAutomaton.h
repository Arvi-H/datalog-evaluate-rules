#ifndef QUERIES_AUTOMATON_H
#define QUERIES_AUTOMATON_H

#include "Automaton.h"

class QueriesAutomaton : public Automaton {
public:
    QueriesAutomaton() : Automaton(TokenType::QUERIES) {}  // Call the base constructor

    void S0(const std::string& input);
    void S1(const std::string& input);
    void S2(const std::string& input);
    void S3(const std::string& input);
    void S4(const std::string& input);
    void S5(const std::string& input);
    void S6(const std::string& input);
};

#endif // QUERIES_AUTOMATON_H


