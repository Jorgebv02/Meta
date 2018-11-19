// To apply the heritage.
#include "Stack.h"
#include "ArrayList.h"

// The Max size and the exceptions and I/O operations.
#define DEFAULT_MAX_SIZE 1024
#include <stdexcept>
#include <iostream>

// To avoid using: "std::cout", etc.
using namespace std;

// Calls the constructor of the ArrayList.
Stack::Stack():ArrayList(DEFAULT_MAX_SIZE) {}

// Calls the constructor of the ArrayList with a parameter.
Stack::Stack(int tamano):ArrayList(tamano) {}

// Goes to the Start and append an element.
void Stack::push(int element){
    goToStart();
    append(element);
}

int Stack::pop(){

    // In case the stack is empty.
    if (isEmpty()){
        cout << "The Stack is empty." << endl;
    }

    else{

        // Go to the end of the pile.
        goToEnd();

        // Pop it and return it.
        int removedValue = remove();
        return removedValue;
    }

}

// Gets the last element but without deleting him.
int Stack::topValue()
{
    goToEnd();
    int temp;
    temp = getValue();
    return temp;
}

// To check if the Stack is empty.
bool Stack::isEmpty()
{
    if(size == 0){
        return true;
    }
    else{
        return false;
    }
}

Stack::~Stack() {}
