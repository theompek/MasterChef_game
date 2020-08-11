/*
-----Egrasia 3 Antikeimenostrafh Programmatismou------
--Elenh Papaxristodoulou AEM:9580 epapachi@auth.gr --
--Mpekiarhs Theofanhs AEM:8200   theompek@auth.gr  --
--Maios 2018                                    --
*/

#include "ImmunityCompetition.h"
using namespace std;


ImmunityCompetition::ImmunityCompetition(){
immunityAward = *new ImmunityAward();
}

ImmunityCompetition::ImmunityCompetition(int id,string name,ImmunityAward immunityAward) : Competition(id,name){
this->immunityAward = immunityAward;
}

ImmunityCompetition::~ImmunityCompetition(){cout << "To antikeimeno 'ImmunityCompetition' katastrafhke"<<endl;}

void ImmunityCompetition::setImmunityAward(ImmunityAward immunityAward){this->immunityAward = immunityAward;}

ImmunityAward ImmunityCompetition::getImmunityAward(){return immunityAward;}

void ImmunityCompetition::status(){
cout<<"Competition status:"<<endl;
Competition::status();
cout<<endl<<"ImmunityAward status:"<<endl;
immunityAward.status();
}

void ImmunityCompetition::compete(Team &team){
Player *players = team.getPlayers();
float technique = -1;
float notFatigue = -1;
float combination = -1;
float maxCombination = -1;
int winnerIndex = 0;
for(int i=0;i<11;i++){
 if(players[i].getAge()!=0){//An o paikths uparxei
  technique = players[i].getTechnique();
  notFatigue = 100 - players[i].getFatigue();
  combination =  technique*0.75 + notFatigue*0.25;
  if(maxCombination < combination){maxCombination = combination; winnerIndex = i; }
 }
}
Round round(1,10800,players[winnerIndex].getName());//10800 sec = 3 hours
//Telos o nikhths au3anei tis nikes tou kata mia
players[winnerIndex].setWins(players[winnerIndex].getWins()+1);
setWinner(players[winnerIndex].getName()); //ImmunityCompetition winner

}

