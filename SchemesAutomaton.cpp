#include "SchemesAutomaton.h"

void SchemesAutomaton::S0(const std::string& input) {
    if (input[inputRead] == 'S') {
        inputRead++;
        S1(input);
    } else {
        Serr();
    }
}

void SchemesAutomaton::S1(const std::string& input) {
    if (input[inputRead] == 'c') {
        inputRead++;
        S2(input);
    } else {
        Serr();;
    }
}

void SchemesAutomaton::S2(const std::string& input) {
    if (input[inputRead] == 'h') {
        inputRead++;
        S3(input);
    } else {
        Serr();
    }
}

void SchemesAutomaton::S3(const std::string& input) {
    if (input[inputRead] == 'e') {
        inputRead++;
        S4(input);
    } else {
        Serr();
    }
}

void SchemesAutomaton::S4(const std::string& input) {
    if (input[inputRead] == 'm') {
        inputRead++;
        S5(input);
    } else {
        Serr();
    }
}

void SchemesAutomaton::S5(const std::string& input) {
    if (input[inputRead] == 'e') {
        inputRead++;
        S6(input);
    } else {
        Serr();
    }
}

void SchemesAutomaton::S6(const std::string& input) {
    if (input[inputRead] == 's') {
        inputRead++;
    } else {
        Serr();
    }
}
