/**
 * istreamIgnore.cpp
 *
 * @author Spencer Wilson
 * @date 2025-03-10
 *
 * a sample of how istream.ignore works
 * specifically for cin, but would also work for istringstream and ifstream... and istream will do
 * read the comments
 * read the asserts
 * tinker with it
 */
#include<iostream>
#include<cassert>
using namespace std;

int main()
{
    string word, line;

    cout << "please enter a string with prefixed whitespace" << endl;
    cin >> word;
    cout << "shouldn't have any whitespace on this first word:" << word << endl;
    getline( cin, line );
    cout << "here is the rest of the line that may have prefixed whitespace:" << line << endl;

    cout << "Please write a long line of text." << endl;
    cin >> word;
    cin.ignore(5);
    getline( cin, line );
    cout << "word: " << word << endl;
    cout << "line: " << line << endl;

    cout << "Please give me hello<ENDL>" << endl;
    cin >> word;   // hello<ENDL> in cin
    assert( word == "hello" ); // only hello stored in word
    cout << "please give me more text" << endl;
    getline( cin, line );  // user not actually prompted. <ENDL> consumed and the text before it is stored to line
    assert( line == "" );  // an empty string from nothing before <ENDL>

    cout << "Please give me 'hello stream world<ENDL>'" << endl;
    cin >> word;   // hello stream world<ENDL>
    assert( word == "hello" );  // only hello stored in word
    cout << "please give me more text" << endl;
    getline( cin, line );  // user not actually prompted. <ENDL> consumed and the text before it is stored to line
    // NOTE includes the space at the beginning!
    assert( line == " stream world" );

    // TINKER: how could you use a single user input to pass the following assert?
    // assert( line == "    stream world" );


    cout << endl << endl << "NOW USING cin.ignore()" << endl;
    // https://cplusplus.com/reference/istream/istream/ignore/
    
    cout << "Please give me 'hello<ENDL>'" << endl;
    cin >> word;   // hello<ENDL>
    cin.ignore();
    assert( word == "hello" );
    cout << "please give me 'sup<ENDL>'" << endl;
    getline( cin, line );  // finally asks user for input!
    assert( line == "sup" );

    cout << "Please give me 'hello stream world<ENDL>'" << endl;
    cin >> word;   // hello stream world<ENDL>
    cin.ignore(); // take the ' ' away from cin
    assert( word == "hello" );
    cout << "please give me 'sup<ENDL>'" << endl;
    getline( cin, line );  // not prompted, but the space is gone now!
    assert( line == "stream world" );
}


