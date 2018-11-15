/*
**************************************************
Source code:    Problem 3 project.
Version:        1.0
Creation Date:  21/October/2018
Last update:    N/A.
Author:         Jorge Barquero Villalobos,
                Juan Escobar Sánchez.
                Yericka Lafuente Ovares,
                based on PhD. José Castro Mora.
Description:    implementation of problem 3 (VAM). For more references,
                read the specification located in GitHub.
Note:           Using Windows 10, gcc 5.1.0 and C++11.
Built in:       CodeBlocks 17.12.
**************************************************
*/

// To print on the standard I/O.
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <vector>
#include <iterator>

// To avoid using "std::cout", etc.
using namespace std;

int main()
{
    // Print the instructions.
    cout << "Welcome to the VAM debugger." << endl;
    cout << "These are the commands: " << endl;
    cout << "(S)tep  : process one instruction." << endl;
    cout << "(R)un   : runs all the program. " << endl;
    cout << "Rese(T) : reset all the program state. " << endl;

    return 0;
}
