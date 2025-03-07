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

void iStringStream();
void constructorSample();
void rightArrow();
void demoStringManip();
// https://www.geeksforgeeks.org/stringstream-c-applications/
int countWords(string str);
void humanTestingCountWords();
void autoTestCountWords();
void handleYesNo( string fName );



int main()
{
    iStringStream();
    // constructorSample();
    // rightArrow();
    // demoStringManip();
    // autoTestCountWords();
    // humanTestingCountWords();
    return 0;
}


void iStringStream()
{
    cout << "ISS sample >>" << endl;
    istringstream iss("Space 1998 2011 ManyNations");
    string location, builders;
    int start, end;
    iss >> location >> start >> end >> builders;
    cout << "location: " << location << endl;
    cout << "start: " << start << endl;
    cout << "end: " << end << endl;
    cout << "builders: " << builders << endl;

    cout << "ISS sample getline" << endl;
    istringstream iss2("Space~1998~2011~many nations");
    string tmp;
    getline( iss2, location, '~');
    getline( iss2, tmp, '~');
    start = stoi(tmp);
    getline( iss2, tmp, '~');
    end = stoi(tmp);
    getline( iss2, builders, '~');
    cout << "location: " << location << endl;
    cout << "start: " << start << endl;
    cout << "end: " << end << endl;
    cout << "builders: " << builders << endl;

    cout << "ISS together" << endl;
    istringstream iss3("Is in outerspace^1998 2011 many nations built this$");
    getline( iss3, location, '^' );
    iss3 >> start >> end;
    getline( iss3, builders, '$' );
    cout << "location: " << location << endl;
    cout << "start: " << start << endl;
    cout << "end: " << end << endl;
    cout << "builders: " << builders << endl;

    return;
}

void constructorSample()
{
    // string str = "This,is,a,string";
    // stringstream sstr(str);
    // string word[4];
    // int i = 0;
    // while( getline(sstr, word[i], 'i') ) {
    //     i++;
    // }
    // cout << word[2] << endl;

    stringstream sstr( "This,is,a,string" );
    string word[4];
    for ( int i = 0; getline(sstr, word[i], 'i') ; i++ );
    cout << word[2] << endl;
    cout << "sstr is still: " << sstr.str() << endl;
    cout << "I'm surprised by the above result" << endl;

    stringstream ss4("yankee~zulu~moretext");
    string x;
    cout << "ss4 initialized: " << ss4.str() << endl;
    getline( ss4, x, '~');
    cout << "x: " << x << endl;
    ss4 << "echo~";
    ss4 << "foxtrot~";
    getline( ss4, x, '~');
    cout << "x: " << x << endl;
    getline( ss4, x, '~');
    cout << "x: " << x << endl;
    cout << "ss4 lacks zulu!? " << ss4.str() << endl;
    cout << "I'm surprised by the above result" << endl;

    return;
}
void rightArrow()
{
    stringstream y("hello there\nsup");
    cout << "y: " << y.str() << endl;
    string z;
    y >> z;
    cout << "y >> z: " << z << endl;
    getline( y, z, 'e' );
    cout << "getline( y, z, 'e' ): " << z << endl;
    return;
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


