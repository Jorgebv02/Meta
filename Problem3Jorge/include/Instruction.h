#ifndef INSTRUCTION_H
#define INSTRUCTION_H

// To use strings.
#include <string>

// To avoid using: "std:cout", etc.
using namespace std;

// This class represents an instruction to process on the Debugger.
class Instruction
{
    public:
        Instruction(string pName, int pRow,
                    int pColumn, int pDirection);

        // In case, the instruction doesn't have a direction.
        Instruction(string pName, int pRow,
                    int pColumn);
        virtual ~Instruction();

    private:

        string name;    // The name of the operation. ie: load, store, etc.
        int row;        // The row where it is.
        int column;     // The column where it is.
        int direction;  // The direction to execute. This can be optional.
};

#endif // INSTRUCTION_H
