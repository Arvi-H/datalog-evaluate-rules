#include "Token.h"
#include "sstream"

Token::Token(TokenType type, std::string description, int line) {
    this->type = type;
    this->description = description;
    this->line = line;
}

std::string Token::TokenConverter(TokenType type) {
    switch(type) {
    case TokenType::COLON:
        return "COLON";
    case TokenType::COLON_DASH:
        return "COLON_DASH";
    case TokenType::COMMA:
        return "COMMA";
    case TokenType::PERIOD:
        return "PERIOD";
    case TokenType::QUESTION:
        return "Q_MARK";
    case TokenType::ADD:
        return "ADD";
    case TokenType::MULTIPLY:
        return "MULTIPLY";
    case TokenType::RIGHT_PAREN:
        return "RIGHT_PAREN";
    case TokenType::LEFT_PAREN: 
        return "LEFT_PAREN";
    case TokenType::SCHEMES:
        return "SCHEMES";
    case TokenType::FACTS:
        return "FACTS";
    case TokenType::RULES:
        return "RULES";
    case TokenType::QUERIES:
        return "QUERIES";
    case TokenType::ID:
        return "ID";
    case TokenType::STRING:
        return "STRING";
    case TokenType::COMMENT:
        return "COMMENT";
    case TokenType::UNDEFINED:
        return "UNDEFINED";
    case TokenType::ENDFILE:
        return "EOF";
    default: return "Read Error";
    }
}

std::string Token::toString() {
    std::stringstream out;

    out << "(" << TokenConverter(type) << "," << "\"" << description <<"\"" << "," << line << ")";
    
    return out.str();
}

TokenType Token::getTokenType() const {
    return type;
}

std::string Token::getTokenDescription() {
    return description;
}
