#include "Debugger.h"
#include <vector>
#include <sstream>

Debugger::Debugger(){
    this -> programCounter = 0;
}

Debugger::~Debugger(){
    //dtor
}

// This function catches a program counter instruction and
// transforms it to his decimal notation.
// For example: "0x00000000" → 0.
int Debugger::convertStringToInt(string pc){
    return 1;
}

vector<string> Debugger::split(const string& s, char delimiter){

   vector<string> tokens;
   string token;
   istringstream tokenStream(s);
   while (getline(tokenStream, token, delimiter)){
      tokens.push_back(token);
   }
   return tokens;
}

