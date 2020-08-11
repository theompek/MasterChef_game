/*
-----Egrasia 3 Antikeimenostrafh Programmatismou------
--Elenh Papaxristodoulou AEM:9580 epapachi@auth.gr --
--Mpekiarhs Theofanhs AEM:8200   theompek@auth.gr  --
--Maios 2018                                    --
*/

#include "TeamCompetition.h"
using namespace std;

TeamCompetition::TeamCompetition(){
foodAward = *new FoodAward();
rounds = new Round[3];
}

TeamCompetition::TeamCompetition(int id,string name,FoodAward foodAward) : Competition(id,name){
this->foodAward = foodAward;
this->rounds = new Round[3];
}

TeamCompetition::~TeamCompetition(){
delete[] rounds;
cout << "To antikeimeno 'Competition' katastrafhke"<<endl;
}

void TeamCompetition::setFoodAwards(FoodAward foodAward){this->foodAward = foodAward;}
void TeamCompetition::setRounds(Round *rounds){
this->rounds[0] = rounds[0];
this->rounds[1] = rounds[1];
this->rounds[2] = rounds[2];
}
void TeamCompetition::setRounds(Round rounds,int index){this->rounds[index] = rounds;}

FoodAward TeamCompetition::getFoodAwards(){return foodAward;}
Round TeamCompetition::getRounds(int index){return rounds[index];}

void TeamCompetition::status(){
cout<<"Comperirion status:"<<endl;
Competition::status();
cout<<endl<<"FoodAward status:"<<endl;
foodAward.status();
cout<<"Rounds status:"<<endl;
rounds[0].status();
rounds[1].status();
rounds[2].status();
}

/*
H sunarthsh compete() anaparhsta thn diadikasia tou omadikou diagonhsmoy kai epistrefei
0 h 1 pou deixnei thn xamenei omada.Gia thn epilogh twn 5 paiktwn ka8e omadas dhmiourgoume
tous pinakes index1[] kai index2[] stous opoious apo8hkeuoume times apo to 0-10 h opoies
antistoixoun stis 5 8eseis twn 5 paiktwn ths lista paiktwn pou 8a epilegoun gia na diagwnistoun
ston guro ths dokimasia.Epipleon ginontai oi aparaithtoi elegxei gia na mhn epilegei 2 fores o idios paikths
ston idio guro kai elegxos gia thn upar3ei paikth sthn 8esh pou deixnei o index.Telos h diadikasia me thn opoia
epilegete o nikhth einai ayth pou orizetai sto diagramma rohs ths ekfwnhshs.
*/
int TeamCompetition::compete(Team &team1,Team &team2){
int wins1 = 0;
int wins2 = 0;
int round = 0;
Player *players1 = team1.getPlayers();
Player *players2 = team2.getPlayers();
int index1[5] = {-1,-1,-1,-1,-1};
int index2[5] = {-1,-1,-1,-1,-1};
float technAvg1 = 0;
float technAvg2 = 0;
float fatigueAvg1 = 0;
float fatigueAvg2 = 0;


if(team1.getNumberOfPlayers()<5 || team1.getNumberOfPlayers()<5){
cout<<"O ari8mos paiktwn kapoias omadas einai mikroteros tou 5"<<endl;
}else{

while(round<3){
//Epilogh paiktwn omada1
for(int i=0;i<5;i++){
 index1[i] = rand()%11; //paragwgh timwn se diasthma 0-10
 if(players1[index1[i]].getAge()==0){
  i--; //An o paikths sthn antistoixh 8esh den uparxei orise 3ana index
 }else{
  for(int j=0;j<i;j++)  //Gia na mhn diale3oume 3ana idio paikth
  if(index1[i] == index1[j]){i--; break;} //An exoume epile3ei hdh ton paikth gia thn dokimasia,tote 3ana dialegoume
 }
}
//Epilogh paiktwn omada2
for(int i=0;i<5;i++){
 index2[i] = rand()%11; //paragwgh timwn se diasthma 0-10
 if(players2[index2[i]].getAge()==0){
  i--; //An o paikths sthn antistoixh 8esh den uparxei orise 3ana index
 }else{
  for(int j=0;j<i;j++)  //Gia na mhn diale3oume 3ana idio paikth
  if(index2[i] == index2[j]){i--; break;} //An exoume epile3ei hdh ton paikth gia thn dokimasia,tote 3ana dialegoume
 }
}

for(int i=0;i<5;i++){
//Den xrhsimopoioume thn sunarthsh compete() ths klashs player giati h sunarthsh
//ayth metabalh thn kourash kata 10%-20%,ara to kanoume me xrhsh setter/getter
//Au3hsh kourashs apoluta kata 5%-10%
float fatigueIncr1 = 5 + (((float) rand()) / (float) RAND_MAX)*5; //Kourash kata 5%-10%
float fatigueIncr2 = 5 + (((float) rand()) / (float) RAND_MAX)*5; //Kourash kata 5%-10%
players1[index1[i]].setFatigue( players1[index1[i]].getFatigue()+fatigueIncr1 );
players2[index2[i]].setFatigue( players2[index2[i]].getFatigue()+fatigueIncr2 );

technAvg1 += players1[index1[i]].getTechnique()/5;
technAvg2 += players2[index2[i]].getTechnique()/5;
//Oi paiktes ths dokimasias den metabaloun tis nikes tous afou den einai atomikes
}

//E3etazoume ton meso oro texnikhs
if(technAvg1>technAvg2){
 rounds[round] = Round(round+1,10800,"Team1"); //10800 sec = 3 hours
 wins1++;
}else if(technAvg1<technAvg2){
 rounds[round] = Round(round+1,10800,"Team2"); //10800 sec = 3 hours
 wins2++;
}else{
    //Sthn periptwsh isotimias sthn texnikh elegxoume tous ligotero kourasmenous
    for(int i=0;i<5;i++){
    fatigueAvg1 += players1[index1[i]].getFatigue()/5;
    fatigueAvg2 += players2[index2[i]].getFatigue()/5;
    }

    if(fatigueAvg1<fatigueAvg2){
    rounds[round] = Round(round+1,10800,"Team1"); //10800 sec = 3 hours
    wins1++;
    } else{
    rounds[round] = Round(round+1,10800,"Team2"); //10800 sec = 3 hours
    wins2++;
    }
}

round++;
for(int i=0;i<5;i++){index1[i] = -1; index2[i] = -1; }
technAvg1 = 0;
technAvg2 = 0;
fatigueAvg1 = 0;
fatigueAvg2 = 0;
}//Telos Rounds loop
}

if(wins1>=2){
cout<<endl<<"Status of winner team before the changes"<<endl;
team1.status(false);
team1.setWins(team1.getWins()+1);
team1.setSupplies(team1.getSupplies()+foodAward.getBonusSupplies());
setWinner("team1"); //TeamCompetitionWinner
cout<<"Status of winner team after the changes"<<endl;
team1.status(false);
return 1;
}
else{
cout<<endl<<"Status of winner team before the changes"<<endl;
team1.status(false);
team2.setWins(team2.getWins()+1);
team2.setSupplies(team2.getSupplies()+foodAward.getBonusSupplies());
setWinner("team2"); //TeamCompetitionWinner
cout<<"Status of winner team after the changes"<<endl;
team1.status(false);
return 0;
}

}
