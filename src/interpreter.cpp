#include <vector>
#include <string>
#include <iostream>
#include "Tokens.h"


int find_left_bracket(std::vector<Token> tokens, int pointer) {
    int balance = 0;

    // Bound checking
    while(pointer >= 0 ) {

        Token currunt_token = tokens[pointer];
        
        switch (currunt_token) {

            case left_bracket_symbol:
                balance = balance - 1;

                if(balance == 0)
                    return pointer;
                else {
                    pointer--;
                    continue;
                }
        
            case right_bracket_symbol:
                balance = balance + 1;
                pointer--;
                continue;
            
            default:
                pointer--;
                continue;
        
        }

    }

    // Since its not found, throw an error
    std::cout << "mising a bracket in script\n";
    exit(-1);
}


int find_right_bracket(std::vector<Token> tokens, int pointer) {
    int balance = 0;

    // Bound checking
    while(pointer >= 0 ) {

        Token currunt_token = tokens[pointer];

        switch (currunt_token) {

            case right_bracket_symbol:
                balance = balance - 1;

                if(balance == 0)
                    return pointer;
                else {
                    pointer--;
                    continue;
                }
        
            case left_bracket_symbol:
                balance = balance + 1;
                pointer--;
                continue;
            
            default:
                pointer--;
                continue;
        
        }

    }

    // Since its not found, throw an error
    std::cout << "mising a bracket in script\n";
    exit(-1);
}



void interpreter(std::vector<Token> tokens) {

    std::string input;

    // Allocate 30000 bytes and set pointers
    char ram[30000] {0};
    int data_pointer = 0;
    int instruction_pointer = 0;


    std::cout << "starting interpretation..\n";
    
    // The code below is unsafe(accesing outside of ram)
    while(instruction_pointer < tokens.size()) {

        switch (tokens[instruction_pointer]) {
            case greater_symbol:
                data_pointer++;
                instruction_pointer++;
                continue;

            case less_symbol:
                 data_pointer--;
                instruction_pointer++;
                continue;

            case plus_symbol:
                ram[data_pointer]++;
                instruction_pointer++;
                continue;

            case minus_symbol:
                ram[data_pointer]--;
                instruction_pointer++;
                continue;

            case dot_symbol:
                std::cout << ram[data_pointer];
                instruction_pointer++;
                continue;

            case comma_symbol:
                std::cin >> input;
                ram[data_pointer] = input[0];
                instruction_pointer++;
                continue;

            case left_bracket_symbol:
                if(ram[data_pointer] == 0) {
                    instruction_pointer = find_right_bracket(tokens, instruction_pointer);
                }else instruction_pointer++;

                continue;

            case right_bracket_symbol:
                if(ram[data_pointer] != 0) {
                    instruction_pointer = find_left_bracket(tokens, instruction_pointer);
                }else instruction_pointer++;

                continue;

        }
    }
}
