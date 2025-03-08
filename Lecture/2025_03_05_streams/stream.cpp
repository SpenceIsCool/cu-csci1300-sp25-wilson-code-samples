// stream.cpp
#include<iostream>
#include<fstream>
using namespace std;

int main( )
{
    // create an input file stream object
    ifstream file_input;

    // open myTextFile.txt with the file stream object
    file_input.open( "myTextFile.txt" ); 

    // check if file opened successfully
    if ( file_input.fail() )
    {
        cout << "Could not open file." << endl;
        return EXIT_FAILURE;
    }
    
    // since the if returns, we don't need an else...

    // do things with the file
    string line = "";
    int line_idx = 0;

    // read each line from the file
    while ( !file_input.eof() )
    {
        // gets line of text from file_input, stores it in line
        getline( file_input, line );

        // print each line read from the file
        cout << line_idx << ": " << line << endl;

        // increment index (count of lines in the file)
        line_idx++;   
    }

    // closing the file
    file_input.close( );
    return 0;
}