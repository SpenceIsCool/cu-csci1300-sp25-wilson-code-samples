/**
 * sorting.cpp
 * 
 * a place to try various sorting alrogithms
 * if implementing a sorting algorithm for an assignment,
 *    you should implement it yourself
 *    and not copy from here
 */
#include<iostream>
#include<fstream>
using namespace std;


struct Book 
{
    string title;
    string author;
};

vector<Book> readFromFile( string filename );
std::ostream& operator<<(std::ostream& os, const Book& b);
void showBooks( vector<Book> books );
vector<Book> bubbleSort( vector<Book> books );
vector<Book> selectionSort( vector<Book> books );
// TODO: try it yourself
// vector<Book> insertionSort( vector<Book> books );
vector<Book> quickSort( vector<Book> books );
vector<Book> mergeSort( vector<Book> books );
void writeToFile( vector<Book> books, string fileName );



int main()
{
    // // some random books off the internet, intentionally unsorted
    // vector<Book> booksUnsorted;
    // booksUnsorted.push_back( { "Pride and Prejudice", "Jane Austen"} );
    // booksUnsorted.push_back( { "The Great Gatsby", "F. Scott Fitzgerald"} );
    // booksUnsorted.push_back( { "Romeo and Juliet", "William Shakespeare"} );
    // booksUnsorted.push_back( { "Oliver Twist", "Charles Dickens"} );
    // booksUnsorted.push_back( { "A Farewell to Arms", "Ernest Hemingway"} );
    // booksUnsorted.push_back( { "A Tale of Two Cities", "Charles Dickens"} );
    // booksUnsorted.push_back( { "Hamlet", "William Shakespeare"} );
    // booksUnsorted.push_back( { "The Old Man and the Sea", "Ernest Hemingway"} );
    vector<Book> booksUnsorted = readFromFile( "unsortedBooks.txt" );


    cout << "STARTING LIST:" << endl;
    showBooks( booksUnsorted );

    vector<Book> booksSortedByBubbles = bubbleSort( booksUnsorted );
    cout << "FULL BUBBLE SORT:" << endl;
    showBooks( booksSortedByBubbles );

    vector<Book> booksSortedBySelection = selectionSort( booksUnsorted );
    cout << "FULL SELECTION SORT:" << endl;
    showBooks( booksSortedBySelection );

    vector<Book> booksSortedByQuickSort = quickSort( booksUnsorted );
    cout << "FULL QUICK SORT:" << endl;
    showBooks( booksSortedByQuickSort );

    vector<Book> booksSortedByMergeSort = mergeSort( booksUnsorted );
    cout << "FULL MERGE SORT:" << endl;
    showBooks( booksSortedByMergeSort );

    writeToFile( booksSortedByQuickSort, "sortedBooks.txt" );

    return 0;
}


/**
 * readFromFile
 */
vector<Book> readFromFile( string filename )
{
    vector<Book> res;
    ifstream f( filename );
    if ( f.is_open() )
    {
        while ( ! f.eof() )
        {
            // author: title
            Book book;
            getline( f, book.author, ':' );
            f.ignore( 1 ); // remove the space
            getline( f, book.title );
            if ( book.author != "" && book.title != "" )
            {
                res.push_back( book );
            }
        }
    }
    else
    {
        cout << "XXXXX something went wrong in setup, issue with file " << filename << endl;
    }
    return res;
}


/**
 * operator<<
 * can overload to have pretier printing of book instances
 */
std::ostream& operator<<(std::ostream& os, const Book& b) 
{
    os << b.author << ": " << b.title;
    return os;
}


/**
 * showBooks
 */
void showBooks( vector<Book> books )
{
    for ( size_t i = 0 ; i < books.size() ; i++ )
    {
        cout << "    " << i + 1 << ". " << books.at(i) << endl;
    }
    return;
}


/**
 * bubbleSort
 * Bubble Sort is generally considered the simplest sorting algorithm. 
 * It works by repeatedly swapping the adjacent elements if they are in the wrong order,
 * only comparing two at a time.
 * 
 * sort by author name, if same author, sort by title
 * all decending order ( Z at end )
 * bubble up
 * 
 * @param books: an unsorted vector of books
 * @returns: sorted vector of book objects
 */
vector<Book> bubbleSort( vector<Book> books )
{
    size_t count = books.size( );
    bool swapOccured, debug;
    swapOccured = true;
    debug = false;
    for (size_t i = 0; swapOccured && i < count - 1; i++)
    {
        swapOccured = false;
        if ( debug ) cout << "BUBBLE STAGE " << i << ":" << endl;
        for (size_t j = 0; j < count - 1 ; j++)
        {
            Book bubble = books.at( j );
            Book next = books.at( j + 1 );
            if ( bubble.author > next.author 
                 || ( bubble.author == next.author && bubble.title > next.title ) )
            {
                if ( debug ) cout << "  > bubble up: " << bubble << " past " << next << endl;
                books[ j ] = next;
                books[ j + 1 ] = bubble;
                swapOccured = true;
            }
        }
    }
    return books;
}


/**
 * selectionSort
 * Selection Sort involves picking the smallest (or largest)
 *  number out of the unsorted elements and then putting it in its own list, 
 * one after the other, so that you find the smallest, then the second smallest, 
 * and so on and so forth.
 * 
 * here, find smallest
 * 
 * assumes list is not empty
 */
