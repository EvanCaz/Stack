/*********************
 * Evan Cazares
 * Assignment: coding05
 * toy problem demostarting excetion handling with pass by refernce, 
 * dev testing, and dynamic memory allocation
**********************/

// each cpp includes ONLY it's header directly
#include "stack.h"

Stack::Stack(int *sz){
    top = -1;
    if(*sz < 2) {
        size = REVERT;
        *sz = REVERT; // to be used in main so the foor loops dont multiple by a -#
    } else {
        size = *sz;
    }
    stack = new Data*[size];
}

bool Stack::push(int id, string* info) {
    bool flag = false;
    if ((top < (size - 1)) && !info->empty() && id > 0){ // validation of inputs and room, pointer notation since string is pointer
        Data* dptr = new Data; // creates new pointer to struct data which will contatin info passed from method
        dptr->id = id; // set attribute
        dptr->information = *info; // set attriubte, derefernce since the parametet in function is pointer and the attribute in the sturct inst, making it pointless
        top++;
        stack[top] = dptr; // sets new highest index of stack to pointer which can be deleted in pop, meaning no extra delete in stack deconstrucotr
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
    }
    return flag;
}

bool Stack::isEmpty() {
    return top < 0;
}

Stack::~Stack(){
    delete []stack; // deletes 1d stack of pointers
    // may need a for loop to delete each pointer in stack
}

void Stack::dumpStack() { // testing, prints all struct locations
    std::cout << "size: " << size << std::endl;
    for (int i = 0;i < size; i++){
       std::cout << stack[i] << std::endl;
    }
}