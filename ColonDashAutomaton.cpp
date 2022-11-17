#include "ColonDashAutomaton.h"

void ColonDashAutomaton::S0(const std::string& input) {
    if (input[inputRead] == ':') {
        inputRead++;
        S1(input);
    } 
}

void ColonDashAutomaton::S1(const std::string& input) {
    if (input[inputRead] == '-') {
        inputRead++;
    } 
}