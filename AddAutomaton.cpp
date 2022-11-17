#include "AddAutomaton.h"

void AddAutomaton::S0(const std::string& input) {
    if (input[inputRead] == '+') {
        inputRead = 1;
    } 
}