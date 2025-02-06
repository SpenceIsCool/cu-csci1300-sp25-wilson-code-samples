#include<iostream>
using namespace std;

// switch (x) { case y: ...; break; ...casecasecase... default
int main() {
    
    cout << "Hello" << endl;

    string foodAsString;
    cout << "Give me a letter and I'll give you food." << endl;
    cin >> foodAsString;

    if ( foodAsString.length() != 1 )
    {
        cout << "You fool! I said give me a letter not a novel!" << endl;
    }
    else
    {
        char food;
        food = foodAsString[0];
        cout << "You have selected: " << food << endl;
        food = toupper(food);

        
        cout << "Here is that ";
        switch (food)
        {
            case 'M': 
                cout << "Muffin";
                break;
            case 'B':
                cout << "Blueberry";
                break;
            default:
                cout << "off-menu item";
                break;
        }
        cout << " you ordered" << endl;
    }

    cout << "Goodbye" << endl;
}
