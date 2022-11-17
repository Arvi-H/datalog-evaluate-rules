#ifndef AUTOMATON_H
#define AUTOMATON_H
#include "Token.h"

class Automaton
{
protected:
    int newLines = 0;
    int index = 0;
    TokenType type;

public:
    bool terminateFlag = false;
    bool multiline = false;
    int multilineInc = 0;
    int inputRead = 0;
    Automaton() : Automaton(TokenType::UNDEFINED) {}
    Automaton(TokenType type) { this->type = type; }

    virtual ~Automaton() = default;
    
    int Start(const std::string& input) {
        newLines = 0;
        inputRead = 0;
        S0(input);
        return inputRead;
    }

    // Every subclass must define this method
    virtual void S0(const std::string& input) = 0;

    void Serr() {
        // Indicate the input was rejected
        inputRead = 0;
    }

    virtual Token* CreateToken(std::string input, int lineNumber) { return new Token(type, input, lineNumber); }

    int NewLinesRead() const { return newLines; }
};

#endif // AUTOMATON_H

