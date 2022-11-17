#include "Parser.h" 

// Constructor to copy the vector of tokens
Parser::Parser(const std::vector<Token*> tokensCopy) {
    for (auto i : tokensCopy){
        tokens.push_back(i);
    }
}

// Start Parser
DatalogProgram Parser::Parse() {
    dataLogProgram();
    return program;
}

// Useful function to check if the tokentype argument matches the tokentype of the vector at that index
void Parser::match(TokenType t) { 
    // Check for End of File
    if (tokens.at(index)->getTokenType() == TokenType::ENDFILE) {
        return;
    }
    
    // Check to see if the tokentype matches 
    if (t == tokens.at(index)->getTokenType()) {
        index++;
        skipComments();
    } else {
        throw(tokens[index]);
    }
}


// Useful function to skip over the comment tokens
void Parser::skipComments() {
    if (tokens.at(index)->getTokenType() == TokenType::COMMENT) { 
        index++; 
    }

    if (tokens.at(index)->getTokenType() == TokenType::COMMENT) { 
        skipComments(); 
    }
}

// datalogProgram  ->  SCHEMES COLON scheme schemeList FACTS COLON factList RULES COLON ruleList QUERIES COLON query queryList EOF
void Parser::dataLogProgram() {
// Check for comments
    skipComments();
// Schemes
    match(TokenType::SCHEMES);
    match(TokenType::COLON);
    scheme();
    schemeList();
// Facts
    match(TokenType::FACTS);
    match(TokenType::COLON);
    factList();
// Rules    
    match(TokenType::RULES);
    match(TokenType::COLON);
    ruleList();
// Queries
    match(TokenType::QUERIES);
    match(TokenType::COLON);
    query();
    queryList();
// EOF
    match(TokenType::ENDFILE);
}

// scheme  ->  ID LEFT_PAREN ID idList RIGHT_PAREN
void Parser::scheme() {
    Predicate scheme;
    Parameter parameter;
    
    // Check for ID
    match(TokenType::ID);
    scheme.setID(tokens.at(index-1)->getTokenDescription());
    
    // Check for Left Paren
    match(TokenType::LEFT_PAREN);

    // Check for ID
    match(TokenType::ID);

    // Add Param
    parameter.setID(tokens.at(index-1)->getTokenDescription());
    scheme.addParameter(parameter);

    // Call idList
    idList(scheme);

    // Check for Right Paren
    match(TokenType::RIGHT_PAREN);

    // Push the scheme
    program.setSchemes(scheme);
}

// schemeList  ->  scheme schemeList | lambda
void Parser::schemeList() {
    if (tokens.at(index)->getTokenType() == TokenType::ID) {
        scheme();
        schemeList();
    }
}

//fact  ->  ID LEFT_PAREN STRING stringList RIGHT_PAREN PERIOD
void Parser::fact() {
    Predicate fact;
    Parameter parameter;
    
    // Check for ID
    match(TokenType::ID);
    fact.setID(tokens.at(index-1)->getTokenDescription());
    
    // Check for Left Paren
    match(TokenType::LEFT_PAREN);

    // Check for String
    match(TokenType::STRING);
    program.setFactsDomain(tokens.at(index-1)->getTokenDescription());
    
    // Add Param
    parameter.setID(tokens.at(index - 1)->getTokenDescription());
    fact.addParameter(parameter);

    // Call stringList
    stringList(fact);

    // Check for Right Paren
    match(TokenType::RIGHT_PAREN);

    // Check for Period
    match(TokenType::PERIOD);

    program.setFacts(fact);
}

// factList  ->  fact factList | lambda
void Parser::factList() {
    if (tokens.at(index)->getTokenType() == TokenType::ID) {
        fact();
        factList();
    }
}

// rule  ->  headPredicate COLON_DASH predicate predicateList PERIOD
void Parser::rule() {
    Predicate ruleHead;
    Predicate rules;
    Rule rule;

    // Call headPredicate
    headPredicate(ruleHead);

    // Set Rule Head
    rule.setPredicateHeadID(ruleHead);
    
    // Check for COLON DASH
    match(TokenType::COLON_DASH);

    // Call predicate
    predicate(rules);

    // Set Rule vector of Predicates
    rule.setPredicates(rules);

    // Call predicateList
    predicateList(rule);

    // Check for Period
    match(TokenType::PERIOD);

    program.setRules(rule); 
}

