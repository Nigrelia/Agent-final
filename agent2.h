#ifndef AGENT_H_INCLUDED
#define AGENT_H_INCLUDED
typedef struct
{

char id_agent[20];
char nom_agent[20];
char prenom_agent[20];
char sexe_agent[10];
float sal_agent;
char type_contact[20];
char contact[50];
char moyen_agent[20];
char park[20];

} agent ;
typedef struct
{
int j;
int m;
int a;
}date;

typedef struct
{
char id_citoyen[50];
char id_parking[50];
char service_c[50];
date date_res;

}reservation;






;

void saisir_agent (agent *a) ;
void ajout_agent(char *agents);
void affichage_agent (agent *a, char *agents);
void mod_agent(char *agents,char *temp_agents);
void supp_agent(char *agents,char *temp_agents);
void affichage_res(char *reservations);
void chercher_agent(char *agents,agent *a);






#endif 
