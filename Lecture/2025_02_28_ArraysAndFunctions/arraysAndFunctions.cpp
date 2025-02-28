#include <iostream>
using namespace std;

void printIntArray(string name, int arr[], const int COUNT);
void addOneInt(int x);
void addOneArrayOfInt(int arr[]);
void copyAndDouble(int arr[], const int COUNT, int result[]);
void randomStuff(int arr[], const int COUNT, int result[]);
void studentQuestion_addOneArrayOfInt(int arr[]);

int main()
{
    const int ROW = 10;
    const int COL = 5;  // short for "Column"
    int arr2D[ ROW ][ COL ];
    for ( int x = 0 ; x < ROW ; x++ )
    {
        for ( int y = 0 ; y < COL ; y++ )
        {
            arr2D[ x ][ y ] = x * y;
        }
    }
    
    for ( int i = 0 ; i < ROW ; i++ )
    {
        for ( int j = 0 ; j < COL ; j++ )
        {
            if ( j != 0 ) { cout << ", "; }
            cout << arr2D[i][j];
        }
        cout << endl;
    }

    int my_x = 5;
    cout << "main: " << my_x << endl;
    addOneInt(my_x); /** LINE 10 */
    cout << "main: " << my_x << endl;
    cout << "Ask yourself, why doesn't the above line print main: 6?" << endl;

    int my_arr[100] = {5};
    cout << "main: " << my_arr[0] << endl;
    addOneArrayOfInt(my_arr);
    cout << "main: " << my_arr[0] << endl;
    cout << "Ask yourself, why doesn't the above line print main: 5?" << endl;

    cout << "\n\n\nFROM A STUDENT QUESITON::" << endl;
    cout << "main: " << my_arr << endl;
    cout << "main: " << my_arr[0] << endl;
    studentQuestion_addOneArrayOfInt(my_arr);
    cout << "main: " << my_arr << endl;
    cout << "main: " << my_arr[0] << endl;
    cout << "Ask yourself, why doesn't the above line print main: 5?" << endl;
    cout << "\n\n\n" << endl;


    const int bravo = 8;
    int alpha[100] = {0, 1, 1, 2, 3, 5, 8, 13};
    int charlie[bravo];
    randomStuff(alpha, bravo, charlie);
    printIntArray("alpha", alpha, bravo);
    printIntArray("charlie", charlie, bravo);
}

/**
 * printIntArray
 *
 * a handy function to print any array for me
 * great for debugging
 *
 * @param name: of the array for formatting nicely
 * @param arr: an array to work with
 * @param COUNT: the number of element of $arr that we care to show (assume <= total length)
 */
void printIntArray(string name, int arr[], const int COUNT)
{
    cout << name << ": [ ";
    for (int i = 0; i < COUNT; i++)
    {
        if (i != 0)
        {
            cout << ", ";
        }
        cout << arr[i];
    }
    cout << "]" << endl;
}

void addOneInt(int x)
{
    x = x + 1;
    cout << "addOneInt: " << x << endl;
}

/**
 * studentQuestion_addOneArrayOfInt
 *
 * do arrays work like vectors? can we just add one to it?
 */
void studentQuestion_addOneArrayOfInt(int arr[])
{
    // WAS: arr[0] = arr[0] + 1;
    arr = arr + 1;
    // addOneArrayOfInt: 0 (seems to always be 0)
    cout << "addOneArrayOfInt: " << arr[0] << endl;
    // addOneArrayOfInt: 0x16f30f124 (will be a fairly random "memory address")
    cout << "addOneArrayOfInt: " << arr << endl;
}

// Pass by reference example:
void addOneArrayOfInt(int arr[])
{
    arr[0] = arr[0] + 1;
    cout << "addOneArrayOfInt: " << arr[0] << endl;
}

void randomStuff(int arr[], const int COUNT, int result[])
{
    for (int i = 0; i < COUNT; i++)
    {
        int elmt = arr[i];
        int newElmt = elmt * 2 + 1;
        result[i] = newElmt;
    }
    return;
}
