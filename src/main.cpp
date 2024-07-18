#include <iostream>
#include <vector>
#include <string>
#include "Tokens.h"
#include "Tokenizer.h"
#include "interpreter.h"


int main(int argc, char *argv[]) { 

    if(argc <= 1) {
        std::cout << "Incorrect usage\nusage: 'brainf path/to/script'\n";
        return -1;
    }
    
    
    std::string path = argv[1];

    // Yes i know i can interpret direcltly.
   std::vector<Token> tokens = Tokenizer(path);

    interpreter(tokens);
    
    return 0;
}
