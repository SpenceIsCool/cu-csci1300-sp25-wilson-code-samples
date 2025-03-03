#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    ifstream file_input;
    file_input.open("lies.txt");
    // file_input.open("readMe.txt");
    string line = "";
    int line_idx = 0;
    // get the next line from the file and store in 'line' variable
    // continue looping as long as there is data to be processed in the file
    while ( getline(file_input, line) )
    {

        // print each line read from the file
        cout << line_idx << ": " << line << endl;

        // increment index(count of lines in the file)
        line_idx++;   
    }
    return 0;
}
