//
//  main.cpp
//  gymplan
//
//  Created by Ayan Nath on 6/28/22.
//

#include <iostream>
#include <string>
using namespace std;


int main(int argc, const char * argv[]) {
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    
    
    cout << "What kind of gym membership plan do you want to buy? ";
    string plan;
    getline(cin, plan);
    
    cout << "What type of gym membership do you want to buy? ";
    string membership;
    getline(cin, membership);
    
    cout << "Which days do you want to workout? ";
    string days;
    getline(cin, days);
    
    cout << "Which facilities do you want to access to? ";
    string facilities;
    getline(cin, facilities);
    
    cout << "Are you on autopay? ";
    string autopay;
    getline(cin, autopay);
    
    cout << "Are you on paperless billing? ";
    string paperlessBilling;
    getline(cin, paperlessBilling);
    
    /**
     cout << "\nplan: " + plan << endl;
     cout << "membership: " + membership << endl;
     cout << "days: " + days << endl;
     cout << "facilities: " + facilities << endl;
     cout << "autopay: " + autopay << endl;
     cout << "paperlessBilling: " + paperlessBilling << endl;
     */
    
    double cost = 0;
    
    if (plan != "Executive" && plan!= "Basic")
    {
        cout << "Your kind of membership plan is not valid!" << endl;
        return(0);
    }
    if (membership != "Adult" && membership!= "Child" && membership!="Senior")
    {
        cout << "Your type of membership is not valid!" << endl;
        return(0);
    }
    if (days != "Odd" && days!= "Even" && days!= "Everyday")
    {
        cout << "Your membership days are not valid!" << endl;
        return(0);
    }
    if (facilities != "Just One" && facilities!= "Regional" && facilities!= "National")
    {
        cout << "Your facilities choice is not valid!" << endl;
        return(0);
    }
    if (autopay != "Yes" && autopay!= "No")
    {
        cout << "Your autopay is not valid!" << endl;
        return(0);
    }
    if (paperlessBilling != "Yes" && paperlessBilling!= "No")
    {
        cout << "Your paperless billing is not valid!" << endl;
        return(0);
    }
    
    
    //Checking conditions for the kind of gym membership plan

    if (plan == "Executive")
    {
        cost += 100.00;
    }
    if (plan == "Basic")
    {
        cost += 50.00;
    }
    
    
    //Checking the extra cost for everyday access
    if (days=="Everyday")
        cost+=25.00;
    
    //Checking the extra cost for extra facilities
    if (facilities=="Regional")
        cost+=30.00;
    
    if (facilities=="National")
        cost+=50.00;
    
    
    
    //Checking conditions for the type of gym membership plan
    if (membership=="Child")
        cost = 0.5*cost;
    
    if (membership=="Senior")
        cost = 0.75*cost;
    
    
    //Checking autopay
    if (autopay=="Yes")
        cost = cost -2.00;
    
    //Checking paperless billing
    if (paperlessBilling=="Yes")
        cost = cost -3.00;

    
    //string costString = to_string(cost);
    cout << "Your " << plan << " gym membership costs $" << cost <<endl;
    return (0);
}
