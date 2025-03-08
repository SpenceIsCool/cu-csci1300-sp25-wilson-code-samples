// myFStream300.cpp
#include<iostream>
#include<fstream>
using namespace std;

int main( )
{
    // create an input file stream object
    ifstream file_input;

    // open myTextFile.txt with the file stream object
    string x;
    cout << "please give me a filename:" << endl;
    cin >> x;
    file_input.open( x ); 

    // check if file opened successfully
    if ( file_input.fail() )
    {
        cout << "Could not open file." << endl;
        return EXIT_FAILURE;
    }
    
    // since the if returns, we don't need an else...

    // do things with the file
    string line = "";
    int line_idx = 1;
    bool keepGoing = true;
    int countComma = 0;

    // read each line from the file
    while ( keepGoing && !file_input.eof() )  //  EOF: end of file
    {
        if ( line_idx > 10 )
        {
            keepGoing = false;
        }
        // gets line of text from file_input, stores it in line
        getline( file_input, line );

        // print each line read from the file
        cout << "LINE: " << line_idx << ": " << line << endl;

        // increment index (count of lines in the file)
        line_idx++;   

        for (size_t i = 0 ; i < line.length() ; i++ )
        {
            if ( line[i] == ';' )
            {
                countComma++;
            }
        }
    }

    cout << "and the first 11 lines of the file had " << countComma << " commas." << endl;

    // closing the file
    file_input.close( );
    return 0;
}