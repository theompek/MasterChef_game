/*
-----Egrasia 4 Antikeimenostrafh Programmatismou------
--Elenh Papaxristodoulou AEM:9580 epapachi@auth.gr --
--Mpekiarhs Theofanhs AEM:8200   theompek@auth.gr  --
--Maios 2018                                    --
*/

#ifndef VOTE_H_INCLUDED
#define VOTE_H_INCLUDED

#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include "Team.h"
using namespace std;

class Vote{

string voted;
string reason;

public:
Vote(){voted = ""; reason = "";}
Vote(Player voted,string reason){this->voted = voted.getName(); this->reason = reason;}
~Vote(){ cout << "Vote object is destroyed." << endl;}

void setVoted(string voted){this->voted = voted;}
void setReason(string reason){this->reason = reason;}

string getVoted(){return voted;}
string getReason(){return reason;}
void status(){
cout<<endl<<"Voted player is: "<<voted<<endl;
cout<<"The reason is: "<<reason<<endl;

}


};

#endif // VOTE_H_INCLUDED
