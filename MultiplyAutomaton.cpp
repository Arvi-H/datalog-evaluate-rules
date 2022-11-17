#include "MultiplyAutomaton.h"

void MultiplyAutomaton::S0(const std::string& input) {
    if (input[inputRead] == '*') {
        inputRead = 1;
    } 
}