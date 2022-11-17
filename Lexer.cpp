#include "Lexer.h"
#include "ColonAutomaton.h"
#include "ColonDashAutomaton.h"
#include "CommaAutomaton.h"
#include "PeriodAutomaton.h"
#include "QuestionAutomaton.h"
#include "RightParenAutomaton.h"
#include "LeftParenAutomaton.h"
#include "SchemesAutomaton.h"
#include "FactsAutomaton.h"
#include "RulesAutomaton.h"
#include "QueriesAutomaton.h"
#include "IDAutomaton.h"
#include "StringAutomaton.h"
#include "CommentAutomaton.h"
#include "EOFAutomaton.h"
#include "AddAutomaton.h"
#include "MultiplyAutomaton.h"
#include <iostream>
#include <fstream>
#include <sstream>

Lexer::Lexer() {
    CreateAutomata();
}

Lexer::~Lexer() {
    // Deallocate tokens memeory
    int tokenNum = tokens.size();
    for (int i = 0; i < tokenNum; i++) {
        delete tokens.at(i);
    }

    tokens.clear();

    // Deallocate automatas memeory
    int automatonNum = automata.size();
    for (int i = 0; i < automatonNum; i++) {
        delete automata.at(i);
    }

    automata.clear();
}

void Lexer::CreateAutomata() {
    automata.push_back(new ColonAutomaton());
    automata.push_back(new ColonDashAutomaton());
    automata.push_back(new CommaAutomaton());
    automata.push_back(new PeriodAutomaton());
    automata.push_back(new QuestionAutomaton());
    automata.push_back(new AddAutomaton());
    automata.push_back(new MultiplyAutomaton());
    automata.push_back(new RightParenAutomaton());
    automata.push_back(new LeftParenAutomaton());
    automata.push_back(new SchemesAutomaton());
    automata.push_back(new FactsAutomaton());
    automata.push_back(new RulesAutomaton());
    automata.push_back(new QueriesAutomaton());
    automata.push_back(new IDAutomaton());
    automata.push_back(new StringAutomaton());
    automata.push_back(new CommentAutomaton());
    automata.push_back(new EOFAutomaton());
}

void Lexer::Run(std::string& input) {
    int lineNumber = 1;

    if (input.empty()) {
        newToken = new Token(TokenType::ENDFILE, "", lineNumber);
        tokens.push_back(newToken);
        return;
    }  

// Parallel and Max Alg
    while (input.size() > 0) {
        int maxRead = 0;
        maxAutomata = automata.at(0);
        
        
    // You need to handle whitespace in between tokens
        while (isspace(input.at(0))) {
        // Increment line number
            if (input.at(0) == '\n') {
                lineNumber++; 
            }

        // Remove Whitespace
            input.erase(0,1); 

        // Check for an empty file
            if (input.empty()) {  
                newToken = new Token(TokenType::ENDFILE, "", lineNumber);
                tokens.push_back(newToken);
                return;
            }  
        }  

    // Each automaton runs with the same input
        for (Automaton *automaton : automata) {
            int inputRead = automaton->Start(input);
            
            // Figure out the max automata
            if (inputRead > maxRead) {
                maxRead = inputRead;
                maxAutomata = automaton;
            } 
        }  
        
    // Check to see if String or Comment are never terminated
        if (maxAutomata->terminateFlag == true) {
            maxRead += maxAutomata->inputRead;

            std::string test = input.substr(0, maxRead);
       
            newToken = new Token(TokenType::UNDEFINED, test, lineNumber);
            tokens.push_back(newToken);
            
            if (maxAutomata->multiline) {
                lineNumber += maxAutomata->multilineInc;
            } 

            newToken = new Token(TokenType::ENDFILE, "", lineNumber);
            tokens.push_back(newToken);
            
            return;
        }
        
    // Here is the "Max" part of the algorithm
        if (maxRead > 0) {
            newToken = maxAutomata->CreateToken(input.substr(0, maxRead), lineNumber);
            lineNumber += maxAutomata->NewLinesRead();
            
    // No automaton accepted input
        } else {
            maxRead = 1;
            std::string test = input.substr(0, maxRead);
            newToken = new Token(TokenType::UNDEFINED, test, lineNumber);
        }

        if (maxAutomata->multiline) {
            lineNumber += maxAutomata->multilineInc;
        } 
         
    // Update input by removing characters read to create Token
        tokens.push_back(newToken);
        input.erase(0, maxRead);
    }
}

/*
void Lexer::printTotalTokens() {
    int totalTokens = tokens.size();
    while (!tokens.empty()) {
        std::cout << tokens.front()->toString() << std::endl;
        tokens.erase(tokens.begin());
    }
    std::cout << "Total Tokens = " << totalTokens << std::endl;
}
*/  

std::vector<Token*> Lexer::getTokens() {
    return tokens;
}