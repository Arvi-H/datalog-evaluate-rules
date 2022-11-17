#include "CommentAutomaton.h"

#include <iostream>
#include <sstream>

using namespace std;

void CommentAutomaton::S0(const std::string& input) {
    multilineInc = 0;

    if (input[inputRead] == '#') {
        inputRead++;
        S1(input);
    } 
}

void CommentAutomaton::S1(const std::string& input) {
     if (input[inputRead] != '|') { 
        inputRead++;
        S2(input);
     } else if (input[inputRead] == '|') {
        multiline = true;
        inputRead++;
        S3(input);
     } 
} 

void CommentAutomaton::S2(const std::string& input) { 
    if (input[inputRead] != '\n') { 
        inputRead++;
        S2(input);
    } else {
        return;
    }
}

void CommentAutomaton::S3(const std::string& input) { 
    int size = input.size();
    if (inputRead >= size) {

        terminateFlag = true;
        return;
    } else if (input[inputRead] != '|') {
        if (input[inputRead] == '\n') {
            multilineInc++;
        }

        inputRead++;
        S3(input);
    
    } else if (input[inputRead] == '|') {
        inputRead++;
        S4(input);

    } else if (input[inputRead] == '\n') {
        multilineInc++;
        inputRead++; 
    }
}

void CommentAutomaton::S4(const std::string& input) { 
    if (input[inputRead] == '#') {
        inputRead++;
        return;
    } else if (input[inputRead] == '|') {
        inputRead++;
        S3(input);
    } else {
        if (input[inputRead] == '\n') {
            S3(input);
        }

        terminateFlag = true;
        return;
    }
}