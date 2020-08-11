/*
-----Egrasia 2 Antikeimenostafh Programmatismou------
--Elenh Papaxristodoulou AEM:9580 epapachi@auth.gr --
--Mpekiarhs Theofanhs AEM:8200   theompek@auth.gr  --
--Aprilios 2018                                    --
*/


#include "Player.h"

using namespace std;

//Constructors
Player::Player(){

firstName = "";
lastName = "";
gender = "";
age = 0;
occupation = "";
abilities = 0;
fatigue = 0;
popularity = 0;
numOfVictories = 0;


}

Player::Player(string firstName,string lastName,string gender,int age,string occupation){

this->firstName = firstName;
this->lastName = lastName;
this->gender = gender;
this->age = age;
this->occupation = occupation;
abilities = (rand()*80)/((float) RAND_MAX); // 0 <= abilities_initial_value <= 80
fatigue = 0; // fatigue_initial_value = 0
popularity = 50; //Initial_value = 50
numOfVictories = 0; //Initial_value = 0

}

//Destructor
Player::~Player(){
cout << "The object of the player with name- " << lastName<< " "<< firstName << " -was destroyed." <<endl;
}

//Sunarthseis set
void Player::set_firstName(string firstName){this->firstName = firstName;}
void Player::set_lastName(string lastName){this->lastName = lastName;}
void Player::set_gender(string gender){this->gender = gender;}
void Player::set_occupation(string occupation){this->occupation = occupation;}
void Player::set_age(int age){this->age = age;}
void Player::set_abilities(float abilities){this->abilities = abilities;}
void Player::set_fatigue(float fatigue){this->fatigue = fatigue;}
void Player::set_popularity(float popularity){this->popularity = popularity;}
void Player::set_numOfVictories(int numOfVictories){this->numOfVictories = numOfVictories;}

//Sunarthseis get
string Player::get_firstName(){return firstName ;}
string Player::get_lastName(){return lastName ;}
string Player::get_gender(){return gender ;}
string Player::get_occupation(){return occupation ;}
int Player::get_age(){return age ;}
float Player::get_abilities(){return abilities ;}
float Player::get_fatigue(){return fatigue ;}
float Player::get_popularity(){return popularity ;}
int Player::get_numOfVictories(){return numOfVictories ;}

//Basikes sunarthseis drashs tou paikth
//Au3hsh ths kourashs kata 20%-40 apoluta kai ths ikanothtas tou paikth kata 5% posostiea
void Player::work(){
float incrementPercent = 20 + (rand()*20)/((float) RAND_MAX); // 20<=incrementPercent<=40
fatigue += incrementPercent; //Au3hsh kata 20%-40% apoluta

abilities += abilities*0.05; //Au3hsh kata 5% posostiea
}

//Metabolh ths dhmofilias tou paikth kata -10% ws 10% tuxaia
void Player::communicate(){
float incrementPercent = -10 + (rand()*20)/((float) RAND_MAX); // -10<=incrementPercent<=10
popularity += popularity*(incrementPercent/100); //Metabolh kata -10% ws 10% posostiea

}

//H sunarthsh epilegei tuxaia an o paikths 8a 3ekourasth h an 8a doulepsei
void Player::workOrRest(){
float randNum = rand()/((float) RAND_MAX);

if(randNum>=0.5){ //O paikths 8a koimh8ei
 fatigue = 0;
}else{ //O paikths 8a kanei e3askhsh
 abilities += 5; //Au3hsh kata 5% apoluta
}

}

//Metabalh thn kourash tou paikth kata 10% ws 20% posostiea
void Player::compete(){
float incrementPercent = 10 + (rand()*10)/((float) RAND_MAX); // 10<=incrementPercent<=20
fatigue += fatigue*(incrementPercent/100); //Au3hsh kata 10%-20% posostiea
};
