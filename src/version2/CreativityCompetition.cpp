/*
-----Egrasia 3 Antikeimenostrafh Programmatismou------
--Elenh Papaxristodoulou AEM:9580 epapachi@auth.gr --
--Mpekiarhs Theofanhs AEM:8200   theompek@auth.gr  --
--Maios 2018                                    --
*/

#include "CreativityCompetition.h"
#define numOfIngredients 10

CreativityCompetition::CreativityCompetition(){
excursionAward = *new ExcursionAward();
ingredients = new string[numOfIngredients];
string arrayIngr[] = {"Patataki","Ntomataki","Ladaki","Fasolaki","Alataki","Koloki8aki","Makaronaki","Piperaki","Keftedaki","Zavarakatranemia"};
for(int i = 0;i<numOfIngredients;i++)
ingredients[i] = arrayIngr[i];

}

CreativityCompetition::CreativityCompetition(int id,string name,ExcursionAward excursionAward) : Competition(id,name){
this->excursionAward = excursionAward;
ingredients = new string[numOfIngredients];
string arrayIngr[] = {"Ladaki","Ntomataki","Patataki","Fasolaki","Alataki","Koloki8aki","Makaronaki","Piperaki","Keftedaki","Zavarakatranemia"};
for(int i = 0;i<numOfIngredients;i++)
ingredients[i] = arrayIngr[i];
}

CreativityCompetition::~CreativityCompetition(){
delete[] ingredients;
cout << "To antikeimeno 'CreativityCompetition' katastrafhke"<<endl;
}

void CreativityCompetition::setExcursionAward(ExcursionAward excursionAward){this->excursionAward = excursionAward;}
void CreativityCompetition::setIngredients(string ingredients,int index){this->ingredients[index] = ingredients;}
void CreativityCompetition::setIngredients(string *ingredients){
for(int i;i<numOfIngredients;i++)
this->ingredients[i] = ingredients[i];
}

ExcursionAward CreativityCompetition::getExcursionAward(){return excursionAward;}
string CreativityCompetition::getIngredients(int index){return ingredients[index];}

void CreativityCompetition::status(){
cout<<"Competition status:"<<endl;
Competition::status();
cout<<endl<<"ExcursionAward status:"<<endl;
excursionAward.status();
cout<<"Ingredients list:"<<endl;
for(int i=0;i<numOfIngredients;i++)
cout<<"Ingredients["<<i<<"]:"<<ingredients[i]<<endl;

}


void CreativityCompetition::compete(Team &team1,Team &team2){
Player *players[2] = {team1.getPlayers(),team2.getPlayers()}; //Eniaios pinakas(me pointers)
float maxTechnique = -1;
int teamIndex = 0;
int winnerIndex = 0;

for(int j=0;j<2;j++)
for(int i=0;i<11;i++)
if(players[j][i].getAge()!=0)
if(maxTechnique < players[j][i].getTechnique()){
maxTechnique = players[j][i].getTechnique();
teamIndex = j;
winnerIndex = i;
}
Round round(1,10800,players[teamIndex][winnerIndex].getName());//10800 sec = 3 hours
cout<<endl<<"Status of winner player before the changes:"<<endl;
players[teamIndex][winnerIndex].status();
//O nikhths au3anei tis nikes tou,thn texnikh tou,kai meiwnetai h dhmofilia tou
players[teamIndex][winnerIndex].setWins(players[teamIndex][winnerIndex].getWins()+1);
players[teamIndex][winnerIndex].setTechnique(players[teamIndex][winnerIndex].getTechnique()+excursionAward.getTechniqueBonus());
players[teamIndex][winnerIndex].setPopularity(players[teamIndex][winnerIndex].getPopularity()+excursionAward.getPopularityPenalty());
setWinner(players[teamIndex][winnerIndex].getName()); //CreativityCompetition winner name
cout<<"Status of winner player after:"<<endl;
players[teamIndex][winnerIndex].status();
}


