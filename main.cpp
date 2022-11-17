#include "Lexer.h"
#include "Parser.h"
#include "DatalogProgram.h"
#include "Interpreter.h"
#include <fstream>
#include <sstream>
#include <iostream>
 
int main(int argc, char** argv) {
// File I/O
    std::ifstream input(argv[1]);
    std::stringstream in;

// Convert file to a string stream
    input.open(argv[1]);
    in << input.rdbuf();
    input.close();

// Convert string stream to a sting
    std::string myFileString = in.str();

    try {
        // Run Lexer
        Lexer lexer;
        lexer.Run(myFileString);

        // Run Parser 
        Parser parser(lexer.getTokens());
        DatalogProgram program = parser.Parse();
        
        // Run Interpreter
        Interpreter interpreter(program);
        interpreter.start();
        
    // Catch Errors
    } catch (Token* errorToken) {
        std::cout << "Failure!" << std::endl << "  " << errorToken->toString();
    } 
 
    return 0;
}