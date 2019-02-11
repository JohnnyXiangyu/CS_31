//
//  main.cpp
//  LetterSample
//
//  Created by Howard Stahl on 1/20/16.
//  Copyright © 2016 Howard Stahl. All rights reserved.
//

#include <iostream>
#include <string>
#include <cassert>
using namespace std;

int number( string s, int index );

int main(int argc, const char * argv[]) 
{
    string s;
    
    cout << "Feed me: ";
    getline( cin, s );
    // you can use s.size( ) to determine the length
    size_t length = s.size();
    cout << "Length = " << length << endl;
    // you can acquire the first letter by saying s[ 0 ]
    char c = s[ 0 ];
    cout << "First letter = " << c << endl;
    // you can use s[ i ] to acquire the ith character
    for ( size_t j = 0; j < s.size(); j++ )
    {
        cout << "s[ " << j << " ] = " << s[ j ] << endl;
    }
    cout << "number( s, 0 ) = " << number(s, 0 ) << endl;
    cout << "number( s, 6 ) = " << number(s, 6 ) << endl;
    // demonstrate using assertions to test code
    assert( number( "123hello", 0 ) == 123 );
    assert( number( "123hello", 1 ) == 23 );
    assert( number( "123hello", 2 ) == 3 );
    assert( number( "123hello", 3 ) == 0 );
    return 0;
}


int number( string s, int index )
{
    int result = 0;
    if ( s[ index ] >= '1' && s[ index ] <= '9' )
    {
        while ( s[index] >= '0' && s[index] <= '9' )
        {
            result = (result * 10) + (s[ index ] - '0');
            index = index + 1;
        }
    }
    return( result );
}