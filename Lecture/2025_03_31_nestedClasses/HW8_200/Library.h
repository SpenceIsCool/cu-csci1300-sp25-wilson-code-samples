// Library.h
// string 	_name 	The name of the Library
// const static int 	_MAX_BOOKS 	The maximum number of books the library can hold; will be 10 for this question
// int[] 	_page_counts 	Array containing the page counts of books in the library. The size of this array is _MAX_BOOKS
// int 	_current_books 	The current number of books in the Library

#include<iostream>  // or <string>
using namespace std;

class Library {
public:
    Library();
private:
    string _name;
    const static int _MAX_BOOKS = 10;
    int _page_counts[_MAX_BOOKS];
    int _current_books;
};
