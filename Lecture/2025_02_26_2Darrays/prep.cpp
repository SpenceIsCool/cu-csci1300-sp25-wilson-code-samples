#include<iostream>
#include<cassert>
using namespace std;



void traverse1D();
void traverse1DImproved( int arr[], const int SIZE );
int findLargestValue( int arr[], const int SIZE );
int findIndexOfLargestValue( int arr[], const int SIZE );
int findLargestValueImproved( int arr[], const int SIZE );
int findSmallestValue( int arr[], const int SIZE );
int findIndexOfSmallestValue( int arr[], const int SIZE );
int findIndexOfSomeEvenValue( int arr[], const int SIZE );
void copyArray();
void swap2();

int main()
{
    // traverse1D();
    const int MY_SIZE = 8;
    int my_arr[ MY_SIZE ] = { 13, 21, 5, 1, 2, 3, 8, 1 };
    // traverse1DImproved( my_arr, MY_SIZE );
    assert( 21 == findLargestValue( my_arr, MY_SIZE ) );
    // recall index from 0
    // 21 is at index 1
    assert( 1 == findIndexOfLargestValue( my_arr, MY_SIZE ) );
    assert( 21 == findLargestValueImproved( my_arr, MY_SIZE ) );
    // there are two 1s in this
    // get the left-most one
    // recall indexes from 0
    assert( 3 == findIndexOfSmallestValue( my_arr, MY_SIZE ) );
    assert( 1 == findSmallestValue( my_arr, MY_SIZE ) );
    // gets the right most value. the 8 at index 6
    assert( 6 == findIndexOfSomeEvenValue( my_arr, MY_SIZE ) );
    copyArray();
    swap2();
    return 0;
}


/**
 * no, this is not the great function for using "pass-by-reference" to swap 2 values.
 * it's just a toy
 * Ask on Ed or consult the internet if you want to see the real function.
 */
void swap2()
{
    const int MY_SIZE = 8;
    int my_arr[ MY_SIZE ] = { 13, 21, 5, 1, 2, 3, 8, 1 };

    // swap 13 for 21
    int tmp = my_arr[0];
    my_arr[0] = my_arr[1];
    my_arr[1] = tmp;

    traverse1DImproved( my_arr, MY_SIZE );

    return;
}

/**
 * C++ doesn't let us copy arrays directly
 * no, this is not the great function for creating a "deep copy"
 * this is a sample. Ask on Ed or consult the internet if you want to see the real function.
 */
void copyArray()
{
const int MY_SIZE = 8;
int my_arr[ MY_SIZE ] = { 13, 21, 5, 1, 2, 3, 8, 1 };

// // error: array initializer must be an initializer list
// int my_arr_copy[ MY_SIZE ] = my_arr;

int my_arr_copy[ MY_SIZE ] = {};
for ( int i = 0 ; i < MY_SIZE ; i++ )
{
    my_arr_copy[ i ] = my_arr[ i ];
}

// add a new traversal to print the array if you're interested

    return;
}

/**
 * assume array is not empty
 * get the right-most even value, else return -1
 */
int findIndexOfSomeEvenValue( int arr[], const int SIZE )
{
    int index = 0;
    for ( int i = 0 ; i < SIZE ; i++ )
    {
        int elmt = arr[i];
        if ( elmt%2 == 0 )
        {
            index = i;
            // // can put a `break` here to get the left-most even value
            // break;
        }
    }

    cout << index << endl;

    return index;
}

int findSmallestValue( int arr[], const int SIZE )
{
    return arr[ findIndexOfSmallestValue( arr, SIZE) ];
}
/**
 * assume array is not empty
 * if equal small values, return the left most index of equal values
 */
int findIndexOfSmallestValue( int arr[], const int SIZE )
{
    int index = 0;
    for ( int i = 0 ; i < SIZE ; i++ )
    {
        int elmt = arr[i];
        if ( elmt < arr[index] )
        {
            index = i;
        }
    }

    cout << index << endl;

    return index;

}

/**
 * like findLargestValue
 * but shorter, just call findLargestValueByIndex
 */
int findLargestValueImproved( int arr[], const int SIZE )
{
    // // feels excessive... make it one line
    // int indexOfLargestValue = findLargestValueByIndex(arr, SIZE);
    // int largest = arr[ indexOfLargestValue ];
    // cout << largest << endl;
    // return largest;

    return  arr[ findIndexOfLargestValue(arr, SIZE) ];
}

/**
 * assume array is not empty
 */
int findIndexOfLargestValue( int arr[], const int SIZE )
{
    int index = 0;
    for ( int i = 0 ; i < SIZE ; i++ )
    {
        int elmt = arr[i];
        if ( elmt > arr[index] )
        {
            index = i;
        }
    }

    cout << index << endl;

    return index;
}

int findLargestValue( int arr[], const int SIZE )
{
    int largest = arr[0];  // let it be some value
    for ( int i = 0 ; i < SIZE ; i++ )
    {
        int elmt = arr[i];
        if ( elmt > largest )
        {
            largest = elmt;
        }
    }

    cout << largest << endl;

    return largest;
}

void traverse1DImproved( int arr[], const int SIZE )
{
    for ( int i = 0 ; i < SIZE ; i++ )
    {
        int elmt = arr[i];
        cout << "here I can do things with: " << elmt << endl;
    }

    return;
}

void traverse1D()
{
    int arr[8] = { 1, 1, 2, 3, 5, 8, 13, 21 };
    int arrLength = sizeof(arr)/sizeof(arr[0]);
    // just proving that 8 is fine here as well
    assert( 8 == arrLength ); 
    for ( int i = 0 ; i < arrLength ; i++ )
    {
        int elmt = arr[i];
        cout << "here I can do things with: " << elmt << endl;
    }

    return;
}


