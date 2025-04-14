/**
 * gradeAsPercentage.cpp
 * 
 * BUILD:
 * see driver.cpp
 */ 
#include "gradeAsPercentage.h"  // NOTE "", not <>


/**
 * GradeAsPercentage
 * default constructor
 * set percentage to 0 if not specified
 */
GradeAsPercentage::GradeAsPercentage( ) 
{
    _percentage = 0;
}


/**
 * GradeAsPercentage
 * parameterized constructor
 * 
 * @param percentage: the percentage to set
 */
GradeAsPercentage::GradeAsPercentage( char percentage ) 
{
    _percentage = percentage;
    _percentage %= 101;
}


/**
 * getPercentage
 * return the percentage as a small number rather than a char
 * this is perhaps an odd design choice of the developer
 * 
 * @return the encapsulated percentage value
 */
unsigned short GradeAsPercentage::getPercentage( ) 
{
    return _percentage;
}


/**
 * setPercentage
 * round all values on 100
 * perhaps a max would work better, but I wanted to review modulus `%`
 * 
 * @param percentage: the percentage to encapsulate
 */
void GradeAsPercentage::setPercentage( char percentage ) 
{
    _percentage = percentage;
    _percentage %= 101;
}