vector<Book> selectionSort( vector<Book> books )
{
    bool debug = false;

    size_t sortedCount, indexSmallestUnsorted, count;
    sortedCount = 0;
    indexSmallestUnsorted = 0;
    count = books.size( );
    for (size_t times = 0 ; times < count ; times++)
    {
        if ( debug ) cout << "SELECTION ITERATION: " << times << endl;
        // find the smallest value's index
        for (size_t i = sortedCount + 1 ; i < count ; i++)
        {
            Book cur = books.at( i );
            Book smallest = books.at( indexSmallestUnsorted );
            if ( cur.author < smallest.author 
                || ( cur.author == smallest.author && cur.title < smallest.title ) )
            {
                indexSmallestUnsorted = i;
            }
        }

        // swap values if different
        Book smallest = books.at( indexSmallestUnsorted );
        Book swap = books.at( sortedCount );
        if ( smallest.author != swap.author || smallest.title != swap.title )
        {
            if ( debug ) cout << "  > smallest value " << smallest << endl
                            << "    swapping with " << swap << endl;
            books[ sortedCount ] = smallest;
            books[ indexSmallestUnsorted ] = swap;
        }
        else
        {
            if ( debug ) cout << "  > smallest value " << smallest << " is already in the correct location" << endl;
        }

        // update for next iteration
        sortedCount++;
        indexSmallestUnsorted = sortedCount;
    }
    
    return books;
}


/**
 * quickSort
 * 
 * Quick Sort is a little more complex, but it is faster than the previous algorithms,
 *  hence the name. Quick sort works by splitting our list around a randomly chosen 
 * “pivot” into two smaller lists for us to sort, where one list is smaller than the
 *  pivot and the other list is larger than the pivot. We then split those smaller
 * lists around their own pivots again, resulting in four lists. This continues 
 * until we run out of elements in our lists.
 * 
 * NOTE: slow if the list is in perfect reverse order
 */
vector<Book> quickSort( vector<Book> books )
{
    bool debug = false;

    // BASE CASE: if the list is empty or length 1, it is sorted.
    size_t pivotIndex = books.size();
    if ( pivotIndex <= 1 )
    {
        return books;
    }

    // INDUCTIVE CASE
    // select pivot
    Book pivotValue = books.at( pivotIndex - 1 );
    if ( debug ) cout << "pivoting on " << pivotValue << endl;

    // split rest of list left and right
    vector<Book> left, right;
    for (size_t i = 0 ; i < pivotIndex - 1 ; i++)
    {
        Book cur = books.at( i );
        if ( cur.author < pivotValue.author 
             || ( cur.author == pivotValue.author && cur.title < pivotValue.title ) )
        {
            if ( debug ) cout << "   < smaller " << cur << endl;
            left.push_back( cur );
        }
        else
        {
            if ( debug ) cout << "   > larger " << cur << endl;
            right.push_back( cur );
        }
    }
    
    // sort each sublist
    left = quickSort( left );
    right = quickSort( right );

    // merge them back
    if ( debug )
    {
        cout << endl << endl << endl << ":::: merging" << endl
             << "LEFT:" << endl;
        showBooks( left );
        cout << "PIVOT: " << pivotValue << endl
             << "RIGHT:" << endl;
        showBooks( right );
    }
    // left +: pivotValue +: right
    vector<Book> result;
    // insert all of left at the end
    result.insert( result.end(), left.begin(), left.end() );
    result.push_back( pivotValue );
    // insert all of right at the end
    result.insert( result.end(), right.begin(), right.end() );
    if ( debug )
    {
        cout << "RESULT:" << endl;
        showBooks( result );
        cout << endl << endl;
    }

    // don't forget to return the values
    return result;
}


/**
 * mergeSort
 */
vector<Book> mergeSort( vector<Book> books )
{
    bool debug = false;
    
    // BASE CASE
    size_t size = books.size();
    if ( size <= 1 ) 
    {
        if ( debug )
        {
            cout << "------- base case" << endl;
            showBooks( books );
        }
        return books;
    }

    // RECURSIVE CASE
    // split roughly in half
    size_t splitPoint = size/2;
    vector<Book> v1, v2;
    v1.insert( v1.begin(), books.begin(), books.begin() + splitPoint );
    v2.insert( v2.begin(), books.begin() + splitPoint, books.end() );
    if ( debug ) cout << "<<<< split at " << books.at( splitPoint ) << endl;

    // repeate the full process (recursion)
    v1 = mergeSort( v1 );
    v2 = mergeSort( v2 );
    if ( debug ) cout << ">>> the partials are sorted" << endl;

    // merge them back together
    vector<Book> result;
    size_t v1Index, v2Index;
    v1Index = 0;
    v2Index = 0;
    for ( size_t i = 0 ; i < max( v1.size(), v2.size() ) ; i++ )
    {
        if ( v1Index == v1.size() || v2Index == v2.size() ) break;
        Book v1Value = v1.at( v1Index );
        Book v2Value = v2.at( v2Index );
        if ( debug ) cout << "<?> COMPARING" << v1Value << " ??? " << v2Value << endl;

        if ( v1Value.author < v2Value.author 
             || ( v1Value.author == v2Value.author && v1Value.title < v2Value.title ) )
        {
            result.push_back( v1Value );
            v1Index++;
        }
        else
        {
            result.push_back( v2Value );
            v2Index++;
        }
    }
    // if ( v1Index < v1.size() )
    for (; v1Index < v1.size(); v1Index++)
    {
        result.push_back( v1.at( v1Index ) );
    }
    // else if ( v2Index >= v2.size() )
    for (; v2Index < v2.size(); v2Index++)
    {
        result.push_back( v2.at( v2Index ) );
    }

    return result;
}


/**
 * writeToFile
 */
void writeToFile( vector<Book> books, string fileName )
{
    ofstream f( fileName );
    if ( f.is_open() )
    {
        for (size_t i = 0; i < books.size(); i++)
        {
            // again, use of overloaded `operator<<`
            f << books.at( i ) << endl;
        }
        f.close();
    }
}

