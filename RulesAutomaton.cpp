#include "RulesAutomaton.h"

void RulesAutomaton::S0(const std::string& input) {
    if (input[inputRead] == 'R') {
        inputRead++;
        S1(input);
    } else {
        Serr();
    }
}

void RulesAutomaton::S1(const std::string& input) {
    if (input[inputRead] == 'u') {
        inputRead++;
        S2(input);
    } else {
        Serr();
    }
}

void RulesAutomaton::S2(const std::string& input) {
    if (input[inputRead] == 'l') {
        inputRead++;
        S3(input);
    } else {
        Serr();
    }
}

void RulesAutomaton::S3(const std::string& input) {
    if (input[inputRead] == 'e') {
        inputRead++;
        S4(input);
    } else {
        Serr();
    }
}

void RulesAutomaton::S4(const std::string& input) {
    if (input[inputRead] == 's') {
        inputRead++;
    } else {
        Serr();
    }
}
