/*
 * Your comment header here
 * modify this file as needed to complete the assignment
 */

// each cpp includes ONLY it's header directly
#include "stack.h"

/*
 * write all your stack methods here
 */

/* this stack will contain pointers that point to instances of the ADT Data struct created in data.h
* each index of the stack will be on pointer, a pass by reference, of an instnace of Data.*/
Stack::Stack(int size){
    // dynamaccally creates array of pointers of length size, each pointer points to a Data struct
    Data* strct;
    strct = new Data[size];
    top = -1;
}
bool Stack::isEmpty() {
    return top < -1;
}
Stack::~Stack(){

}