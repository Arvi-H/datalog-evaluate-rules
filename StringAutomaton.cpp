#include "StringAutomaton.h"

void StringAutomaton::S0(const std::string& input) {
    multilineInc = 0;
    if (input[inputRead] == '\'') {
        inputRead++;
        S1(input);  
    } else {
        Serr();
    }
}


void StringAutomaton::S1(const std::string& input) {
    int size = input.size();
    if (inputRead >= size) {
        terminateFlag = true;    
        return;
    } else if (input[inputRead] == '\'') {
        inputRead++;
        S2(input);
    } else {
        if (input.at(inputRead) == '\n') {
            multiline = true;
            multilineInc++;
        }

        inputRead++;
        S1(input);
    }
}

void StringAutomaton::S2(const std::string& input) {
    if (input[inputRead] == '\'') {
        inputRead++;
        S1(input);
    } else { 
        return;
    }
}

