#include "IDAutomaton.h"

void IDAutomaton::S0(const std::string& input) {
    if (isalpha(input[inputRead])) {
        inputRead++;
        S1(input);
    } 
}

void IDAutomaton::S1(const std::string& input) {
    if (isalpha(input[inputRead])) {
        inputRead++;
        S1(input);
    } else if (isdigit(input[inputRead])) {
        inputRead++;
        S1(input);
    }  
}
