/**
 * gradeAsPercentage.h
 * 
 * BUILD:
 * see driver.cpp
 */ 
#ifndef GRADE_AS_PERCENTAGE_H
#define GRADE_AS_PERCENTAGE_H

/**
 * GradeAsPercentage
 * 
 * efficiently store grade percentages as char [0 - 255]
 * but let the user get this value as a number
 * 
 * it's not super realistic of great code, but its something worth considering
 */
class GradeAsPercentage {
private: 
    char _percentage;  
public:  
    GradeAsPercentage( ); 
    GradeAsPercentage( char percentage );
    unsigned short getPercentage( );
    void setPercentage( char percentage ); 
    unsigned short representation;
};

#endif
