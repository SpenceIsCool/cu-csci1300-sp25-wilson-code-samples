#include<iostream>
#include<vector>
using namespace std;


void sampleVectorSplitting();
void sampleVectorMerging();
void showVector( vector<int> v );
vector<int> foo( vector<int> v1, vector<int> v2 );
vector<int> mergeSort( vector<int> v );


int main()
{
    sampleVectorSplitting();
    // sampleVectorMerging();
    // vector<int> v = { 5, 22, 7, 3, 15, 9, -7, -9, 12 };
    // showVector( mergeSort( v ) );
}


void sampleVectorSplitting( )
{
    cout << "sampleVectorSplitting" << endl;
    vector< int > x = { 0, 100 };
    vector< int > y = { 5, 12, 2, 18, 7, 9 };
    x.insert( x.begin() + 1, y.begin() + 2 , y.begin() + 5);
    showVector( x );
}


void sampleVectorMerging()
{
    vector<int> x = { 5, 10, 15, 20 };
    vector<int> y = { 3, 6, 9, 12, 15, 18, 21 };
    vector<int> z = foo( x, y );
    showVector( z );
}


void showVector( vector<int> v )
{
    cout << "{ ";
    for ( unsigned int i = 0 ; i < v.size( ) ; i++ )
    {
        if ( i != 0 )
        {
            cout << ", ";
        }
        cout << v.at( i );
    }
    cout << " }" << endl;
    return;
}


vector<int> foo( vector<int> v1, vector<int> v2 )
{
    vector<int> res;
    unsigned int x, y;
    x = 0;
    y = 0;
    while ( x < v1.size() && y < v2.size() )
    {
        if ( v1.at( x ) < v2.at( y ) )
        {
            res.push_back( v1.at( x ) );
            x++;
        }
        else
        {
            res.push_back( v2.at( y ) );
            y++;
        }

    }
    // consume the rest of each of them (only one will actually happen in practice
    for ( ; x < v1.size( ) ; x++ )
    {
        res.push_back( v1.at( x ) );
    }
    
    for ( ; y < v2.size( ) ; y++ )
    {
        res.push_back( v2.at( y ) );
    }

    return res;
}



vector<int> mergeSort( vector<int> v )
{
    // base case
    if ( v.size() < 2 ) return v;
    // split
    unsigned int split = v.size() / 2;
    vector<int> left, right;
    left.insert( left.begin(), v.begin(), v.begin() + split );
    right.insert( right.begin(), v.begin() + split, v.end());
    // recurse
    left = mergeSort( left );
    right = mergeSort( right );
    // merge
    return foo( left, right );
}

