#ifndef LEXER_H
#define LEXER_H
#include <vector>
#include "Automaton.h"
#include "Token.h"

class Lexer
{
private:
    std::vector<Automaton*> automata;
    std::vector<Token*> tokens;
    Token *newToken;

    void CreateAutomata();
    Automaton *maxAutomata;

public:
    Lexer();
    ~Lexer();

    void Run(std::string& input);
    // void printTotalTokens();
    std::vector<Token*> getTokens();
};

#endif  

