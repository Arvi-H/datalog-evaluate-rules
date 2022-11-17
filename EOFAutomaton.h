#ifndef ENDFILEAUTOMATON_H
#define ENDFILEAUTOMATON_H

#include "Automaton.h"

class EOFAutomaton : public Automaton {
public:
    EOFAutomaton() : Automaton(TokenType::ENDFILE) {}  // Call the base constructor

    void S0(const std::string& input);
};

#endif // COLONAUTOMATON_H

