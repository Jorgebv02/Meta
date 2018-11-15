#ifndef DEBUGGER_H
#define DEBUGGER_H

// Include the Stack.
#include "Stack.h"

// To manage ArrayList.
#include <vector>

// Include the instruction class.
#include "Instruction.h"

// This class controls all the program state.
class Debugger
{
    public:
        Debugger();             // Constructor.
        virtual ~Debugger();    // Destructor.

        // To process one instruction.
        void step(vector<int> instruction);

        // Runs all the program.
        void run();

        // Reset all and goes to the beginning.
        void reset();

        // Reads the file where is the vbin.
        vector<vector<string>> readFile(ifstream file);

        // Auxiliary functions.
        int convertStringToInt(string pc);

        // Splits an string by a delimiter.
        vector<string> split(const string& s, char delimiter);

        // Gets a line of the code.

    private:
        int programCounter;                 // Allows to know in which point is the code.
        Stack Stack;                        // To put instructions and values here.
        vector<vector<int>> instructions;   // A vector of vectors with all the instructions.
        string buffer;                      // The output buffer.
};

#endif // DEBUGGER_H
