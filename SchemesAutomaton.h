#ifndef SCHEMES_AUTOMATON_H
#define SCHEMES_AUTOMATON_H

#include "Automaton.h"

class SchemesAutomaton : public Automaton {
public:
    SchemesAutomaton() : Automaton(TokenType::SCHEMES) {}  // Call the base constructor

    void S0(const std::string& input);
    void S1(const std::string& input);
    void S2(const std::string& input);
    void S3(const std::string& input);
    void S4(const std::string& input);
    void S5(const std::string& input);
    void S6(const std::string& input);
};

#endif // SCHEMES_AUTOMATON_H


