#include<iostream>
#include<fstream>
#include<cassert>
using namespace std;


struct PlayableCharacter
{
    string name;
    unsigned int killCount;
    unsigned int deathCount;
    unsigned int assistCount;
    unsigned int killsInARow;
};


void displayPC( PlayableCharacter pc );
PlayableCharacter takedown( PlayableCharacter pc );
void testPC();

int main()
{
    bool testing = false;
    string saveFileName = "saveFile.txt", tmp;
    ofstream saveFileWriter;
    ifstream saveFileReader;
    bool keepGoing = true;
    // TODO: figure out how to have more players. this is just a lazy sketch of the final product
    PlayableCharacter myOnlyPlayer{};

    if ( testing )
    {
        testPC();
        cout << "ALL TESTS PASSED!" << endl;
    }

    // Q200: why is the menu directly in main? 
    //       I usually don't put it here like this, but I was having
    //       struct issues this morning. Will try to update for wednesday
    while ( keepGoing )
    {
        int input = -1;
        while ( input <= 0 || input > 7 )
        {
            cout << endl << endl << endl
                    << "Please select from the following:" << endl
                    << "1. make a player" << endl
                    << "2. load a previous player" << endl
                    << "3. takedown an enemy" << endl
                    << "4. your hand slipped" << endl
                    << "5. provide great support" << endl
                    << "6. review your stats" << endl
                    << "7. save and exit" << endl;
            cin >> input;
            cin.ignore(); // great practice after >>
            if ( input <= 0 || input > 7 )
            {
                cout << "Does not compute, please input a valid input" << endl;
            }
        }

        switch ( input )
        {
            case 1:
                myOnlyPlayer = { "", 0, 0, 0 };
                cout << "What is the characters name?" << endl;
                // cin >> p.name;  // works, but I want to allow spaces like "Miss Fortune"
                getline( cin, myOnlyPlayer.name );
                break;
            case 2:
                myOnlyPlayer = { "", 0, 0, 0 };
                saveFileReader.open( saveFileName );
                if ( saveFileReader.fail( ) )
                {
                    cout << "Something went horribly wrong. Cannot recover" << endl;
                    cout << "Exiting without save" << endl;
                    keepGoing = true;
                }
                else
                {
                    // file should contain one line
                    // it should be of the form
                    // name,killCount,deathCount,assistCount,killsInARow;
                    getline( saveFileReader, myOnlyPlayer.name, ',' );
                    // Q200: What is stoi?
                    //       Lecture from Friday has some more detail
                    //       getline requires a string 
                    //       tmp is a string
                    //       but I expected it to be an integer
                    //       stoi: sTRING to iNTEGER
                    //       note also: stod: sTRING to dOUBLEw
                    getline( saveFileReader, tmp, ',' );
                    myOnlyPlayer.killCount = stoi(tmp);
                    getline( saveFileReader, tmp, ',' );
                    myOnlyPlayer.deathCount = stoi(tmp);
                    getline( saveFileReader, tmp, ',' );
                    myOnlyPlayer.assistCount = stoi(tmp);
                    getline( saveFileReader, tmp, ',' );
                    myOnlyPlayer.killsInARow = stoi(tmp);
                }
                saveFileReader.close();
                cout << "SUCCESSFUL LOAD: ";
                displayPC( myOnlyPlayer );
                break;
            case 3:
                cout << myOnlyPlayer.name << " takedown";
                myOnlyPlayer.killCount++;
                myOnlyPlayer.killsInARow++;
                if ( myOnlyPlayer.killsInARow == 5 ) 
                {
                    cout << " PENTAKILL";
                }
                if ( myOnlyPlayer.killsInARow >= 8 ) 
                {
                    cout << " You are LEGENDARY";
                }
                cout << endl;
                break;
            case 4:
                cout << myOnlyPlayer.name << " has been defeated";
                myOnlyPlayer.deathCount++;
                if ( myOnlyPlayer.killsInARow > 0 )
                {
                    cout << " SHUTDOWN.";
                }
                myOnlyPlayer.killsInARow = 0;
                cout << endl;
                break;
            case 5:
                myOnlyPlayer.assistCount++;
                break;
            case 6:
                displayPC( myOnlyPlayer );
                break;
            case 7:
                keepGoing = false;
                // ofstream saveFileWriter
                saveFileWriter.open( saveFileName );
                if ( saveFileWriter.fail( ) )
                {
                    cout << "Something went horribly wrong. Cannot recover" << endl;
                    cout << "Exiting without save" << endl;
                }
                else
                {
                    // name,killCount,deathCount,assistCount
                    saveFileWriter << myOnlyPlayer.name << ','
                            << myOnlyPlayer.killCount << ','
                            << myOnlyPlayer.deathCount << ','
                            << myOnlyPlayer.assistCount << ','
                            << myOnlyPlayer.killsInARow << endl;
                    saveFileWriter.close();
                    cout << "SAVE successful. goodbye." << endl;
                }
                break;
            default:
                cout << "Something went horribly wrong. Cannot recover" << endl;
                cout << "Exiting without save" << endl;
                keepGoing = false;
        }
    }
    return 0;
}


void testPC()
{
    PlayableCharacter p0{ "Seraphine", 0, 1, 15 };
    assert( p0.name == "Seraphine" );
    assert( !p0.killCount );
    assert( p0.deathCount == 1 );
    assert( p0.assistCount == 15 );

    PlayableCharacter p1;
    p1.name = "gnar";
    p1.killCount = 10;
    p1.deathCount = 0;
    p1.assistCount = 2;
    assert( p1.name == "gnar" );
    assert( p1.killCount == 10 );
    assert( p1.deathCount == 0 );
    assert( p1.assistCount == 2 );

    p1.killCount++;
    assert( p1.killCount == 11 );
}


void displayPC( PlayableCharacter pc )
{
    cout << pc.name << ": " 
         << pc.killCount << "/" 
         << pc.deathCount << "/" 
         << pc.assistCount << endl;
    return;
}


