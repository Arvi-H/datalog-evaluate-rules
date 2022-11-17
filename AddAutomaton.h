#ifndef ADD_AUTOMATON_H
#define ADD_AUTOMATON_H

#include "Automaton.h"

class AddAutomaton : public Automaton
{
private:
    void S1(const std::string& input);

public:
    AddAutomaton() : Automaton(TokenType::ADD) {}  // Call the base constructor

    void S0(const std::string& input);
};

#endif // ADD_AUTOMATON_H

