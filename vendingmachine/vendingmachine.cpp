//
//  vendingmachine.cpp
//  vendingmachine
//
//  Created by Ayan Nath on 7/7/22.
//

#include <cassert>
#include <iostream>
#include <string>
using namespace std;


//helper function that checks if the string ends with a purchase
bool endWithPurchase(string vendingstring)
{
    long length = vendingstring.length();
    
    if (length<3)
        return false;
    
    if (vendingstring.at(length-3)!='P')
        return false;
    if (vendingstring.at(length-2)!='A' && vendingstring.at(length-2)!='B' && vendingstring.at(length-2)!='C')
        return false;
    if (vendingstring.at(length-1) != '0' && vendingstring.at(length-1) != '1' && vendingstring.at(length-1) != '2' && vendingstring.at(length-1) != '3' && vendingstring.at(length-1) != '4' && vendingstring.at(length-1) != '5' && vendingstring.at(length-1) != '6' && vendingstring.at(length-1) != '7' && vendingstring.at(length-1) != '8' && vendingstring.at(length-1) != '9')
        return false;
    
    return true;
}

//helper function that returns the value of how much was entered
//if there is a refund in the middle of the string, the amountEntered value resets to 0
double amountEntered(string vendingstring)
{
    double entered = 0.0;
    
    for (size_t i = 0; i < vendingstring.length(); i++)
    {
        if (vendingstring.at(i)=='$')
            entered = entered + 1.00;
        else if (vendingstring.at(i)=='q')
            entered = entered + 0.25;
        else if (vendingstring.at(i)=='d')
            entered = entered + 0.10;
        else if (vendingstring.at(i)=='n')
            entered = entered + 0.05;
        else if (vendingstring.at(i)=='p')
            entered = entered + 0.01;
        else if (vendingstring.at(i)=='R')
        {
            if (i != vendingstring.length()-1)
            {
                entered=0;
            }
                
        }
    }
    return entered;
}

//helper function that returns the value of how much you are spending
//if there is a refund in the middle of the string, the spent value resets to 0
double spent(string vendingstring)
{
    double spent = 0.0;
    
    for (size_t i = 0; i < vendingstring.length(); i++)
    {
        
        if (vendingstring.at(i)=='A')
            spent = spent + 1.00;

        if (vendingstring.at(i)=='B')
            spent = spent + 2.00;

        if (vendingstring.at(i)=='C')
            spent = spent + 3.00;
        if (vendingstring.at(i)=='R')
        {
            if (i != vendingstring.length()-1)
            {
                spent=0;
            }
        }
    }
    return spent;
}

//helper method that checks if a purchase is valid (if A, B, or C follows the letter P or M; and if
// numbers follow A B or C)
bool isValidPurchase(string vendingstring)
{
    for (size_t i = 0; i < vendingstring.length(); i++)
    {
        if (vendingstring.at(i)=='P')
        {
            if (i > vendingstring.length()-3)
                return false;
            
            if (vendingstring.at(i+1) !='A' && vendingstring.at(i+1) !='B' && vendingstring.at(i+1) !='C')
                return false;
            
            if (vendingstring.at(i+2) != '0' && vendingstring.at(i+2) != '1' && vendingstring.at(i+2) != '2' && vendingstring.at(i+2) != '3' && vendingstring.at(i+2) != '4' && vendingstring.at(i+2) != '5' && vendingstring.at(i+2) != '6' && vendingstring.at(i+2) != '7' && vendingstring.at(i+2) != '8' && vendingstring.at(i+2) != '9')
                return false;
                
        }
        
        if (vendingstring.at(i)=='A' || (vendingstring.at(i)=='B') || (vendingstring.at(i)=='C'))
        {
            if (vendingstring.at(i-1)!='P')
                return false;
        }
        
    }
     
    return true;
}


/**
 returns true if its parameter is a well-formed vending machine string as described above, or  false otherwise.
 */
