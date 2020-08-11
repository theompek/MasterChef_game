/*
-----Egrasia 2 Antikeimenostafh Programmatismou------
--Elenh Papaxristodoulou AEM:9580 epapachi@auth.gr --
--Mpekiarhs Theofanhs AEM:8200   theompek@auth.gr  --
--Aprilios 2018                                    --
*/

#include <iostream>
#include "Player.h"
#include "Team.h"
using namespace std;


Team addPlayerInTeam(Team team);
void displayTeam(Team team);
void displayPlayer(Team team);
int chooseTeam();
bool cinFailHandle(bool cinValue);

int main()
{
 srand (static_cast <unsigned> (time(0))); //We 'seed' the random numbers
//Dhmiourgia antikeimenwn omadwn
 Team teams[2];
 cout << "Dhmiourgia prwths omadas me 'red' xrwma" <<endl;
 teams[0] = *new Team("red");
 cout << "Dhmiourgia deuterhs omadas me 'blue' xrwma" <<endl;
 teams[1] = *new Team("blue");

 cout <<"Oi omades dhmiourgh8hkan"<<endl;

 int choice;
 int color;
 while(true){ //Basiko menou epilogwn programatos
 cout<<endl<<endl;
 cout<<"Menu:"<<endl;
 cout<<"Gia pros8hkh enos paikth se omada plhktrologiste ton ari8mo: 1"<<endl;
 cout<<"Gia probolh twn stoixeiwn mias omadas plhktrologiste ton ari8mo: 2"<<endl;
 cout<<"Gia probolh twn stoixeiwn enos paikth mias omadas plhktrologiste ton ari8mo: 3"<<endl;
 cout<<"Gia e3odo apo to programma plhktrologiste ton ari8mo: 4" <<endl;

 while(!cinFailHandle(cin>>choice)){};

 switch(choice){
 case 1:
   color = chooseTeam();
   teams[color] = addPlayerInTeam(teams[color]);
  break;
 case 2:
  color = chooseTeam();
  displayTeam(teams[color]);
  break;
 case 3:
  color = chooseTeam();
  displayPlayer(teams[color]);
  break;
 case 4:
  cout<<endl<<endl<< "Termatismos programmatos"<<endl;
  return 0; //E3odos apo to prwgramma
 default:
   cout<<"Plhktrologisate la8os epilogh apo to Menu,3ana prospa8hste"<<endl;
   break;
 }

 } //Telos while

 return 0;
}

/*
H sunarthsh xrhsimopoieitai gia thn pros8hkh enos paikth se mia omada.
Pairnei san orisma thn omada,kata thn ektelesh ths o xrhsths eisagei ta stoixeia toy
paikth kai h sunarthsh epistrefei antikeimeno ths omadas meta thn pros8hkh tou paikth sthn omada
*/
Team addPlayerInTeam(Team team){
string firstName;
string lastName;
string gender;
int age;
string occupation;

cout << "Plhktrologiste ta stoixeia toy paikth opws fainontai me thn parakatw seira"<<endl;
cout<<"firstName(a string)"<<endl;
cin>>firstName;
cout<<"lastName(a string)"<<endl;
cin>>lastName;
cout<<"gender(male or female)"<<endl;
cin>>gender;
do{
cout<<"age(an integer >= 18)"<<endl;
while(!cinFailHandle(cin>>age)){};
}while(age<18);
cout<<"occupation(a string)"<<endl;
cin>>occupation;

team.addPlayer(*new Player(firstName,lastName,gender,age,occupation));

cout<< "O paikths apo8hkeutike sthn lista paiktwn ths omadas"<<endl<<endl;
return team;
}


//H sunarthsh probalei tis metablhtes-stoixeia tou antikeimenou omadas
void displayTeam(Team team){
string go;
cout <<"Ta stoixeia ths omadas einai:"<<endl<<endl;
cout <<"teamColor = "<<team.get_teamColor()<<endl;
cout <<"numOfPlayers = "<<team.get_numOfPlayers() <<endl;
cout <<"numOfVictories = "<<team.get_numOfVictories() <<endl;
cout <<"numOfIngredients = "<<team.get_numOfIngredients() <<endl<<endl;

cout <<"Plhktrologhste ena opoiodhpote plhktro gia sunexeia sto programma"<<endl;
cin>>go;

}

//H sunarthsh probalei tis metablhtes-stoixeia tou antikeimenou paikth
void displayPlayer(Team team){
string go;
string choice;
Player player;

cout<<"Plhktrologiste 1 gia anazhthsh me to onoma tou paikth h opoiodhpote allo plhktro gia anazhthsh ws pros thn 8esh sthn lista"<<endl;
cin>>choice;

if(choice == "1"){
string lastName;
string firstName;
cout<<"Plhktrologiste to 'lastName' tou paikth"<<endl;
cin>>lastName;
cout<<"Plhktrologiste to 'firstName' tou paikth"<<endl;
cin>>firstName;

player = team.get_PlayerFromList(firstName,lastName);
}else{
int index;
cout<<"Plhktrologiste thn 8esh tou paikth sthn lista(prwth 8esh paikth ston pinaka antistoixei se plhktro 1 kai oxi se 0)"<<endl;
cin>>index;
player = team.get_PlayerFromList(index-1);
}

if(player.get_firstName()!= ""){ //An o paikths uparxei
cout <<endl<<"Ta stoixeia tou paikth einai"<<endl<<endl;
cout <<"firstName =" <<player.get_firstName() <<endl;
cout <<"lastName =" <<player.get_lastName() <<endl;
cout <<"gender =" <<player.get_gender() <<endl;
cout <<"age =" <<player.get_age() <<endl;
cout <<"occupation =" <<player.get_occupation() <<endl;
cout <<"abilities =" <<player.get_abilities() <<endl;
cout <<"fatigue =" <<player.get_fatigue() <<endl;
cout <<"popularity =" <<player.get_popularity() <<endl;
cout <<"numOfVictories =" <<player.get_numOfVictories() <<endl;
}


cout <<"Plhktrologhste ena opoiodhpote plhktro gia sunexeia sto programma"<<endl;
cin>>go;
}

//H sunarthsh xrhsimopoieitai gia thn epilogh omadas apo ton xrhsth sto menu ths main
//Epistrefei 0 gia thn 'red' omada(prwth omada) kai 1 gia thn 'blue' omada(deuterh omada)
int chooseTeam(){
 string color;
 while(true){
 cout<<"Plhktrologiste 0 gia thn epilogh ths 'red' omadas h 1 gia thn epologh ths 'blue' omadas"<<endl;
 cin>>color;

 if(color=="0"){
  return 0;
 }else if(color=="1"){
  return 1;
 }

  cout<<"Plhktrologisate la8os epilogh gia omada,prepei 0 h 1, 3ana prospa8hste"<<endl<<endl;
 }

}

/*H sunarthsh diaxeirizetai to sfalma kata thn eisagwgh apo ton xrhsth metablhths 'string' se metablhsh 'integer'
--Sthn main xrhshmopoieitai me thn morfh
int value;
while(!cinFailHandle(cin>>value)){};
--Dhladh mexri na eisagei o xrhsths tupo 'integer' sthn metablhth value,8a ekteleitai sunexeia h while().
*/
bool cinFailHandle(bool cinValue){

if(!cinValue){
 cin.clear();
 cin.ignore();
 cout<<"La8os typos dedomenwn,plhktrologiste enan 'integer' tupo. "<<endl;
return false;
}

return true;
}
