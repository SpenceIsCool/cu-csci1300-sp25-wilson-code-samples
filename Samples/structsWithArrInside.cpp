#include<iostream>
using namespace std;

// struct Alpha {
//     // must state length
//     int bravo[];
// };

struct Alpha {
    int bravo[3];
};

void foo( Alpha a );
void bar( Alpha as[5] );

int main()
{
    Alpha charlie = { {1300,10,15} };
    
    cout << "COPY charlie to delta" << endl;
    Alpha delta = charlie;
    cout << "CHANGING element of charlie" << endl;
    charlie.bravo[0] = 5;
    cout << "SHOWING same element of delta\n\tif 5, then the copy is changed\n\telse, the copy is 'deep' and uneffected'" << endl;
    cout << delta.bravo[0] << endl;

    cout << "BEFORE the function that might pass-by-refence" << endl;
    for ( int i = 0 ; i < 3 ; i++ )
    {
        cout << charlie.bravo[i] << endl;
    }

    foo( charlie );

    cout << endl
         << "AFTER the function that might pass-by-refence"
         << endl
         << "if it is passed by reference: 6, 11, 16"
         << endl
         << "else it's by value: 5, 10, 15"
         << endl;
    for ( int i = 0 ; i < 3 ; i++ )
    {
        cout << charlie.bravo[i] << endl;
    }


    cout << "\n\n\nWhat about an array of these?" << endl;
    Alpha many[5] = { charlie, charlie, charlie, charlie, charlie };
    bar(many);
    cout << "{ " << endl;
    for ( int i = 0 ; i < 5 ; i++ )
    {
        if ( i != 0 )
        {
            cout << ", " << endl;
        }
        cout << "{ ";
        for ( int j = 0 ; j < 3 ; j++ )
        {
            if ( j != 0 )
            {
                cout << ", ";
            }
            cout << many[i].bravo[j];
        }
        cout << " }";
    }
    cout << " }" << endl;
}

/**
 * foo
 * I want to know if the array inside will change
 */
void foo( Alpha a )
{
    for ( int i = 0 ; i < 3 ; i++ )
    {
        a.bravo[i]++;
    }
}


void bar( Alpha as[5] )
{
    for ( int i = 0 ; i < 5*3 ; i++ )
    {
        as[i%5].bravo[i%3] += i;
    }
    return;
}
