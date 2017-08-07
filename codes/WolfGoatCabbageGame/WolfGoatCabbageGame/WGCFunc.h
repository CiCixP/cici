#ifndef WGCFunctions_hpp
#define WGCFunctions_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>

char input(std::vector<int> side, std::string bank);
void move(std::vector<int> & From, std::vector<int> & To, char choice);
void printMoves(std::vector<int> side);
void check(std::vector<int> side);


#endif /* WGCFunctions_hpp */
