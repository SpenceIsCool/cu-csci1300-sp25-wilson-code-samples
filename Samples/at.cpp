/**
 * arr.at(i) should be like a safe version of arr[i]
 * let's explore
 */
#include<iostream>
using namespace std;

void fails();
void works();
void actuallyForStrings();

int main()
{
    fails();
    works();
    actuallyForStrings();



    // WORKS for STRINGS!


    return 0;
}

/**
 * doesn't work on a standard int[ ]
 */
void fails()
{
    cout << "\n\n\ndoesn't work on a standard int[ ]"
         << "\nuncomment below to see compiler error" 
         << endl;
    // const int SIZE = 5;
    // int arr[SIZE] = { 3, 6 };
    // int filled = 2;

    // // does not work on this kind of array
    // // works on std::array
    // cout << arr.at(1) << endl;
    return;
}
void works()
{
    const int SIZE = 5;
    array<int, SIZE> arr= { 3, 6 };

    // does not work on this kind of array
    // works on std::array
    cout << "\n\n\nworks on `array` type"
         << "\narray<int, 5> arr= { 3, 6 }" 
         << "\narr.at(1): " << arr.at(1)
         << endl;
}

void actuallyForStrings()
{
    string x = "hello";

    // does not work on this kind of array
    // works on std::array
    cout << "\n\n\nworks on `string` type"
         << "\nstring x = \"hello\"" 
         << "\nx.at(1): " << x.at(1)
         << endl;
}

