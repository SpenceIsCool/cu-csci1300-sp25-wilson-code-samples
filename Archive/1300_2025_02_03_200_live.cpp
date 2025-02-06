#include<iostream>
using namespace std;

double extraSilly()
{
    cout << "I'm so Silly" << endl;
    return 3.14;
}

// function is named silly
// it has no paremeters () instead of ( int x0 )
// it stated a return type int
int silly()
{
    extraSilly();
    extraSilly();
    extraSilly();
    extraSilly();
    return 14;
}


// a better silly function
void aBetterSillyFunction()
{
    extraSilly();
    extraSilly();
    extraSilly();
    extraSilly();
    return;
}

// main is a function
// so can we let it return void?
// main shall always return `int` in C++
int main()
{
    // this is not a void, it returns 14
    // why doesn't it print
    int mySpecialSillyReturnValue;
    mySpecialSillyReturnValue = silly();
    cout << mySpecialSillyReturnValue << endl;

    // this is a void
    aBetterSillyFunction();
    // why does main so often return 0?
    // does this number matter?
    // 0 is an "exit status" that means "all good"
    // there are non-zero values that mean some specific error
    //       has occured while running this main function
    //       use EXIT_FAILURE
    return 0;
}

// can we call main from down here?
// ill-advised. I think it's allowed.
