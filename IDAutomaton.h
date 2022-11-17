#ifndef ID_AUTOMATON
#define ID_AUTOMATON

#include "Automaton.h"


class IDAutomaton : public Automaton {
public:
    IDAutomaton() : Automaton(TokenType::ID) {}  // Call the base constructor

    void S0(const std::string& input);
    void S1(const std::string& input);
};

#endif // ID_AUTOMATON