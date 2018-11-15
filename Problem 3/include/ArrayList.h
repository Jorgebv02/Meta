#ifndef ARRAYLIST_H
#define ARRAYLIST_H

// To manage definitions and exceptions.
#include <cstddef>
#include <stdexcept>

class ArrayList{

    // All the methods and the constructor.
    public:
        ArrayList(int pMax);        // The constructor of the class.
        virtual ~ArrayList();       // The destructor of the class.
        int getValue();             // Returns the element in the position "pos".
        int getPos();               // Returns the value of "pos".
        int getSize();              // Returns the size of the ArrayList.
        void goToStart();           // Go to the first element of the ArrayList.
        void goToEnd();             // Go to the last element of the ArrayList.
        void goToPos(int pos);      // Go to "pos".
        void previous();            // Subtract 1 to "pos".
        void next();                // Sums 1 to "pos".
        void append(int Element);   // Appends an element at the end of the ArrayList.
        void insert(int pElement);  // Inerts an element in position "pos".
        int remove();               // Remove the element in position "pos".
        void print();               // Prints all the elements of the ArrayList.

    protected:
        int *elements;              // A pointer to the elements.
        int max;                    // The max value that it can accept.
        int size;                   // The current size of the ArrayList.
        int pos;                    // A position in the ArrayList.

};

#endif // ARRAYLIST_H
