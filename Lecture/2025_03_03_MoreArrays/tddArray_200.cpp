/**
 * tddArray.cpp
 * 
 * @author Spencer Wilson
 * @date 2025 March 03
 * 
 * A test driven development (TDD) approach to problems invloving arrays
 */


#include<iostream>  // cout
#include<cassert>  // assert (for TDD)
using namespace std;


// implemented for us: read later
// ASSUME these work well
void printIntArray(string name, double arr[], int used);
void printDoubleArray(string name, double arr[], int used);
void testGetProd1D();
double getProd1D( double arr[ ], int used );
// // OPTIONAL: try these yourself if interested (quick and painless)
// void testSum1D();
// double getSum1D( double arr[ ], int used );
// void testAvg1D();
// double getAvg1D( double arr[ ], int used );
void testGetIndexOfLargestValue( );
int getIndexOfLargestValue( int arr[], int used );
void testIsEquivalentIntArr( );
bool isEquivalentIntArr( int arr1[], int arr2[], int used );

// LIVE
void testRemoveLargest( );
int removeLargest( int arr[] , int used );


int main()
{
    testGetProd1D();
    testGetIndexOfLargestValue();
    testIsEquivalentIntArr();
    testRemoveLargest();
    return 0;
}


/**
 * printDoubleArray
 *
 * a handy function to print any array for me
 * great for debugging
 *
 * @param name: of the array for formatting nicely
 * @param arr: an array to work with
 * @param used: the number of element of $arr that we care to show (assume <= total length)
 */
void printDoubleArray( string name, double arr[], int used )
{
    cout << name << ": [ ";
    for (int i = 0; i < used; i++)
    {
        if (i != 0)
        {
            cout << ", ";
        }
        cout << arr[i];
    }
    cout << " ]" << endl;
}


/**
 * printIntArray
 *
 * a handy function to print any array for me
 * great for debugging
 *
 * @param name: of the array for formatting nicely
 * @param arr: an array to work with
 * @param used: the number of element of $arr that we care to show (assume <= total length)
 */
void printIntArray( string name, int arr[], int used )
{
    cout << name << ": [ ";
    for (int i = 0; i < used; i++)
    {
        if (i != 0)
        {
            cout << ", ";
        }
        cout << arr[i];
    }
    cout << " ]" << endl;
}


/**
 * testProd
 * validate the getProd1D function
 */
void testGetProd1D()
{
    cout << endl << endl << "BEGIN: testProd" << endl;
    double myArr[4] = { 2, 5, 10, 0.5 };
    cout << "testing product of sub-arrays of: " << endl;
    printDoubleArray( "myArr", myArr, 4 );
    assert( 50 == getProd1D( myArr, 4 ) );

    // cheating a bit, but we can also use smaller used values
    assert( 100 == getProd1D( myArr, 3 ) );
    assert( 10 == getProd1D( myArr, 2 ) );
    // perhaps controversial, return the value if it's the only value
    assert( 2 == getProd1D( myArr, 1 ) );

    // OPTIONAL: nice to have a print out to see that the tests passed
    // The above asserts will end all execution with an error if they are not true
    cout << "ALL TESTS PASSED: testProd" << endl;
}


/**
 * getProd1D
 * find the product of the used elements in an array
 * e.g. arr = { 5, 10, 2 }, return 100
 * 
 * @param arr: the array of interest, ASSUME it's non-empty
 * @param used: the count of elements to observe, ASSUME it's positive and less than the arr capacity
 * @returns: the product of the observed values
 */
double getProd1D( double arr[ ], int used )
{
    // // this is valid
    // double prodSoFar = arr[0];
    // for ( int i = 1 ; i < used ; i++ )
    // {
    //     double elmt = arr[i];
    //     prodSoFar *= elmt;
    // }
    // return prodSoFar;

    // let's make it tighter
    // don't need an elmt value
    // since the `for` does exactly one thing we don't need { }
    double prodSoFar = arr[0];
    for ( int i = 1 ; i < used ; i++ )
        prodSoFar *= arr[i];
    return prodSoFar;
}


/**
 * testGetIndexOfLargestValue
 * validate the getIndexOfLargestValue function
 */
