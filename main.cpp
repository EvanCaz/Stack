/*
 * your header here
 * 
 */

#include "main.h"

int main(int argc, char **argv) {
    // here for the rand_string() function
    // if you don't use it, get rid of this
    srand(time(NULL));
    int sz, choice;
    string test = "test string"; // variable defintion since push accepts a pointer
    string strtemp;
    

    if (argc == 2){
        sz = atoi(argv[1]); // converts string index to int and takes floats to ints whcih is bad not sure how to change
        if (sz != 0){
            Stack s1(sz); // creating stack of the size passes in command line
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
            cout << "Random testing next with switch statment to call random methods on stack..." << endl;
            for(int i=0; i<(sz*MULTIPLIER); i++){ // for overflow
                choice = rand()%MAX;
                Data testObj;
                switch(choice){
                    case 0:
                        cout << "Test empty number " << (i+1) << " (1 empty, 0 not empty): " << s1.isEmpty() << endl;
                        break;
                    case 1:
                        cout << "Test pop number " << (i+1) << " (1 success, 0 underflow): " << s1.pop(&testObj) << endl;
                        cout << testObj.id << " : " << testObj.information << endl;
                        break;
                    case 2:
                        cout << "Test peek number " << (i+1) << " (1 success, 0 underflow): " << s1.peek(&testObj) << endl;
                        cout << testObj.id << " : " << testObj.information << endl;
                        break;
                    case 3:
                        rand_string(&strtemp);
                        cout << "Test push number " << (i+1) << " (1 success, 0 overflow): " << s1.push(i*MULTIPLIER, &strtemp) << endl;
                        break;
                }
            }


            cout << endl;
            s1.dumpStack();

        











        } else {
            cout << "Incorrect argument" << endl;
        }
    } else {
        cout << "Please Enter correct amount of arguments" << endl;
    }
    return 0;




































    /* ***************************************************************
     * First get your arguments from the command line. Your program must
     * accept one and only one argument not including the program name
     * itself. That argument must be an integer. If anything else is entered
     * in any way, terminate the program with a suitable error message
     * telling the user how to use your program correctly.
     * 
     * Remember, you may not use more than one return, even in main()
     * and you may not use exit() or anything like that.
     * ***************************************************************/
    
    /* ***************************************************************
     * Use the number passed in from the command line and declare a stack
     * that uses that number as the size of the stack. NOTE: Make sure
     * your stack checks the number passed in to it. You cannot rely
     * on main checking the number first, each part of every program and
     * ADT is always responsible for it's own error checking. Main must
     * check the user gave it an int. The stack must check main()
     * gave it a good number. This is proper error checking, no part of
     * any program can assume it's caller is behaving correctly. To do this,
     * try passing -1 or 0 or some other "bad" number to the stack from
     * main and make sure your stack rejects it, or defaults to some
     * pre-defined default value. This will be tested during grading.
     * ***************************************************************/

    
    /* ***************************************************************
     * Throughly test your stack. You must perform an exhaustive series
     * of tests on your stack. Show all possible ways your stack can be used
     * and abused and prove that your stack can gracefully handle ALL cases.
     * You must use automated testing (no user input). First cover all
     * explicit cases which you can think of, then execute random operations.
     * When generating test data, use random ints for ids and random short
     * strings for string. There is a string generator made for you in the
     * functions module. You are free to use it or make your own.
     * ***************************************************************/

    /* ***************************************************************
     * Below is some sample code for the random string function. It's
     * only here to demonstrate the function. DELETE it once you study
     * it and understand it and can use it yourself in your code.
     * ***************************************************************/
    


    

    
    /* ***************************************************************
     * Your code will be tested by applying your stack to a custom main
     * designed to break your code. If it can be broken, you risk a
     * substantially reduced grade, up to and including a zero.
     * ***************************************************************/
    
    // WHEN YOU SUBMIT, DELETE ALL THESE INSTRUCTIONALCOMMENTS
    
}
