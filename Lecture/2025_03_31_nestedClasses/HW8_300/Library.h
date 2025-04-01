// Library.h
#include<string> // <iostream>
using namespace std;

class Library
{
public:
    Library();
private:
    string _name;
    const static int _MAX_BOOKS = 10;
    int _page_counts[_MAX_BOOKS];
    int _current_books;
};

