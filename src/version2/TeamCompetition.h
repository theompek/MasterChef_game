/*
-----Egrasia 3 Antikeimenostrafh Programmatismou------
--Elenh Papaxristodoulou AEM:9580 epapachi@auth.gr --
--Mpekiarhs Theofanhs AEM:8200   theompek@auth.gr  --
--Maios 2018                                    --
*/

#ifndef TEAMCOMPETITION_H_INCLUDED
#define TEAMCOMPETITION_H_INCLUDED
#include <stdlib.h>     /* srand, rand */
#include <iostream>
#include "Competition.h"
#include "FoodAward.h"
#include "Round.h"
#include "Team.h"

using namespace std;

class TeamCompetition : public Competition{

FoodAward foodAward;
Round *rounds;

public:

TeamCompetition();
TeamCompetition(int id,string name,FoodAward foodAward);
~TeamCompetition();

void setFoodAwards(FoodAward foodAward);
void setRounds(Round *rounds);
void setRounds(Round rounds,int index);

FoodAward getFoodAwards();
Round getRounds(int index);

void status();
int compete(Team &team1,Team &team2);
};


#endif // TEAMCOMPETITION_H_INCLUDED

