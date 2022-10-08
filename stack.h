/*********************
 * Evan Cazares
 * Assignment: coding05
 * toy problem demostarting excetion handling with pass by refernce, 
 * dev testing, and dynamic memory allocation
**********************/

#ifndef STACK_H
#define STACK_H


#include "data.h"
#include <iostream>

#define REVERT 10

class Stack {

private:
    int top;
    int size;
    Data **stack;
public:
    Stack(int*); // construcot to create array of points of the size passed in from command line
    ~Stack(); // deconstructor to prevrent memory leaks and delete all news

    bool pop(Data*); // accepts location of a empty data struct to fill if stack is not empty and decrements top
    bool peek(Data*); // same thing but does not decrement varaible top
    bool isEmpty(); // retunrs true when top is -1
    bool push(int, string*); // gets passes an identifier and string point to struct data, point then gets put ontop of stack

    void dumpStack(); // testing
};


#endif //STACK_H
