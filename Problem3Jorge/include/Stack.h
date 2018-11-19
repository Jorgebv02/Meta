#ifndef STACK_H
#define STACK_H

// Includes the ArrayList.
#include "ArrayList.h"

// To manage exceptions.
#include <cstddef>
#include <stdexcept>

// To avoid using: "std::cout", etc.
using namespace std;
/*
    This pile looks like this:
    |__| → This is the top/size of the stack.
    |__|
    |__|
    |__| → This is the "first element", or element[0].

*/

class Stack : public ArrayList
{
    public:
        Stack();                    // Constructor by defect.
        Stack(int Size);            // Constructor with a size.
        virtual ~Stack();           // Destructor.
        void push(int element);     // Push an element to the stack.
        int pop();                  // Pop an element to the stack.
        int topValue();             // Get the topValue at the stack.
        bool isEmpty();             // To know if the Stack is empty :P.

};

#endif // STACK_H

