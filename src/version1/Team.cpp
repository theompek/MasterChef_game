/*
-----Egrasia 2 Antikeimenostafh Programmatismou------
--Elenh Papaxristodoulou AEM:9580 epapachi@auth.gr --
--Mpekiarhs Theofanhs AEM:8200   theompek@auth.gr  --
--Aprilios 2018                                    --
*/

#include "Team.h"

using namespace std;

//Constructors
Team::Team(){
teamColor = "";
for(int i=0;i<MaxPlayers;i++) playerList[i] = *new Player;
numOfPlayers = 0;
numOfVictories = 0;
}

Team::Team(string teamColor){
this->teamColor = teamColor;
for(int i=0;i<MaxPlayers;i++) playerList[i] = *new Player;
numOfPlayers = 0;
numOfVictories = 0;
}

//Destructor
Team::~Team(){
cout << "The object of the Team with color " << teamColor << " was destroyed." <<endl;
}

//Sunarthseis set
  void Team::set_teamColor(string teamColor){this->teamColor = teamColor;}

  //Antikatastei to antikeimeno paikth me to epi8umhto onoma me to antikeimo player
  void Team::set_PlayerInList(string firstName,string lastName,Player player){
       int i;
       for(i=0;i<numOfPlayers;i++){ //Psa3e sthn lista kai an breis paikth me to epi8umhto onoma antikatesthse ton
        if(playerList[i].get_firstName() == firstName &&
           playerList[i].get_lastName() == lastName)
          {
           playerList[i] = player;
           break;
          }
        }

       if(i==numOfPlayers)
       cout<<"O paikths me onoma "<<lastName<<" "<< firstName <<" den bre8hke sthn lista"<<endl;
      }

  //Antikatastei to antikeimono paikth sthn 8esh index tou pinaka me to antikeimo player
  void Team::set_PlayerInList(int index,Player player){
      if(index < MaxPlayers){
       playerList[index] = player;
       }else{
        cout << "O deikths index = " << index <<" einai ektos oriwn tou pinaka listas paiktwn"<<endl;
       }
  }

  void Team::set_numOfPlayers(int numOfPlayers){this->numOfPlayers = numOfPlayers;}
  void Team::set_numOfVictories(int numOfVictories){this->numOfVictories = numOfVictories;}
  void Team::set_numOfIngredients(int numOfIngredients){this->numOfIngredients = numOfIngredients;}

  //Sunarthseis get
  string Team::get_teamColor(){return teamColor;}

  Player Team::get_PlayerFromList(string firstName,string lastName){
      for(int i=0;i<numOfPlayers;i++){
       if(playerList[i].get_firstName() == firstName &&
          playerList[i].get_lastName() == lastName){
           return playerList[i];
          }
       }

     cout<<"O paikths me onoma "<<lastName<<" "<< firstName <<" den bre8hke sthn lista"<<endl;
     return (*new Player);
    }

  Player Team::get_PlayerFromList(int index){
     if(index < numOfPlayers)
     return playerList[index];

    cout << "O deikths index = " << index <<" megaluteros apo ton ari8mo twn dia8eshmwn paiktwn"<<endl;
    cout <<"Den uparxei paikths sthn antistoixh 8esh"<<endl<<endl;
    return (*new Player);
    }

  int Team::get_numOfPlayers(){return numOfPlayers;}
  int Team::get_numOfVictories(){return numOfVictories;}
 int Team::get_numOfIngredients(){return numOfIngredients;}


  //Basikes sunarthseis

  //Pros8etei paikth sto telos ths listas
  void Team::addPlayer(Player player){
   if(numOfPlayers<MaxPlayers){
    playerList[numOfPlayers] = player;
    numOfPlayers++;
   }else{
    cout << "O megistos ari8mos paiktwn mias omadas einai " << MaxPlayers <<".Den epitrepete pros8hkh epiplewn paiktwn"<<endl;
   }
  }

  //Diagrafei paikth apo thn lista me bash to onoma toy kai metatopoizei ola ta antikeimena paikth
  //pou briskontai apo ta de3ia pros ta aristera wste na mhn exoume asynexeia sthn lista
  void Team::deletePlayer(string firstName,string lastName){
  int flage = 1;
  for(int i=0;i<numOfPlayers;i++){ //Psa3e ton paikth pou 8a diagrapsoume
       if(playerList[i].get_firstName() == firstName &&
          playerList[i].get_lastName() == lastName){
           for(i++;i<numOfPlayers;i++) //kai fere mia 8esh katw olous tou upoloipous paiktes ths listas
           playerList[i-1] = playerList[i];

           playerList[i-1] = *new Player; //antikatestise to teleutaio antikeimeno me ena keno antikeimeno paikth
           numOfPlayers--;
           flage = 0;
        }
       }

     if(flage)
     cout<<"O paikths me onoma "<<lastName<<" "<< firstName <<" den bre8hke sthn lista"<<endl;

    }

  //Diagrafei paikth apo thn lista me bash thn 8esh sthn lista kai metatopoizei ola ta antikeimena paikth
  //pou briskontai apo ta de3ia pros ta aristera wste na mhn exoume asynexeia sthn lista

  void Team::deletePlayer(int index){
   if(index < numOfPlayers){
   for(index++;index<numOfPlayers;index++) //Fere mia 8esh katw olous tou upoloipous paiktes ths listas
   playerList[index-1] = playerList[index];

   playerList[index-1] = *new Player; //antikatestise to teleutaio antikeimeno me ena keno antikeimeno paikth
   numOfPlayers--;
   }else{
    cout<<"O deikths index = "<<index<<" einai ektos oriwn twn dia8eshmwn paiktwn ths listas = "<<numOfPlayers<<endl;
   }
}


