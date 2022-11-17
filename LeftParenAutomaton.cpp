#include "LeftParenAutomaton.h"

void LeftParenAutomaton::S0(const std::string& input) {
    if (input[inputRead] == '(') {
        inputRead = 1;
    } 
}
