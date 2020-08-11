/*
-----Egrasia 3 Antikeimenostrafh Programmatismou------
--Elenh Papaxristodoulou AEM:9580 epapachi@auth.gr --
--Mpekiarhs Theofanhs AEM:8200   theompek@auth.gr  --
--Maios 2018                                    --
*/

#ifndef IMMUNITYCOMPETITION_H_INCLUDED
#define IMMUNITYCOMPETITION_H_INCLUDED
#include <iostream>
#include "Competition.h"
#include "ImmunityAward.h"
#include "Team.h"
#include "Round.h"
using namespace std;

class ImmunityCompetition : public Competition{

ImmunityAward immunityAward;

public:
ImmunityCompetition();
ImmunityCompetition(int id,string name,ImmunityAward immunityAward);
~ImmunityCompetition();

void setImmunityAward(ImmunityAward immunityAward);
ImmunityAward getImmunityAward();

void status();
void compete(Team &team);
};

#endif // IMMUNITYCOMPETITION_H_INCLUDED
