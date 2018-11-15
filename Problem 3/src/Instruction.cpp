#include "Instruction.h"

Instruction::Instruction(string pName, int pRow,
                    int pColumn, int pDirection){

    this -> name       = pName;
    this -> row        = pRow;
    this -> column     = pColumn;
    this -> direction  = pDirection;
}

Instruction::Instruction(string pName, int pRow,
                         int pColumn){
    this -> name       = pName;
    this -> row        = pRow;
    this -> column     = pColumn;
}

// I don't remember how to destruct an object XD.
Instruction::~Instruction(){

}
