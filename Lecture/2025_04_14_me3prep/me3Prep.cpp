/**
 * me3Prep.cpp
 * 
 * DISCLAIMER: the following code is not extensively tested
 * 
 * SPWI: complete description
 */ 
#include<iostream>
using namespace std;


// SPWI: fill in comments
class GradeAsPercentage {  //
private:  // 
    char _percentage;  // 
public:  // 
    GradeAsPercentage( );  // 
    GradeAsPercentage( char percentage );  // 
    unsigned short getPercentage( );  // 
    void setPercentage( char percentage );  // 
    unsigned short representation;  // 
};  // 

GradeAsPercentage::GradeAsPercentage( ) {
    _percentage = 0;
}

GradeAsPercentage::GradeAsPercentage( char percentage ) {
    _percentage = percentage;
}

unsigned short GradeAsPercentage::getPercentage( ) {
    return _percentage;
}

void GradeAsPercentage::setPercentage( char percentage ) {
    _percentage = percentage;
    _percentage %= 100;
}



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

unsigned short Gradebook::find_iterations( unsigned short count ) {
    unsigned short max_iterations = 0;
    if ( count > _MAX_MIDTERMS ) max_iterations = _MAX_MIDTERMS;
    else max_iterations = count;
    return max_iterations;
}

Gradebook::Gradebook( ) {
    // _midterms is set for us automatically
    _final = GradeAsPercentage( 0 );
}

// ASSUME the rest is implemented, or you will be asked to implement it.














// HIDDEN FROM SHEET:
int main( ) {

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


    // change some grades...
    GradeAsPercentage differentMidterms[3] = { {98}, {85}, {70} };
    gb.setMidterms( differentMidterms, 3 );
    gb.setFinal( {75} );
    gb.showTotal(); 
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
