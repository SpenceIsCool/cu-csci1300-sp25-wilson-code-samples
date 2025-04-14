/**
 * gradebook.h 
 * 
 * BUILD:
 * see driver.cpp
 */ 
#ifndef GRADEBOOK_H
#define GRADEBOOK_H
#include "gradeAsPercentage.h"  // NOTE <> not "" and .h not .cpp


/**
 * Gradebook
 * 
 * encapuslates the exam grades of CSCI1300 for a single student in Spring 2025
 * aims to help better understand the final exam grade replacement policy
 * 
 * not the best design...
 * as it only has the exam grades 
 * and it only considers one student instead of many students
 * but it's good enough for our purposes today
 */
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


#endif

