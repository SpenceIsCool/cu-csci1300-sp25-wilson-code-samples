/**
 * driver.cpp
 * 
 * BUILD
 * g++ -std=c++17 -Wall -Werror -Wpedantic -Wsign-compare gradeAsPercentage.cpp gradebook.cpp driver.cpp
 * 
 * OBSERVE: the above uses .cpp, NOT .h
 */
#include "gradebook.h"
#include "gradeAsPercentage.h"  // optional, but good to have


void scenario1();
void scenario2();


int main( ) {
    scenario1();
    scenario2();
}


/**
 * scenario 1: 
 * final exam grade replacement used
 */
void scenario1() {
    // default constructor, splitting declaration and initialization
    GradeAsPercentage me1;
    me1 = GradeAsPercentage();
    me1.setPercentage( 66 );

    // default constructor, combining declaration and initialization
    GradeAsPercentage me2 = GradeAsPercentage();
    me2.setPercentage( 64 );

    // parameterized constructor
    GradeAsPercentage me3 = GradeAsPercentage( 65 );

    // creating array (required in C++ due to pass by reference behavior)
    GradeAsPercentage arr[3] = { me1, me2, me3 };

    // parameterized constructor
    Gradebook gb = Gradebook( arr, 1, { 98 } );
    gb.showTotal();
}


/**
 * scenario 2
 * actual average used
 */
void scenario2( ) 
{
    Gradebook gb = Gradebook();
    GradeAsPercentage differentMidterms[3] = { {98}, {85}, {70} };
    gb.setMidterms( differentMidterms, 3 );
    gb.setFinal( {75} );
    gb.showTotal(); 
}

