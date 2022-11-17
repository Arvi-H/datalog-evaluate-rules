#include "PeriodAutomaton.h"

void PeriodAutomaton::S0(const std::string& input) {
    if (input[inputRead] == '.') {
        inputRead = 1;
    } 
}