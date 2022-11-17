#ifndef STRING_AUTOMATON
#define STRING_AUTOMATON

#include "Automaton.h"
#include <iostream>

class StringAutomaton : public Automaton {
public:
    StringAutomaton() : Automaton(TokenType::STRING) {}  // Call the base constructor

    void S0(const std::string& input);
    void S1(const std::string& input);
    void S2(const std::string& input);
};

 

#endif // ID_AUTOMATON