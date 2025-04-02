// Detective.h
#include<string>
using namespace std;

class Detective
{
public:
    Detective(); // must have the default to help with later array stuff
    Detective( string n, unsigned short s );
    void print() const;
    // common to have "getters" and "setters"
    string getName();
    unsigned short getSolvedCases();
    void setName( string newName );
    void setSolvedCases( unsigned short newSolvedCases );
private:
    string name;
    unsigned short solvedCases;
    // that one case that haunts them
    // EvilVillan theirNemisis
};


