/*
-----Egrasia 2 Antikeimenostafh Programmatismou------
--Elenh Papaxristodoulou AEM:9580 epapachi@auth.gr --
--Mpekiarhs Theofanhs AEM:8200   theompek@auth.gr  --
--Aprilios 2018                                    --
*/

#ifndef TEAM_H_INCLUDED
#define TEAM_H_INCLUDED

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include "Player.h"

using namespace std;

#define MaxPlayers 11  //Megistos ari8mos paiktwn se omada

class Team{
//private values
string teamColor;
Player playerList[MaxPlayers];
int numOfPlayers;
int numOfVictories;
int numOfIngredients;

public:
  //Constructors & Destructor
  Team();
  Team(string teamColor);
  ~Team();

  //Sunarthseis set
  void set_teamColor(string teamColor);
  void set_PlayerInList(string firstName,string lastName,Player player); //Antikatastei to antikeimeno paikth me to epi8umhto onoma me to antikeimo player
  void set_PlayerInList(int index,Player player); //Antikatastei to antikeimono paikth sthn 8esh index tou pinaka me to antikeimo player
  void set_numOfPlayers(int numOfPlayers);
  void set_numOfVictories(int numOfVictories);
  void set_numOfIngredients(int numOfIngredients);

  //Sunarthseis get
  string get_teamColor();
  Player get_PlayerFromList(string firstName,string lastName);
  Player get_PlayerFromList(int index);
  int get_numOfPlayers();
  int get_numOfVictories();
  int get_numOfIngredients();

  //Basikes sunarthseis
  void addPlayer(Player player); //Pros8etei paikth sto telos ths listas
  void deletePlayer(string firstName,string lastName); //Diagrafei paikth apo thn lista me bash to onoma toy
  void deletePlayer(int index); //Diagrafei paikth apo thn lista me bash thn 8esh sthn lista



};

#endif // TEAM_H_INCLUDED
