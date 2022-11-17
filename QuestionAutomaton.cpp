#include "QuestionAutomaton.h"

void QuestionAutomaton::S0(const std::string& input) {
    if (input[inputRead] == '?') {
        inputRead = 1;
    } 
}
