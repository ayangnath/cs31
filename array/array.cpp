//
//  main.cpp
//  Project 4
//
//  Created by Ayan Nath on 7/20/22.
//

#include <cassert>
#include <iostream>
#include <string>
using namespace std;

int locateMaximum( const  string  array[ ],  int  n );
bool matchingValuesTogether( const string array[ ], int n );
bool hasDuplicates( const string array[ ], int  n );
string majorityElement( const string array[ ], int  n );
bool hasReverse( const string array[ ], int n );
int findLastOccurrence( const string array[ ], int n, string target );
int countFloatingPointValues( const string array[ ], int   n );
int replaceAll( string array[ ], int n, char letterToReplace, char letterToFill );


/**
 Return the index of the largest item found in the array or -1 if n <= 0.  For example, for the array folks[ 8 ] shown above, locateMaximum( folks, 8 )  should return the value 4, corresponding to the index of "tyrion".  If there are multiple duplicate maximum values, please return the smallest index that has this maximum value.  The maximum value is determined by its dictionary-sorted order which is what < and > use in C++ to determine true and false.
 */
int locateMaximum( const  string  array[ ],  int  n )
{
    if (n<=0)
        return -1;
    string maxString = array[0];
    int max = 0;
    
    for (size_t i = 0; i < n; i++)
    {
        if (array[i] > maxString)
        {
            max = (int)i;
        }
    }
    
    return max;
}

/**
 If all the duplicated values found in the array are located one right after the other, return true otherwise false.  If you don't find any duplicated values at all, then return true since you never found any values violating this together-ness principle.  If n <=0, return false.  For example, for the array people[ 5 ] shown above, matchingValuesTogether( people, 5 ) should return true.  For the array folks[ 8 ],  matchingValuesTogether( folks, 8 ) should return false because the two "jon" values are not located in the array in contiguously located elements, one right after the other.
 */
bool matchingValuesTogether( const string array[ ], int n )
{
    if (n<=0)
        return false;
    
    if (hasDuplicates(array,n) == false)
        return true;
    
    for(size_t i = 0; i < n-1; i++)
    {
        for(size_t j = i+2; j <= n; j++)
        {
            if (array[i]==array[j] && array[j] != array[j-1])
            {
                //cout << array[i] << " " << array[j];
                return false;
            }
        }
    }
    
    return true;
}

/**
 If there is a value that is repeatedly found in the array, return true otherwise false or if n <= 0 return false. For example, for the array people[ 5 ] shown above,  hasDuplicates( people, 5 ) should return false. For the array people[ 5 ] shown above, hasDuplicates( people, 0 ) should return false because the empty array indeed has no duplicates either. For the array folks[ 8 ] shown above, hasDuplicates( folks, 8 ) should return true.
 */
bool hasDuplicates( const string array[ ], int  n )
{
    if (n<=0)
        return false;
    
    for (size_t i = 1; i < n; i ++)
    {
        for (size_t j = 0; j< i; j++)
        {
            if (array[i]==array[j])
                return true;
        }
    }
    
    return false;
}

/**
 For all the elements in the passed array, identify and return the element that occurs more than n/2 times in the array or return the empty string "" otherwise.   For example, for the array   folks[ 8 ]  shown above, majorityElement( folks, 8 ) should return the empty string since there is no value that occurs five or more times.  For example, for the array data[ 5 ] shown above, majorityElement( data, 5 ) should return "mama" since it occurs three times.
 */
string majorityElement( const string array[ ], int  n )
{
    if (n<=0)
        return "";
    
    int max = 0;
    int index = 0;
    for (size_t i = 0; i < n; i ++)
    {
        int count = 0;
        for (size_t j = 0; j < n; j++)
        {
            if (array[i]==array[j])
                count++;
        }
        
        if (count > max)
        {
            max = count;
            index = (int)i;
        }
    }
    
    if (max > n/2)
        return array[index];
    
    else return "";
}



//helper function that reverses a string
string reverse(string s)
{
    int length = (int)s.length();
    int j = length -1;
    int i = 0;
    
    while (i <= j)
    {
        swap(s[i],s[j]);
        j = j-1;
        i = i+1;
    }
    
    return s;
}


/**
 If there is an element in the passed array whose value is the reverse of an existing value found in the array, return true otherwise false or if n <= 0 return false .  For example, for the array people[ 5 ] shown above, hasReverse( people, 5 ) should return false.  For example, for the array folks[ 8 ] shown above, hasReverse( folks, 8 )should return true  because "samwell" and its reverse "llewmas" are in the array as well as "jon" and "noj".
 */
bool hasReverse( const string array[ ], int n )
{
    if (n<=0)
        return false;
    
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = i+1; j < n; j++)
        {
            if (array[i]==reverse(array[j]))
                return true;
        }

    }
    
    
    return false;
}

/**
 Return the largest index that holds the target value in the array or -1 if it is not found at all or n <= 0.  For example, for the array     data[ 5 ] shown above,   findLastOccurrence( data, 5, "mama" ) should return the value 4 while findLastOccurrence( data, 5, "howard" ) should return -1.
 */
int findLastOccurrence( const string array[ ], int n, string target )
{
    if (n<=0)
        return -1;
    
    int index = -1;
    
    for (size_t i =0; i < n; i++)
    {
        if (array[i]==target)
            index = (int)i;
    }
    
    return index;
}

