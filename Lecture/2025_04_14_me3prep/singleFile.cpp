/**
 * singleFile.cpp
 * 
 * BUILD:alignof
 * g++ -std=c++17 -Wall -Werror -Wpedantic -Wsign-compare singleFile.cpp
 * 
 * DISCLAIMER: the following code is not extensively tested
 * 
 * note that the mulitple file version of this is also available in the same folder as this on GitHub
 */ 
#include<iostream>
using namespace std;






// ideally it's own file gradeAsPercentage.h if GRADE_AS_PERCENTAGE_H ifndef
class GradeAsPercentage {  // the class declaration
private:  // a keyword for encapsulation (hiding stuff)
    char _percentage;  // data member (D)
public:  // a keyword for controlling how people can deal with the encapsulated data
    GradeAsPercentage( );  // member function (F), specifically a constructor (C), specifically the default constructor
    GradeAsPercentage( char percentage );  // member function (F), specifically a constructor (C), specifically the parameterized constructor
    unsigned short getPercentage( );  // member function (F)
    void setPercentage( char percentage );  // member function (F) 
    unsigned short representation;  // data member (D) typically private only, but it doesn't have to be. this one isn't implemented anywhere
};  // don't forget the `;`







// ideally it's own gradeAsPercentage.cpp
GradeAsPercentage::GradeAsPercentage( ) {
    _percentage = 0;
}

GradeAsPercentage::GradeAsPercentage( char percentage ) {
    _percentage = percentage;
    _percentage %= 100;
}

unsigned short GradeAsPercentage::getPercentage( ) {
    return _percentage;
}

void GradeAsPercentage::setPercentage( char percentage ) {
    _percentage = percentage;
    _percentage %= 100;
}






// ideally it's own file gradebook.h if GRADEBOOK_H ifndef
class Gradebook {
public:
    Gradebook( );
    Gradebook( GradeAsPercentage final );
    Gradebook( GradeAsPercentage midterms[ ], unsigned short count, GradeAsPercentage final );
    void showTotal( );
    // arrays often use pass-by-reference and return true count
    unsigned short getMidterms( GradeAsPercentage midterms[ ], unsigned short count );
    void setMidterms( GradeAsPercentage midterms[ ], unsigned short count );
    GradeAsPercentage getFinal( );
    void setFinal( GradeAsPercentage final );
private:
    unsigned short find_iterations( unsigned short count );
    const static unsigned short _MAX_MIDTERMS = 3;
    GradeAsPercentage _midterms[ _MAX_MIDTERMS ];
    GradeAsPercentage _final;
};






// ideally it's own gradebook.cpp
unsigned short Gradebook::find_iterations( unsigned short count ) {
    unsigned short max_iterations = 0;
    if ( count > _MAX_MIDTERMS ) max_iterations = _MAX_MIDTERMS;
    else max_iterations = count;
    return max_iterations;
}

Gradebook::Gradebook( ) {
    // _midterms is set for us automatically
    // this is becauge GradeAsPercentage has a default constructor
    // if not, we would have a problem...
    _final = GradeAsPercentage( 0 );
}

Gradebook::Gradebook( GradeAsPercentage final ) {
    _final = final;
}

Gradebook::Gradebook( GradeAsPercentage midterms[], unsigned short count, GradeAsPercentage final ) {

    // set the midterm grades
    // user might give more midterms than we support, if so only copy in the first _MAX_MIDTERMS
    // set the max iteration as the min of count and _MAX_MIDTERMS
    unsigned short max_iterations = find_iterations( count );
    // set the allowable midterms (RECALL _midterms = midterms won't work, arrays don't copy easily [in c++])
    for ( unsigned short i = 0 ; i < max_iterations ; i++ ) {
        _midterms[i] = midterms[i];
    }
    

    // set the final grade
    _final = final;
}

void Gradebook::showTotal( ) {
    // if the final exam grade is higher than the midterm average, then the final is the total
    // else, the average of the 4 exams is the total

    // get the midterm average
    unsigned short sum, avg;
    sum = 0;
    for ( unsigned short i = 0 ; i < _MAX_MIDTERMS ; i++ ) {
        sum += _midterms[i].getPercentage( );
    }
    avg = sum / _MAX_MIDTERMS;

    // maybe total average
    if ( avg > _final.getPercentage() ) avg = ( sum + _final.getPercentage() ) / ( _MAX_MIDTERMS + 1 );
    // maybe final only
    else avg = _final.getPercentage();

    cout << avg << endl;
}


unsigned short Gradebook::getMidterms( GradeAsPercentage midterms[], unsigned short count ) {
    unsigned short len = find_iterations( count );
    for ( unsigned short i = 0 ; i < len ; i++ ) {
        // exploit pass-by-reference
        // assumes the user gave us a long enough array
        midterms[i] = _midterms[i];
    }
    // return the current count
    return len;
}

void Gradebook::setMidterms( GradeAsPercentage midterms[], unsigned short count ) {
    unsigned short len = find_iterations( count );
    for ( unsigned short i = 0 ; i < len ; i++ ) {
        _midterms[i] = midterms[i];
    }
}

GradeAsPercentage Gradebook::getFinal( ) {
    return _final;
}

void Gradebook::setFinal( GradeAsPercentage final ) {
    _final = final;
}











// ideally in it's own driver file like gradebookDriver.cpp
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
void scenario2() {


    Gradebook gb = Gradebook();
    GradeAsPercentage differentMidterms[3] = { {98}, {85}, {70} };
    gb.setMidterms( differentMidterms, 3 );
    gb.setFinal( {75} );
    gb.showTotal(); 
}











