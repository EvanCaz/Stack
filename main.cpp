/*********************
 * Evan Cazares
 * Assignment: coding05
 * toy problem demostarting excetion handling with pass by refernce, 
 * dev testing, and dynamic memory allocation
**********************/

#include "main.h"

int main(int argc, char **argv) {
    srand(time(NULL));
    int sz, choice;
    string strtemp;
    

    if (argc == 2){
        sz = atoi(argv[1]); // converts string index to int and takes floats to ints whcih is bad not sure how to change
        if (sz != 0){
            Stack s1(&sz); // creating stack of the size passes in command line, pass by refernce so that if -# gets enter its changed to ten
            cout << "Testing \"isEmpty\" on empty stack..." << endl;
            cout << "Empty(1 success, 0 failure): " << s1.isEmpty() << endl;
            cout << "Testing \"peek\" and \"pop\" on empty stack with empty struct..." << endl;
            Data d1, d2;
            cout << "peek(1 success, 0 failure): " << s1.peek(&d1) << endl << "pop(1 success, 0 failure): " << s1.pop(&d2) << endl;
            cout << "peek data struct contents: " << d1.id << " : " << d1.information << endl;
            cout << "pop data struct contents: " << d2.id << " : " << d2.information << endl;
            cout << "defined testing.." << endl;
            cout << "Filling stack past size..." << endl;
            for(int i=0; i<(sz*MULTIPLIER); i++){ // for overflow
                rand_string(&strtemp);
                cout << "Push number " << (i+1) << " (1 success, 0 failure): " << s1.push(i*MULTIPLIER, &strtemp) << endl;
            }
            cout << endl << "Testing pop and peek on full stack past stack size..." << endl;
            for(int i=0; i<(sz*MULTIPLIER); i++){ // for overflow
                if(i%2 == 0){ // splits actions into two paths for both peek and pop
                    Data testObj;
                    cout << "Test pop  " << (i+1) << " (1 success, 0 failure): " << s1.pop(&testObj) << endl;
                } else {
                    Data testObj2;
                    cout << "Test peek " << (i+1) << " (1 success, 0 failure): " << s1.pop(&testObj2) << endl;
                }
            }
            cout << endl << "Testing push and pop on middle of stack..." << endl;
            for(int i=0; i<(sz*MULTIPLIER); i++){ // for overflow
                if(i%2 == 0){ // splits actions into two paths for both peek and pop
                    Data testObj;
                    cout << "Test pop  " << (i+1) << " (1 success, 0 failure): " << s1.pop(&testObj) << endl;
                } else {
                    rand_string(&strtemp);
                    cout << "Test push " << (i+1) << " (1 success, 0 failure): " << s1.push(i*MULTIPLIER, &strtemp) << endl;
                }
            }
            cout << endl << "Random testing next with switch statment to call random methods on stack..." << endl;
            for(int i=0; i<(sz*MULTIPLIER); i++){ // for overflow
                choice = rand()%MAX;
                Data testObj;
                switch(choice){
                    case 0:
                        cout << "Test empty number " << (i+1) << " (1 empty, 0 not empty): " << s1.isEmpty() << endl;
                        break;
                    case 1:
                        cout << "Test pop number " << (i+1) << " (1 success, 0 underflow): " << s1.pop(&testObj) << endl;
                        cout << "Contents of pop: " << testObj.id << " : " << testObj.information << endl;
                        break;
                    case 2:
                        cout << "Test peek number " << (i+1) << " (1 success, 0 underflow): " << s1.peek(&testObj) << endl;
                        cout << "Contents of peek: " << testObj.id << " : " << testObj.information << endl;
                        break;
                    case 3:
                        rand_string(&strtemp);
                        cout << "Test push number " << (i+1) << " (1 success, 0 overflow): " << s1.push(i*MULTIPLIER, &strtemp) << endl;
                        break;
                }
            }
        } else {
            cout << "Incorrect argument" << endl;
        }
    } else {
        cout << "Please Enter correct amount of arguments" << endl;
    }

    return 0;
}