//helper method for isFloatingPoint
bool hasOnlyDigits(string s)
{
    for (size_t i =0 ; i < s.length(); i++)
    {
        if (s.at(i)!='0'&& s.at(i)!='1' && s.at(i)!='2' && s.at(i)!='3' && s.at(i)!='4' && s.at(i)!='5' && s.at(i)!='6' && s.at(i)!='7' && s.at(i)!='8' && s.at(i)!='9' && s.at(i)!='.' && s.at(i)!='+' && s.at(i)!= '-')
            return false;
    }
    return true;
}

bool isFloatingPoint(string s)
{
    if (hasOnlyDigits(s)==false)
        return false;
    
    int decimalCount=0;
    int plusCount=0;
    int minusCount=0;
    for (size_t i =0 ; i < s.length(); i++)
    {
        if (s.at(i)=='.')
            decimalCount++;
        
        if (s.at(i)=='+')
            plusCount++;
        
        if (s.at(i)=='-')
            minusCount++;
    }
    
    if (decimalCount>1)
        return false;
    
    if (plusCount>1)
        return false;
    
    if (minusCount>1)
        return false;
    
    if (plusCount==1 && s.at(0)!='+')
        return false;
    
    if (minusCount==1 && s.at(0)!='-')
        return false;
    
    return true;
}

/**
 Return the total number of floating-point values found in all the array elements of the passed array argument.  For the purpose of this function, a floating-point value should have the form #.#, where # is one of the digits 0-9.  The decimal point is optional but should only be found once for the element to count as a valid floating-point value.  Additionally, the number may contain a single leading + or - sign which is optional.  Return -1 if n <= 0.  For example, for the array     string data[ 4 ] = { "4.4.3.3", "+44", "-33.098", "33.098a" };    countFloatingPointValues( data, 4 ) should return the value 2 while countFloatingPointValues( data, -14 ) should return -1.  According to this specification, all of the following are valid floatingPointValues:  "1.0", "+1", ".0101", "0.0123", "-12".
 */
int countFloatingPointValues( const string array[ ], int   n )
{
    if (n<=0)
        return -1;
    
    int count = 0;
    
    for (size_t i = 0; i < n; i ++)
    {
        if (isFloatingPoint(array[i]) == true)
            count++;
    }
            
    return count;
}

/**
 For the passed array, replace all occurrences in each element of the character  charToReplace with letterToFill, returning the total number of times the letterToReplace character was replaced by this call or return -1 if n <=0.  For example, for the array folks[ 8 ] shown above, replaceAll( folks, 8, 'A', 'Z' ) should return 0 since there are no 'A's in any of the elements.  replaceAll( folks, -10, 'A', 'Z' ) should return -1.  replaceAll( folks, 8, 'a', 'Z' ) should return 5 and adjust the array folks to {  "sZmwell", "jon", "mZrgZery", "dZenerys",  "tyrion", "jon", "llewmZs", "noj" }
 */
int replaceAll( string array[ ], int n, char letterToReplace, char letterToFill )
{
    if (n<=0)
        return -1;
    
    int count = 0;
    
    for (size_t i = 0; i < n; i ++)
    {
        for (size_t j = 0; j < array[i].length(); j++)
        {
            if (array[i].at(j)==letterToReplace)
            {
                count ++;
                array[i].at(j)=letterToFill;
            }
                
        }

    }
    return count;
}


int main(int argc, const char * argv[]) {
    string people[5] = { "howard", "pixie", "barak", "joe", "donald" };
    string folks[8] = {  "samwell", "jon", "margaery", "daenerys",
                              "tyrion", "jon", "llewmas", "noj" };
    string data[5] = { "mama", "mama", "12,", "sansa", "mama" };
    string dee[5] = { "mama", "mama", "mama", "mama", "mama" };
    string data2[ 4 ] = { "4.4.3.3", "+44", "-33.098", "33.098a" };
    string v[5] = {"1", "3", "2", "2", "3"};
    string zz[4] = {"a", "", "b", ""};
    
    string yy[5] = {"A", "A" ,"B", "B", "C"};
        string xx[5] = {"A", "A", "B", "A", "A"};
        string ww[9] = {"A", "A", "C", "B", "B", "T", "D", "D", "D"};
    
    cout.setf( ios::boolalpha );
    
    cout << locateMaximum( folks, 8 ) << endl; // 4
    cout << matchingValuesTogether( people, 5 ) << endl; // true
    cout << matchingValuesTogether( folks, 8 ) << endl; // false
    cout << hasDuplicates( people, 5 ) << endl; // false
    cout << hasDuplicates( people, 0 ) << endl;// false
    cout << hasDuplicates( folks, 8 ) << endl;// true
    cout << majorityElement( folks, 8 ) << endl;// ""
    cout << majorityElement( data, 5 ) << endl;// "mama"
    cout << hasReverse( people, 5 ) << endl;// false
    cout << hasReverse( folks, 8 ) << endl;// true
    cout <<  findLastOccurrence( data, 5, "mama" ) << endl; // 4
    cout << findLastOccurrence( data, 5, "howard" ) << endl; // -1
    cout << countFloatingPointValues( data2, 4) << endl; // 2
    cout <<countFloatingPointValues( data2, -14) << endl; // -1
    cout << replaceAll( folks, 8, 'A', 'Z' ) << endl; // 0
    cout << replaceAll( folks, -10, 'A', 'Z' ) << endl; // -1
    cout << replaceAll( folks, 8, 'a', 'Z' ) << endl; // 5
    
    
    //cout << folks[7] << endl;
}
