

//
// IMPORT STUFF
//


#include<iostream>  // cout, endl
#include<cassert>  // assert
using namespace std;


//
// DECALARE HELPERS
//


char encryptLower(char letter, int shift_value);
void testEncrypt( );




//
// DEFINE MAIN
//

int main() {
   
    // can comment me out before submission
    testEncrypt();
    
    // I was provided on the web-workbook
    // I should be changed before final submission
    char letter = 'r';
    char encrypted_letter = encryptLower(letter, 5);
    cout << "Letter " << letter << " was encrypted to " << encrypted_letter << endl;
    return 0;
} 


//
// DEFINE ALL HELPER FUNCTIONS
//


/**
 * encryptLower
 * given a lowercase letter
 * shift the value to allow for encryption of the character
 */
char encryptLower(char letter, int shift_value)
{
    // change me to false before submission!
    // so the debug prints don't happen!
    bool debug = true;
    if (debug) cout << "\n\nTESTING: " << letter << " shifted by " << shift_value << endl;
    if (debug) cout << "I am a guarded print statement. I can be helpful for debugging code." << endl;
    
    // write psudo-code comments here before you code

    return letter;
}


void testEncrypt( )
{
    // I'm the easy tests...
    assert( ',' == encryptLower(',' , 1));
    assert( 'D' == encryptLower('D' , 1));
    
    // // uncomment me in blocks
    // assert( 'b' == encryptLower('a' , 1));
    // assert( 'c' == encryptLower('a' , 2));
    // assert( 'd' == encryptLower('a' , 3));

    // // uncomment me in blocks
    // assert( 'b' == encryptLower('c' , -1));
    // assert( 'a' == encryptLower('c' , -2));

    // // I'm a bit harder (consider using `%` as part of solution)
    // assert( 'a' == encryptLower('a' , 26));
    // assert( 'c' == encryptLower('a' , 28));

    // // I am even harder
    // assert( 'a' == encryptLower('z' , 1));
    // assert( 'b' == encryptLower('z' , 2));
    // assert( 'z' == encryptLower('a' , -1));
    // assert( 'y' == encryptLower('a' , -2));

    // // I am likely extra hard tests
    // // consider an `unsigned char`
    // assert( 'u' == encryptLower('s', -50));
    // assert( 'v' == encryptLower('z', 22));
}

