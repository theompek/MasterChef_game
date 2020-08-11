/*
-----Egrasia 2 Antikeimenostafh Programmatismou------
--Elenh Papaxristodoulou AEM:9580 epapachi@auth.gr --
--Mpekiarhs Theofanhs AEM:8200   theompek@auth.gr  --
--Aprilios 2018                                    --
*/

#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

using namespace std;

class Player{
//private values
 string firstName;
 string lastName;
 string gender;
 int age;
 string occupation;
 float abilities;
 float fatigue;
 float popularity;
 int numOfVictories;

public:
  //Constructors & Destructor
  Player();
  Player(string firstName,string lastName,string gender,int age,string occupation);
  ~Player();



  //Sunarthseis set
  void set_firstName(string firstName);
  void set_lastName(string lastName);
  void set_gender(string gender);
  void set_occupation(string occupation);
  void set_age(int age);
  void set_abilities(float abilities);
  void set_fatigue(float fatigue);
  void set_popularity(float popularity);
  void set_numOfVictories(int numOfVictories);

  //Sunarthseis get
  string get_firstName();
  string get_lastName();
  string get_gender();
  string get_occupation();
  int get_age();
  float get_abilities();
  float get_fatigue();
  float get_popularity();
  int get_numOfVictories();

  //Basikes sunarthseis drashs tou paikth
  void work();
  void communicate();
  void workOrRest();
  void compete();

};

#endif // PLAYER_H_INCLUDED
