#ifndef QUESTIONUTOMATON_H
#define QUESTIONUTOMATON_H

#include "Automaton.h"

class QuestionAutomaton : public Automaton {
public:
    QuestionAutomaton() : Automaton(TokenType::QUESTION) {}  // Call the base constructor

    void S0(const std::string& input);
};

#endif // QUESTION_AUTOMATON_H

