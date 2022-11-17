#ifndef COMMENT_AUTOMATON
#define COMMENT_AUTOMATON

#include "Automaton.h"


class CommentAutomaton : public Automaton {
public:
    CommentAutomaton() : Automaton(TokenType::COMMENT) {}  // Call the base constructor

    // bool multiLineComment = false;

    void S0(const std::string& input);
    void S1(const std::string& input);
    void S2(const std::string& input);
    void S3(const std::string& input);
    void S4(const std::string& input);
};

#endif // ID_AUTOMATON