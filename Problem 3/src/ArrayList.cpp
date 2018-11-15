#include "ArrayList.h"

// A definition, and some libraries to manage exceptions and
// I/O operations.
#define DEFAULT_MAX_SIZE 1024
#include <stdexcept>
#include <iostream>

// To avoid using things like: "std::cout", etc.
using namespace std;

// Constructor.
ArrayList::ArrayList(int pMax = DEFAULT_MAX_SIZE){
    elements    = new int[pMax];
    size        = 0;
    pos         = 0;
    max         = pMax;
}

int ArrayList::getValue(){
    return elements[pos];
}

int ArrayList::getPos(){
    return pos;
}

int ArrayList::getSize(){
    return size;
}

void ArrayList::goToStart(){
    pos = 0;
}

void ArrayList::goToEnd(){
    pos = size - 1;
}

void ArrayList::goToPos(int pPos){
    this -> pos = pPos;
}

void ArrayList::next(){

    // In case, he's not at the end of the ArrayList.
    if (pos < size){
        pos++;
    }
}

void ArrayList::append(int pElement){

    // In case the list is full.
    if (size == max){
        cout << "The List is full." << endl;
        return;
    }
    elements[size] = pElement;
    size++;
}

void ArrayList::insert(int pElement){

    // In case the list is full.
    if (size == max){
        cout << "The List is full." << endl;
    }

    // Slipping.
    for (int i = size; i > pos; i--){
        elements[i] = elements[i-1];
    }

    elements[pos] = pElement;
    size++;
}

int ArrayList::remove(){
    if (pos < 0 || pos >= size || size == 0){
        cout << "The list is empty." << endl;
    }
    else{

        // Slipping.
        int deletedElement = elements[pos];
        for (int i = pos; i < size; i++){
            elements[i] = elements[i + 1];
        }

        size --;
        return deletedElement;
    }
}

void ArrayList::print(){
    for (int i = 0; i <= size-1; i++){
        cout << elements[i] << " ";
    }

    cout << endl;
}

void ArrayList::previous(){

    // To avoid going back at the first element of the ArrayList.
    if (pos < size && pos > 0){
        pos = pos - 1;
    }
}

ArrayList::~ArrayList(){
    size    = 0;
    pos     = 0;
    delete[]elements;
}

