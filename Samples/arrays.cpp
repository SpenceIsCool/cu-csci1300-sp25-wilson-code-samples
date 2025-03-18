// arrays.cpp
#include<iostream>
using namespace std;


int array_simple( )
{
    int y[5] = { 2, 4, 6, 8, 10 };
    int x = y[3];
    return x;
}

int multiD_array( )
{
    const int ROW = 5;
    const int COL = 10;
    int y[ ROW ][ COL ] = {};
    int count = 0;
    for ( int row = 0 ; row < 5 ; row++ )
    {
        for ( int col = 0 ; col < 10 ; col++ )
        {
            y[row][col] = count;
            count++;
        }
    }
    return count;
}

int ref_1D( int arr[], int len )
{
    int prodSoFar = 1;
    for ( int i = 0 ; i < len ; i++ ) 
    {
        prodSoFar *= arr[i];
        arr[i] = prodSoFar;
    }
    return prodSoFar;
}

void show_arr1D( int arr[ ], int len )
{
    cout << "{ ";
    for ( int i = 0 ; i < len ; i++ )
    {
        if ( i != 0 )
        {
            cout << ", ";
        }
        cout << arr[i];
    }
    cout << " }" << endl;
}
int main ( )
{
    cout << "array_simple: " << array_simple( ) << endl;
    cout << "multiD_array: " << multiD_array( ) << endl;
    const int LEN = 5;
    int arr1D[LEN] = { 2, 4, 6, 8, 10 };
    cout << "ref_1D: " << ref_1D( arr1D, LEN ) << endl;
    show_arr1D( arr1D, LEN );
    return 0;
}

