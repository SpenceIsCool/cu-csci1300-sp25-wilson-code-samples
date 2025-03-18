#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    string fn = "myFileThatReallyShouldNotExistSoICanTriggerAnError.txt";
    ifstream fR;
    fR.open( fn );
    fR.close();
    return 0;
}