void testGetIndexOfLargestValue( )
{
    cout << endl << endl << "BEGIN: testGetIndexOfLargestValue" << endl;
    int myArr[6] = { 2, 5, 10, 1300, 18, 7 };
    assert( 3 == getIndexOfLargestValue( myArr, 6 ) );  // 1300 at index 3

    // cheating a bit, but we can also use smaller used values
    assert( 2 == getIndexOfLargestValue( myArr, 3 ) );  // {2,5,10} 10 at index 2

    // OPTIONAL: nice to have a print out to see that the tests passed
    // The above asserts will end all execution with an error if they are not true
    cout << "ALL TESTS PASSED: testGetIndexOfLargestValue" << endl;
}


/**
 * getIndexOfLargestValue
 * find the index of the largest value in the used section of the array
 * 
 * @param arr: the array of interest, ASSUME it's not empty
 * @param used: the number of elements to consider, ASSUME it's >0 and <total capacity of array
 * @returns: the index of the largest value in $arr
 */
int getIndexOfLargestValue( int arr[], int used )
{
    int indexOfLargestSoFar = 0;
    for ( int i = 0 ; i < used ; i++ )
    {
        // don't need these variables, can write it tighter if you want...
        int elmt = arr[i];
        int largest = arr[indexOfLargestSoFar];
        if ( elmt > largest )
        {
            indexOfLargestSoFar = i;
        }
    }
    // return indexOfLargestSoFar;
    // the following just reads nicer sometimes
    int result = indexOfLargestSoFar;
    return result;
}


/**
 * testIsEquivalentIntArr
 * validate the isEquivalentIntArr function
 */
void testIsEquivalentIntArr( )
{
    cout << endl << endl << "BEGIN: testIsEquivalentIntArr" << endl;

    int arr1[6] = { 2, 5, 10, 1300, 18, 7 };
    int arr2[1000] = { 2, 5, 10, 1300, 18, 7 };
    assert( isEquivalentIntArr( arr1, arr2, 6 ) );
    assert( isEquivalentIntArr( arr1, arr2, 5 ) );
    assert( isEquivalentIntArr( arr1, arr2, 2 ) );

    int arr3[5] = { 2270, 2400 };
    // NOTE use of `!`
    assert( ! isEquivalentIntArr( arr1, arr3, 6 ) );

    cout << "ALL TESTS PASSED: testIsEquivalentIntArr" << endl;
    return;
}

/**
 * isEquivalentIntArr
 * determine if two arrays hold equivalent values in the same order
 * 
 * @param arr1: the first array of interest
 * @param arr2: the comparing array
 * @param used: the length to compare, ASSUME it is within the capacity of each array
 * @returns: true if arr1 == arr2, else false
 */
bool isEquivalentIntArr( int arr1[], int arr2[], int used )
{
    // // NOTE: there are many other valid solutions to this problem
    // //       could return early rather than setting a value and breaking the loop
    // //       could do some nice things with equivalence
    // bool allTheSameSoFar = true;
    // for ( int i = 0 ; i < used ; i++ )
    // {
    //     int n1 = arr1[i];
    //     int n2 = arr2[i];
    //     if ( n1 != n2 )
    //     {
    //         allTheSameSoFar = false;
    //         break;  // OPTIONAL: end the loop right now, see comment about "HERE"
    //     }
    // }
    // // HERE: break would take us HERE
    // return allTheSameSoFar;

    // SAMPLE: tighter code, ask on EdStem/Ed/DiscussionForum if you want to know more
    bool res = true;
    for ( int i = 0 ; res && i < used ; i++ )
        res = res && arr1[i] == arr2[i];
    return res;
}















// LIVE
/**
 * testRemoveLargest
 * validate the removeLargest function
 */
void testRemoveLargest( )
{
    cout << endl << endl << "BEGIN: testRemoveLargest" << endl;
    // int arr1[6] = { 2, 5, 10, 1300, 18, 7 };
    // LIVE: expected next array and asertions possible.
    // assert(false) to trigger an error and know that we have more to do
    assert( false );
    cout << "ALL TESTS PASSED: testRemoveLargest" << endl;
    return;
}


/**
 * removeLargest
 * remove the largest value of the array
 * shift remaining elements left, return the new used value
 * 
 * e.g. { 5, 1300, 7 } becomes { 5, 7 }
 *      THINK find the index of the largest value
 *      THEN shift remaining values to the left
 * 
 * NOTE: returns the new used value
 * NOTE: changes the arr using pass-by-reference
 * 
 * @param arr: the array of interst, MODIFIED in function
 * @param used: the length from the left that we care about, ASSUME within capacity of $arr
 * @returns: the new used value
 */
int removeLargest( int arr[] , int used )
{
    // LIVE: how do we do this? psudo code first
    return -1;
}


