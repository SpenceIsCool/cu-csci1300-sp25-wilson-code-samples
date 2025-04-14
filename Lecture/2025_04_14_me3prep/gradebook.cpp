/**
 * gradebook.cpp
 * 
 * BUILD:
 * see driver.cpp
 */
#include "gradebook.h"  // NOTE "", not <> and .h, not .cpp
#include "gradeAsPercentage.h"  // NOTE: this one is optional as it's included in  gradebook.h, but it's a good practice to have it anyway
#include<iostream>
using namespace std;


/**
 * find_iterations
 * find the minimum of _MAX_MIDTERMS and count
 * could have just been a call to min
 * 
 * this is a private member function as it is used many times in the class 
 * but the user shouldn't need to call it
 * 
 * @param count: a number to consider
 * @returns: the lower of the capacity of the array vs the number to consider
 */
unsigned short Gradebook::find_iterations( unsigned short count ) {
    unsigned short max_iterations = 0;
    if ( count > _MAX_MIDTERMS ) max_iterations = _MAX_MIDTERMS;
    else max_iterations = count;
    return max_iterations;
}


/**
 * Gradebook
 * default constructor
 * 
 * _midterms is set for us automatically
 * this is becauge GradeAsPercentage has a default constructor
 * if not, we would have a problem...
 */
Gradebook::Gradebook( ) 
{
    _final = GradeAsPercentage( 0 );
}


/**
 * Gradebook
 * one of the parameterized constructors
 * not fully parameterized, only sets some of the encapsulated values
 * 
 * @param final: the final value to set
 */
Gradebook::Gradebook( GradeAsPercentage final ) 
{
    _final = final;
}


/**
 * Gradebook
 * one of the parameterized constructors
 * this is fully parameterized as it sets all of the encapsulated values
 * 
 * @param midterms: a collection of midterm grades
 * @param count: the number of midterm grades in midterms that we care to set
 * @param final: the final value to set
 */
Gradebook::Gradebook( GradeAsPercentage midterms[], unsigned short count, GradeAsPercentage final ) 
{
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


/**
 * showTotal
 * if the final exam grade is higher than the midterm average, then the final is the total
 * else, the average of the 4 exams is the total
 */
void Gradebook::showTotal( ) 
{
    // calculate the midterm average
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


/**
 * getMidterms
 * get the midterm grades using pass-by-reference and return the length of the set array
 * 
 * @param midterms: a collection of midterm grades
 * @param count: the number of midterm grades that we wish to collect
 * @return: the count of midterm grades actually collected
 */
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


/**
 * setMidterms
 * set the midterm grades
 * 
 * if count it bigger than _MAX_MIDTERMS than only set the first _MAX_MIDTERMS
 * 
 * @param midterms: a collection of midterm grades
 * @param count: the number of midterm grades that we wish to set
 */
void Gradebook::setMidterms( GradeAsPercentage midterms[], unsigned short count )
{
    unsigned short len = find_iterations( count );
    for ( unsigned short i = 0 ; i < len ; i++ ) {
        _midterms[i] = midterms[i];
    }
}


/**
 * getFinal
 * get the final grade
 * 
 * @returns: _final
 */
GradeAsPercentage Gradebook::getFinal( ) 
{
    return _final;
}


/**
 * setFinal
 * set the final exam grade
 * 
 * @param final: the exam grade to set
 */
void Gradebook::setFinal( GradeAsPercentage final )
{
    _final = final;
}

