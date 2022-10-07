/*
 * Your comment header here
 * modify this file as needed to complete the assignment
 */

#ifndef STACK_H
#define STACK_H

/*
 * there are no other includes here because they are not needed.
 * if you do need other things included, they would go here
 */

#include "data.h"

class Stack {

private:
    /* 
     * write all your private method prototypes here
     */
    int top;
    int size;
    Data **stack;
    // notice stack is a pointer to a pointer. That means if you do
    // a single array allocation, you will get an array of pointers
public:
    Stack(int); // construcot to create array of points of the size passed in from command line
    ~Stack(); // deconstructor to prevrent memory leaks and delete all news

    bool pop(Data*); // accepts location of a empty data struct to fill if stack is not empty
    bool peek(Data*); // same thing but does not decrement varaible top
    bool isEmpty(); // retunrs true when top is -1
    bool push(int, string*); // gets passes an identifier and string point to struct data, point then gets put ontop of stack
    
};

#endif //STACK_H
