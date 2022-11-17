#include "CommaAutomaton.h"

void CommaAutomaton::S0(const std::string& input) {
    if (input[inputRead] == ',') {
        inputRead = 1;
    } 
}
