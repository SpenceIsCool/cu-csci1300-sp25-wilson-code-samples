#include<iostream>
using namespace std;

int main() 
{
    char food;

    cout << "What letter food did you want?" << endl;
    cin >> food;

    food = toupper(food);
    // cout << "I see you wanted the letter: " << food << endl;

    switch ( food )
    {
        case 'A':  // NOT "A"
            cout << "Apple";
            break;
        case 'K':
            cout << "Kolache";
            break;
        case 'B':
            cout << "Blueberries";
            break;
        case 'P':
            cout << "Pizza";
            break;
        case 'Z': cout << "zucchini";
            break;
        default:
            cout << "Sorry, I don't have anything that starts with a " << food << endl;
    }
    cout << endl;
}
