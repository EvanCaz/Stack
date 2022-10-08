/*
 * Your comment header here
 * modify this file as needed to complete the assignment
 */

// each cpp includes ONLY it's header directly
#include "stack.h"

Stack::Stack(int sz){
    top = -1;
    if(sz > 2) {
        size = sz; 
        stack = new Data*[size];
    } else {
        size = DFSIZE;
        stack = new Data*[size];
    }
}

bool Stack::push(int id, string* info) {
    bool flag = false;
    if ((top < (size - 1)) && !info->empty() && id > 0){ // validation of inputs and room
        Data* dptr = new Data; // creates point
        dptr->id = id; // set attribute
        dptr->information = *info; // set attriubte, derefernce since the parametet in function is pointer, making it pointless
        top++;
        stack[top] = dptr; // sets new highest index of stack to pointer
        flag = true;
    }
    return flag;
}


bool Stack::pop(Data* dptr) { // receives empty data struct location
    bool flag = false;
    if (top < 0){
        dptr->id = -1;
        dptr->information = "";
    } else {
        dptr->id = stack[top]->id;
        dptr->information = stack[top]->information;
        delete stack[top]; // deletes pointer at top of stack, deallocating
        top--;
        flag = true;
    }
    return flag;

}
bool Stack::peek(Data* dptr){ // receives empty data struct location
    bool flag = false;
    if (top < 0){
        dptr->id = -1;
        dptr->information = "";
    } else {
        dptr->id = stack[top]->id;
        dptr->information = stack[top]->information;
        flag = true;
        delete stack[top]; // deletes pointer at top of stack, deallocating
    }
    return flag;
}

bool Stack::isEmpty() {
    return top < 0;
}

Stack::~Stack(){
    delete []stack; // deletes 1d stack of pointers
}