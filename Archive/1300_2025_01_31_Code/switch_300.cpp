#include<iostream>
using namespace std;

int main()
{
    // get users food character
    // and then give them food
    char food;
    cout << "Hey, what's the first letter of your favorite food?" << endl;
    cin >> food;

    food = tolower(food);

    // cout << "I found " << food << endl;
    switch ( food )
    {
        // use 'A', NOT "A"
        case 's':
            cout << "Spaghetti";
            break;
        case 'm':
            cout << "medium rare steak";
            break;
        case 'a':
            cout << "Apples";
            break;
        default:
            cout << "I know of no such food";
    }
    cout << endl;
}
