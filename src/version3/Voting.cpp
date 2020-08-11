/*
-----Egrasia 4 Antikeimenostrafh Programmatismou------
--Elenh Papaxristodoulou AEM:9580 epapachi@auth.gr --
--Mpekiarhs Theofanhs AEM:8200   theompek@auth.gr  --
--Maios 2018                                    --
*/

#include "Voting.h"
//Arxikopoihsh ektos sunarthshs
vector<Vote> Voting::votes;
map<string,int> Voting::results;

void takeVotes(Player *players,vector<Vote> &votes);
void votesCounting(Player *players,vector<Vote> &votes,map<string,int> &results);
void findCandidates(Player *players,map<string,int> &results);
void removePlayer(Team &team);

void Voting::votingProcess(Team &team){
/* initialize random seed: */
srand (time(NULL));
Player *players = team.getPlayers();

if(team.getNumberOfPlayers()<4){cout<<endl<<"We haven't enough players for voting"<<endl<<endl; return;}

takeVotes(players,votes); //Kata8esh sphfwn

cout<<endl<<"Voting Process:"<<endl;
for(unsigned int i = 0;i<votes.size();i++) votes[i].status(); //Ektupwsh apotelesmatwn
cout<<endl;

votesCounting(players,votes,results); //Katametrhsh pshfwn

for(int i = 0;i<11;i++)//Ektupwsh apotelesmatwn
if(players[i].getAge() != 0)
cout<<"Player "<<players[i].getName()<<" has "<<results[players[i].getName()]<<" votes."<<endl;

findCandidates(players,results); //Euresh 2 uposphfiwn gia apoxwrhsh

cout<<endl<<"Oi uposphfioi gia apoxwrhsh einai: "<<endl;
for(int i = 0;i<11;i++)
if(players[i].getAge() != 0 && players[i].getCandidate() == true)
players[i].status();

removePlayer(team); //Epilogh paikth gia apoxwrhsh

votes.clear();
results.clear();
}

//Sunarthsh gia ton tropo sphfoforias,edw orizoume na einai apla tuxaios o tropos sphfoforias
int voteSomeone(){return rand()%11;}

//H sunarthsh pairnei orisma anafora sto dianusma twn sphfwn kai
//topo8etei tis pshfous apo thn diadikasia sphfoforias sto dianusma
void takeVotes(Player *players,vector<Vote> &votes){
string reasons[6] = {"O pio adunamos paikths *(o_O)*","Kakh sumperifora (-_-;)","Prospa8ei na dhmiourghsei problhmata stous sumpektes (o__o!) ","Adumania sunergasias (*_*)","Apomakros me kakes diaproswphkes sxeshs @(~_~)@ ","Trwei kryfa faghto ta bradia ```|_(o_O)_|```"};

for(int i=0;i<11;i++){
 int prevVotes[3] = {-1,-1,-1};
 if(players[i].getAge()!=0)
  for(int votesNum = players[i].getVotes(); votesNum > 0; votesNum--)
  {
   int index = voteSomeone();
   //An den pshfizei ton eauto tou && o paikths pou sphfizetai uparxei && den exei asulia && den exoume pollaples pshfous ston idio paikth apo idio paikth
   if(index!=i && players[index].getAge()!=0 && players[index].getImmunity() == false
     && index != prevVotes[0] && index != prevVotes[1] && index != prevVotes[2]){
    prevVotes[votesNum-1] = index;
    votes.push_back(*new Vote(players[index],reasons[rand()%6]) );
   }else{
    votesNum++; //3ana pshfise kapoion allo paikth
   }
  }
 }

}
//Oi sunarthsh pairnei orismata se anafores kai kanei thn katametrhsh kai
//to maping twn paiktwn-pshfwn.Sto telos ths diadikasia o xarths 'results' 8a exei
//ws kleidia ta onomata twn paiktwn kai times twn ari8mo twn pshfwn pou sugeprwse o ka8enas
void votesCounting(Player *players,vector<Vote> &votes,map<string,int> &results){
string key;
int value;

for(int i=0; i<11; i++)     //Gia ka8e paikth
if(players[i].getAge()!=0){
 key = players[i].getName();
 value = 0;

 for(unsigned int j=0; j < votes.size(); j++)  //metrame tis pshfoys pou exei lavei
  if(votes[j].getVoted() == key )
   value++;

 results.insert( pair<string,int>(key, value) );
 }
}

//Orisma anafora sto map kai briskei tous 2 paiktes pros apoxwrhsh
void findCandidates(Player *players,map<string,int> &results){
int maxValue[2] = {-1,-1};
int index[2] = {0,0};
int numOfVotes;

for(int i=0; i < 11; i++)
 if(players[i].getAge()!=0){
 numOfVotes = results[players[i].getName()];

  if(maxValue[0]<numOfVotes){
   if(maxValue[0]>maxValue[1]){
    maxValue[1] = maxValue[0];
    index[1] = index[0] ;
   }
   maxValue[0] = numOfVotes;
   index[0] = i;
   }else if(maxValue[1]<numOfVotes){
    maxValue[1] = numOfVotes;
    index[1] = i;
     }
  }

players[index[0]].setCandidate(true);
players[index[1]].setCandidate(true);

cout<<endl<<"Arxikopopioume ton paikth me asulia: Immunity-> false , Votes ->1 "<<endl<<endl;
for(int i = 0;i<11;i++)
 if(players[i].getAge() != 0 && players[i].getImmunity() == true){
   players[i].setImmunity(false);
   players[i].setVotes(1);
   break;
 }
}

//H sunarthsh briskei ton upopshfio me thn xeiroterh texnikh kai ton diagrafei apo thn omada
//epipleon 8etei thn metablhth candidate tou allou uposphfiou sthn arxikh timh,dhladh se timh 'false'
void removePlayer(Team &team){
Player *players = team.getPlayers();
int cand_index[2] = {0,0};
int k=0;

for(int i = 0;i<11;i++)
 if(players[i].getAge() != 0 && players[i].getCandidate() == true && k < 2){
  cand_index[k++] = i;
 }
if(players[cand_index[0]].getTechnique() < players[cand_index[1]].getTechnique()){
 cout<<"O paikths pou apoxwrei telika einai:"<<endl;
 players[cand_index[0]].status();
  team.removePlayer(players[cand_index[0]].getName());
 players[cand_index[1]].setCandidate(false);
}else{
 cout<<"O paikths pou apoxwrei telika einai:"<<endl;
 players[cand_index[1]].status();
 team.removePlayer(players[cand_index[1]].getName());
 players[cand_index[0]].setCandidate(false);
}

}
