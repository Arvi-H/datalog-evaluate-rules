#ifndef PARSER
#define PARSER

#include <vector>
#include <string>
#include <iostream>
#include "DatalogProgram.h"
#include "Lexer.h"

class Parser {
public:
    // Constructor to assign all objects with a vector of tokens
    Parser(const std::vector<Token*> t);
   
    // Match Tokens
    void match(TokenType t);
   
    // Skip Comments
    void skipComments();
   

    // Grammar Rules
    void dataLogProgram();
    void scheme();
    void schemeList();
    void fact();
    void factList();
    void rule();
    void ruleList();
    void query();
    void queryList();
    void idList(Predicate& predicate);
    void stringList(Predicate& predicate);
    void predicate(Predicate& predicate);
    void headPredicate(Predicate& predicate);
    void predicateList(Rule& rule);
    void parameter(Predicate& predicate);
    void parameterList(Predicate& predicate);

    // Begin Parsing here
    DatalogProgram Parse();
private:
    std::vector<Token*> tokens;
    DatalogProgram program;
  
    // Index counter
    int index = 0;
};

#endif