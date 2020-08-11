/*
-----Egrasia 3 Antikeimenostrafh Programmatismou------
--Elenh Papaxristodoulou AEM:9580 epapachi@auth.gr --
--Mpekiarhs Theofanhs AEM:8200   theompek@auth.gr  --
--Maios 2018                                    --
*/

#ifndef CREATIVITYCOMPETITION_H_INCLUDED
#define CREATIVITYCOMPETITION_H_INCLUDED

#include <iostream>
#include "Competition.h"
#include "ExcursionAward.h"
#include "Team.h"
#include "Round.h"
using namespace std;

class CreativityCompetition : public Competition{

ExcursionAward excursionAward;
string *ingredients;

public:
CreativityCompetition();
CreativityCompetition(int id,string name,ExcursionAward excursionAward);
~CreativityCompetition();



void setExcursionAward (ExcursionAward excursionAward);
void setIngredients(string ingredients,int index);
void setIngredients(string *ingredients);

ExcursionAward getExcursionAward();
string getIngredients(int index);
void status();
void compete(Team &team1,Team &team2);
};

#endif // CREATIVITYCOMPETITION_H_INCLUDED