// ruleList  ->  rule ruleList | lambda
void Parser::ruleList() {
    if (tokens.at(index)->getTokenType() == TokenType::ID) {
        rule();
        ruleList();
    }
}

// query  ->  predicate Q_MARK
void Parser::query() {
    Predicate query;

    // Call predicate
    predicate(query);

    // Check for Question Mark
    match(TokenType::QUESTION);

    program.setQueries(query);
}

// Parse Query List
void Parser::queryList() {
    if (tokens.at(index)->getTokenType() == TokenType::ID) {
        query();
        queryList();
    }
}

// idList  ->  COMMA ID idList | lambda
void Parser::idList(Predicate& predicate) {
    // Check for Comma
    if (tokens.at(index)->getTokenType() == TokenType::COMMA) {
        Parameter p;

        // Check for comma
        match(TokenType::COMMA);

        // Check for ID
        match(TokenType::ID);

        // Add Parameter
        p.setID(tokens.at(index-1)->getTokenDescription());
        predicate.addParameter(p);
        
        // Call idList
        idList(predicate);
    }
}

// stringList  ->  COMMA STRING stringList | lambda
void Parser::stringList(Predicate& predicate) {
    if (tokens.at(index)->getTokenType() == TokenType::COMMA) {
        Parameter p;
        
        // Check for comma
        match(TokenType::COMMA);
        
        // Check for string
        match(TokenType::STRING);

        // Add Parameter
        program.setFactsDomain(tokens.at(index-1)->getTokenDescription());
        p.setID(tokens.at(index-1)->getTokenDescription());
        predicate.addParameter(p);

        stringList(predicate);
    }
}

// predicate  ->  ID LEFT_PAREN parameter parameterList RIGHT_PAREN
void Parser::predicate(Predicate& predicate) {
    // Check for ID
    match(TokenType::ID);

    // Add predicate ID
    predicate.setID(tokens.at(index-1)->getTokenDescription());
    
    // Check for Left Paren
    match(TokenType::LEFT_PAREN);

    // Call Parameter
    parameter(predicate);
    
    // Call ParameterList
    parameterList(predicate);
    
    // Check for right paren
    match(TokenType::RIGHT_PAREN);
}

// headPredicate  ->  ID LEFT_PAREN ID idList RIGHT_PAREN
void Parser::headPredicate(Predicate& predicate) {
    Parameter param;

    // Check for ID
    match(TokenType::ID);
    predicate.setID(tokens.at(index-1)->getTokenDescription());

    // Check for left paren
    match(TokenType::LEFT_PAREN);

    // Check for ID
    match(TokenType::ID);

    // Add parameter to predicate
    param.setID(tokens.at(index-1)->getTokenDescription());
    predicate.addParameter(param);

    // Call idList
    idList(predicate);

    // Check for right paren
    match(TokenType::RIGHT_PAREN);
}

// predicateList  ->  COMMA predicate predicateList | lambda
void Parser::predicateList(Rule& rule) {
    // Check for comma
    if (tokens.at(index)->getTokenType() == TokenType::COMMA){
        Predicate p;
    
        // Check for comma
        match(TokenType::COMMA);
        
        // Call predicate
        predicate(p);

        // Push to vector of predicates in rule
        rule.setPredicates(p);

        // Call predicate list
        predicateList(rule);
    }
}

// parameter  ->  STRING | ID 
void Parser::parameter(Predicate& predicate) {
    // Check for string
    if (tokens.at(index)->getTokenType() == TokenType::STRING) {
        match(TokenType::STRING);
    // Check for ID
    } else if (tokens.at(index)->getTokenType() == TokenType::ID) {
        match(TokenType::ID);
    }

    // Add Parameter
    Parameter parameter;

    parameter.setID(tokens.at(index-1)->getTokenDescription());
    predicate.addParameter(parameter);
}

// parameterList  ->  COMMA parameter parameterList | lambda
void Parser::parameterList(Predicate& predicate) {
    if (tokens.at(index)->getTokenType() == TokenType::COMMA) {
        match(TokenType::COMMA);
        
        parameter(predicate);
        parameterList(predicate);
    }
}

