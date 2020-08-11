/*
-----Egrasia 4 Antikeimenostrafh Programmatismou------
--Elenh Papaxristodoulou AEM:9580 epapachi@auth.gr --
--Mpekiarhs Theofanhs AEM:8200   theompek@auth.gr  --
--Maios 2018                                    --
*/

#ifndef VOTING_H_INCLUDED
#define VOTING_H_INCLUDED
#include "Vote.h"
#include <vector>
#include <map>

using namespace std;

class Voting{
public:
static vector<Vote> votes;
static map<string,int> results;

//Exoume mono static metablhtes ara den exoume constructors/destructor
//afou den exoyme dhmiourgia antikeimenwn sthn klash auth

static void votingProcess(Team &team);
};

#endif // VOTING_H_INCLUDED
