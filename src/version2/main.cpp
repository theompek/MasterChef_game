/*
-----Egrasia 3 Antikeimenostrafh Programmatismou------
--Elenh Papaxristodoulou AEM:9580 epapachi@auth.gr --
--Mpekiarhs Theofanhs AEM:8200   theompek@auth.gr  --
--Maios 2018                                    --
*/

#include "Team.h"
#include "CreativityCompetition.h"
#include "TeamCompetition.h"
#include "ImmunityCompetition.h"


using namespace std;

// Index 0 = Red Team, Index 1 = Blue Team
Team teams[2] = { Team("Red"), Team("Blue")};
int competitionId = 0;
int defeatedTeam = 0;
void menu();
void normalDay();
void teamCompetitionDay();
void immunityCompetitionDay();
void creativityCompetitionDay();

int main()
{
    menu();

    return 0;
}

void menu()
{
    int choice = -1;

    while(choice != 0)
    {
        cout << endl << "1.Normal Day." << endl;
        cout << "2.Team Competition Day." << endl;
        cout << "3.Immunity Competition Day." << endl;
        cout << "4.Creativity Competition Day." << endl;
        cout << "0.Quit" << endl;

        cin >> choice;

        switch(choice)
        {

        case 1:
            normalDay();
            break;
        case 2:
            teamCompetitionDay();
            break;
        case 3:
            immunityCompetitionDay();
            break;
        case 4:
            creativityCompetitionDay();
            break;
        case 0:
            break;
        default:
            cout << "Incorrect Input. Choose between 1 and 3. Press 0 to quit." << endl;

        }
    }
}

void normalDay()
{
cout << endl << "This is a normal day in the Master Chef Game." << endl << endl;
//Oi omades trwne prwino
teams[0].teamEats();
teams[1].teamEats();
//Oi omades kanoun douleies
teams[0].teamWorks();
teams[1].teamWorks();
//Metabalete h dhmofilia
teams[0].teamSocializes();
teams[1].teamSocializes();
//Oi omades trwne bradino
teams[0].teamEats();
teams[1].teamEats();
//Oi omades koimounte
teams[0].teamSleeps();
teams[1].teamSleeps();
}

void teamCompetitionDay()
{
cout << endl << "This is a Team Competition day in the Master Chef Game." << endl << endl;
//Oi omades ergazonte kai trwne
teams[0].teamWorks();
teams[1].teamWorks();
teams[0].teamEats();
teams[1].teamEats();
FoodAward foodAward("Kreata_Kai_Laxanika",false);
TeamCompetition teamCompetition(competitionId,"Mpoufes_Gamou",foodAward);
defeatedTeam = teamCompetition.compete(teams[0],teams[1]);
competitionId++;
teamCompetition.status();
//Oi omades trwne,suzhtane,koimountai
teams[0].teamEats();
teams[1].teamEats();
teams[0].teamSocializes();
teams[1].teamSocializes();
teams[0].teamSleeps();
teams[1].teamSleeps();
}

void immunityCompetitionDay()
{
cout << endl << "This is a Immunity Competition day in the Master Chef Game." << endl << endl;
//Oi omades ergazonte kai trwne
teams[0].teamWorks();
teams[1].teamWorks();
teams[0].teamEats();
teams[1].teamEats();
ImmunityAward immunityAward("Maxeri_Kai_Podia_Kouzinas",true);
ImmunityCompetition immunityCompetition(competitionId,"Paraskeuh_Pswmiou",immunityAward);
immunityCompetition.compete(teams[defeatedTeam]);
competitionId++;
immunityCompetition.status();
//Oi omades trwne,suzhtane,koimountai
teams[0].teamEats();
teams[1].teamEats();
teams[0].teamSocializes();
teams[1].teamSocializes();
teams[0].teamSleeps();
teams[1].teamSleeps();
}

void creativityCompetitionDay()
{
cout << endl << "This is a Creativity Competition day in the Master Chef Game." << endl << endl;
//Oi omades ergazonte kai trwne
teams[0].teamWorks();
teams[1].teamWorks();
teams[0].teamEats();
teams[1].teamEats();
ExcursionAward excursionAward("Estiatorio_Apostolakh",true);
CreativityCompetition creativityCompetition(competitionId,"Me_8ema_To_Lemoni",excursionAward);
creativityCompetition.compete(teams[0],teams[1]);
competitionId++;
creativityCompetition.status();
//Oi omades trwne,suzhtane,koimountai
teams[0].teamEats();
teams[1].teamEats();
teams[0].teamSocializes();
teams[1].teamSocializes();
teams[0].teamSleeps();
teams[1].teamSleeps();
}
