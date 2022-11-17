#include "ColonAutomaton.h"

void ColonAutomaton::S0(const std::string& input) {
    if (input[inputRead] == ':') {
        inputRead = 1;
    } 
}