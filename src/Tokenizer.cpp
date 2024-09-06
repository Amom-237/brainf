#include <vector>
#include <string>
#include <iostream>
#include <fstream>

#include "Tokenizer.h"
#include "Tokens.h"


std::vector<Token> Tokenizer(std::string path)
{
    std::ifstream file(path);
    if (!file.is_open()) {
        std::cout << "File does not exist: " << path << std::endl;
        file.close();
        exit(-1);
    }

    std::vector<Token> tokens;
    std::string current_line;

    while (std::getline(file, current_line)) {
        
        for (int i = 0; i < current_line.length(); i++) {
            switch (current_line[i]) {
            case '>':
                tokens.push_back(greater_symbol);
                continue;
            case '<':
                tokens.push_back(less_symbol);
                continue;
            case '+':
                tokens.push_back(plus_symbol);
                continue;
            case '-':
                tokens.push_back(minus_symbol);
                continue;
            case '.':
                tokens.push_back(dot_symbol);
                continue;
            case ',':
                tokens.push_back(comma_symbol);
                continue;
            case '[':
                tokens.push_back(left_bracket_symbol);
                continue;
            case ']':
                tokens.push_back(right_bracket_symbol);
                continue;
            default:
                // Ignoring unrecognized symbols,
                continue;
            
            }
        }
    }

    file.close();
    return tokens;
}