bool isValidVendingMachineString(string vendingstring)
{
    if (vendingstring.length()==0)
            return false;
    
    if (vendingstring.at(0) != 'D' && vendingstring.at(0) != 'R' && vendingstring.at(0) != 'M')
        return false;
    
    if (endWithPurchase(vendingstring)==false && vendingstring.back()!='R')
        return false;
    
    if (amountEntered(vendingstring)<spent(vendingstring))
        return false;
    
    if (isValidPurchase(vendingstring)==false)
        return false;
    
    for (size_t i = 0; i < vendingstring.length(); i++)
    {
        if (vendingstring.at(i) != 'D' && vendingstring.at(i) != 'M' && vendingstring.at(i) != 'P' && vendingstring.at(i) != 'R' && vendingstring.at(i) != 'A' && vendingstring.at(i) != 'B' && vendingstring.at(i) != 'C' && vendingstring.at(i) != 'p' && vendingstring.at(i) != 'n' && vendingstring.at(i) != 'd' && vendingstring.at(i) != 'q' && vendingstring.at(i) != '$' && vendingstring.at(i) != '0' && vendingstring.at(i) != '1' && vendingstring.at(i) != '2' && vendingstring.at(i) != '3' && vendingstring.at(i) != '4' && vendingstring.at(i) != '5' && vendingstring.at(i) != '6' && vendingstring.at(i) != '7' && vendingstring.at(i) != '8' && vendingstring.at(i) != '9')
        {
            return false;
        }
        
        if (vendingstring.at(i)=='D' || vendingstring.at(i)=='M')
        {
            if (vendingstring.at(i+1)!= 'p' && vendingstring.at(i+1)!= 'n' && vendingstring.at(i+1)!= 'd' && vendingstring.at(i+1)!= 'q' && vendingstring.at(i+1)!= '$')
                return false;
        }
    }

    
    return true;
}

/**
 If the parameter is a well-formed vending machine string, this function returns the total amount of all purchases.  If the string parameter is not valid, return -1.00.
 */
double amountSpent(string vendingstring)
{
    if (isValidVendingMachineString(vendingstring)==false)
        return -1.00;
    
    return spent(vendingstring);
}


/**
 If the parameter is a well-formed vending machine string, this function returns the change left over after the string is fully processed.  If the string parameter is not valid, return -1.00.
 */
double changeReturned(string vendingstring)
{
    if (isValidVendingMachineString(vendingstring)==false)
        return -1.00;
    
    return amountEntered(vendingstring) - spent(vendingstring);
}

/**
 If the parameter is a well-formed vending machine string, this function returns the total number of item purchased after the string is fully processed.  If the string parameter is not valid, return -1
 */
int howManyItemsBought(string vendingstring)
{
    if (isValidVendingMachineString(vendingstring)==false)
        return -1.00;
    
    int items = 0;
    
    int i = 0;
    while (i < vendingstring.length())
    {
        if (vendingstring.at(i)=='A' || vendingstring.at(i)=='B' || vendingstring.at(i)=='C')
        {
            items = items +1;
            i = i + 3;
        }
        
        else i++;
    }
    
    return items;
}


bool neitherSpentMore(string s1, string s2, double howMuch)
{
    if (isValidVendingMachineString(s1) == false || isValidVendingMachineString(s2) == false)
    {
        return false;
    }
    
    if (amountSpent(s1)>= howMuch || amountSpent(s2)>= howMuch)
    {
        return false;
    }
    
    return true;
}



int main()
    {
        //string s;
        cout.setf( ios::boolalpha ); // prints bool values as "true" or "false"
//            while( true )
//            {
//                 cout << "Enter a possible vending machine string: ";
//                 getline(cin, s); if (s == "quit") break;
//                 cout << "isValidVendingMachineString returns ";
//                 cout << isValidVendingMachineString(s) << endl;
//                 cout << "amountSpent(s) returns ";
//                 cout << amountSpent(s) << endl;
//                 cout << "changeReturned(s) returns ";
//                 cout << changeReturned(s) << endl;
//                 cout << "howManyItemsBought(s) returns ";
//                 cout << howManyItemsBought(s) << endl;
//                cout << endl;
//            }
    
    cout << neitherSpentMore( "MqDqMqDqPA3", "D$M$PB3", 10.00 ) << endl;
            return( 0 );
    }
