/*
-----Egrasia 3 Antikeimenostrafh Programmatismou------
--Elenh Papaxristodoulou AEM:9580 epapachi@auth.gr --
--Mpekiarhs Theofanhs AEM:8200   theompek@auth.gr  --
--Maios 2018                                    --
*/

#ifndef COMPETITION_H_INCLUDED
#define COMPETITION_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;

class Competition{
protected:
    int id;
	string name;
	string winner;

public:
Competition(){
	id = 0;
	name = "";
	winner = "";
	}
Competition(int id,string name){
    this->id = id ;
    this->name = name;
    this->winner = "";
}
~Competition(){cout << "To antikeimeno 'Competition' katastrafhke"<<endl;}

void setId(int id){this->id = id ;}
void setName(string name){this->name = name;}
void setWinner(string winner){this->winner = winner;}

int getId(){return id;}
string getName(){return name;}
string getWinner(){return winner;}

void status(){
    cout << "Id: " << id << endl;
	cout << "Name: " << name << endl;
	cout << "Winner: " << winner << endl;
}

};


#endif // COMPETITION_H_INCLUDED
