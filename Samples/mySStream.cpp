/**
 * want to learn more about sstream
 * `s`tring `stream`
 * it's a type of stream (like cin and cout are also stream in iostream)
 * an iterable linear collection
 */
#include<iostream>
// it is it's own library
#include<sstream>
#include<cassert>
using namespace std;

void demoStringManip();
// https://www.geeksforgeeks.org/stringstream-c-applications/
int countWords(string str);
void humanTestingCountWords();
void autoTestCountWords();
void handleYesNo( string fName );



int main()
{
    demoStringManip();
    autoTestCountWords();
    humanTestingCountWords();
    return 0;
}


void demoStringManip()
{
    string s;
    stringstream ss;
    
    cout << "string streams are strings that act like streams (support >> and <<)." << endl;
    cout << "read the demoStringManip function to know more" << endl;

    s = "Hello";
    s += ", World";
    // It's hard to append a number to a string
    // can't do directly
    // cout << (int)'!' << endl;
    // char for `!` NOT the number 33
    s += 33; 
    // ALSO important to note the `+=` on a string is a VERY expensive operation
    cout << s << endl;


    // NOW the number is a number and not a char
    // cause why would someone naturally use 33 to mean `!` 
    // that wouldn't be something many of us want
    ss << "Hello" << ", World"  << 33;
    // cout << ss << endl;  // NOPE: big error
    // NOTE: <stringstream>.str() is expensive but it's less expensive than all the +=
    s = ss.str();
    cout << s << endl;

    handleYesNo( "demoStringManip" );
    return;
}


void autoTestCountWords()
{
    cout << "BEGIN: autoTestCountWords" << endl;
    assert( 1 == countWords("hello") );
    assert( 5 == countWords("welcome to learning about sstream.") );
    cout << "$$$$$$ ALL TESTS PASSED in autoTestCountWords!" << endl;
    return;
}

void handleYesNo( string fName )
{
    string userInput;
    bool ask;
    
    ask = true;
    while (ask)
    {
        cout << "Does that look correct? [yes/no]" << endl;
        getline(cin, userInput);
        if ( userInput != "yes" && userInput != "no" ) cout << "let's try that again... answer yes or no." << endl;
        else 
        {
            assert( "yes" == userInput );
            cout << "$$$$$$ ALL TESTS PASSED in " << fName << endl;
            ask = false;
        }
    }

    return;
}

void humanTestingCountWords()
{
    string userInput;
    int count;

    cout << "BEGIN: humanTestingCountWords" << endl;
    
    cout << "please give me a string" << endl;
    getline(cin, userInput);
    count = countWords(userInput);
    cout << "that sentence has " << count << " words separated by spaces." << endl;

    handleYesNo( "humanTestingCountWords" );
    return;
}

/**
 * countWords
 * adapted from: https://www.geeksforgeeks.org/stringstream-c-applications/
 * 
 * @param str: 
 * @returns: a number
 */
int countWords(string str)
{
    // Breaking input into word 
    // using string stream
  
    // Used for breaking words
    stringstream s(str); 
  
    // To store individual words
    string word; 

    int count = 0;
    // we know from cin >> word, that >> gets only a word
    // we use getline(cin, sentence) instead.
    while (s >> word)
        count++;
    return count;
}


