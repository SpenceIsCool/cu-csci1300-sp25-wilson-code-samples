/**
 * istreamIgnore.cpp
 *
 * @author Spencer Wilson
 * @date 2025-03-10
 *
 * a sample of how ignore works
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

    cout << "Please give me hello<ENDL>" << endl;
    cin >> word;   // hello<ENDL>
    assert( word == "hello" );
    cout << "please give me more text" << endl;
    getline( cin, line );  // user not actually prompted. <ENDL> consumed and the text before it is stored to line
    assert( line == "" );

    cout << "Please give me 'hello stream world<ENDL>'" << endl;
    cin >> word;   // hello<ENDL>
    assert( word == "hello" );
    cout << "please give me more text" << endl;
    getline( cin, line );  // user not actually prompted. <ENDL> consumed and the text before it is stored to line
    // NOTE includes the space at the beginning!
    assert( line == " stream world" );

    // TINKER: how could you use a single user input to pass the following assert?
    // assert( line == "    stream world" );

    cout << endl << endl << "NOW USING cin.ignore()" << endl;
    cout << "Please give me 'hello<ENDL>'" << endl;
    cin >> word;   // hello<ENDL>
    cin.ignore();
    assert( word == "hello" );
    cout << "please give me 'sup<ENDL>'" << endl;
    getline( cin, line );  // user not actually prompted. <ENDL> consumed and the text before it is stored to line
    // NOTE includes the space at the beginning!
    assert( line == "sup" );

    cout << "Please give me 'hello stream world<ENDL>'" << endl;
    cin >> word;   // hello stream world<ENDL>
    cin.ignore();
    assert( word == "hello" );
    cout << "please give me 'sup<ENDL>'" << endl;
    getline( cin, line );  // not prompted, but the space is gone now!
    assert( line == "stream world" );

}
