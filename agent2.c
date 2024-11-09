#include <stdio.h>
#include <stdlib.h>
#include "agent2.h"
#include "string.h"


//saisir agent

void saisir_agent(agent *a)
{
	printf("Donner l'ID de l'agent a ajouter : \n");
	scanf("%s",a->id_agent);
	printf("Donner le nom de l'agent a ajouter : \n");
	scanf("%s",a->nom_agent);
	printf("Donner le prénom de l'agent a ajouter : \n");
	scanf("%s",a->prenom_agent);
	printf("Donner le sexe de l'agent a ajouter : \n");
	scanf("%s",a->sexe_agent);
	printf("Donner la salaire de l'agent a ajouter : \n");
	scanf("%f",&a->sal_agent);
	printf("Donner le type de contact de l'agent a ajouter : \n");
	scanf("%s",a->type_contact);
	printf("Donner le contact de l'agent a ajouter : \n");
	scanf("%s",a->contact);
	printf("Donner le moyen de transport de l'agent a ajouter : \n");
	scanf("%s",a->moyen_agent);
	strcpy(a->park, "Non_affecte");

 
}


//ajouter les agents

void ajout_agent(char *agents)
{
    int i ;
    FILE *f = fopen(agents, "a+");  
    if (f == NULL) {
        printf("erreur");
        return;
    }

   agent a1;
    saisir_agent(&a1);
	int pos = 0;

    agent a; 
 while (fscanf(f, "%s %s %s %s %f %s %s %s %s", a.id_agent, a.nom_agent, a.prenom_agent,a.sexe_agent, &a.sal_agent, a.type_contact, a.contact,a.moyen_agent,a.park)!= EOF) 
	{
          if (strcmp(a.id_agent, a1.id_agent) == 0) 
	{
            pos = 1;  
            break;
        }
	}   

    if (pos == 1) {
        
        printf("L'id agent existe déjà\n");
    } else {
        
        fprintf(f, "%s %s %s %s %.2f %s %s %s %s \n", a1.id_agent, a1.nom_agent, a1.prenom_agent,a1.sexe_agent, a1.sal_agent, a1.type_contact, a1.contact,a1.moyen_agent,a1.park);
        printf("Agent ajouté avec succès!\n");
    }

fclose(f);
    
   
}

//affichage des agents

void affichage_agent (agent *a,char *agents)
{
	

    FILE *f = fopen(agents, "r");  
    if (f == NULL) {
        printf("erreur");
        return;
    }

   
    
    while (fscanf(f, "%s %s %s %s %f %s %s %s %s", a->id_agent, a->nom_agent, a->prenom_agent,a->sexe_agent, &a->sal_agent, a->type_contact, a->contact,a->moyen_agent,a->park) !=EOF) 
	{
        printf("%s %s %s %s %.2f %s %s %s %s \n", a->id_agent, a->nom_agent, a->prenom_agent,a->sexe_agent, a->sal_agent, a->type_contact, a->contact,a->moyen_agent,a->park); 
    	}

    
fclose(f);
    
   


}

//modification des info des agents


		
		


	void mod_agent(char *agents,char *temp_agents) {
  
		


		int pos=-1;
		int x;
		char c[20];
		printf("Donner l'ID de l'agent a modifier: \n");
    		scanf("%s", c);
		
		FILE *f = fopen(agents, "r");  
    		if (f == NULL) {
        	printf("erreur \n");
        	return;
    		}
		FILE *f1 = fopen(temp_agents, "w");
		if (f1 == NULL) {
        	printf("erreur \n");
        	return;
    		}
		agent a;
		while (fscanf(f, "%s %s %s %s %f %s %s %s %s", a.id_agent, a.nom_agent, a.prenom_agent,a.sexe_agent, &a.sal_agent, a.type_contact, a.contact,a.moyen_agent,a.park)!= EOF) 
		{
        	if(strcmp(c,a.id_agent)==0)
		{
		pos=1;
		
		
		do {
                printf("1 - Nom\n");
                printf("2 - Prenom\n");
                printf("3 - Sexe\n");
                printf("4 - Salaire\n");
                printf("5 - Type de contact\n");
                printf("6 - Contact\n");
                printf("7 - etat\n");
                printf("0 - quitter \n");
                printf("Choisir le champ a modifier: \n");
                scanf("%d", &x);
		}while(x<0||x>7);

		
		
                
                switch (x) {
                    case 1:
                        printf("Saisir la modification du nom: \n");
                        scanf("%s", a.nom_agent);
                        break;
                    case 2:
                        printf("Saisir la modification du prenom: \n");
                        scanf("%s", a.prenom_agent);
                        break;
                    case 3:
                        printf("Saisir la modification du sexe: \n");
                        scanf("%s", a.sexe_agent);
                        break;
                    case 4:
                        printf("Saisir la modification du salaire: \n");
                        scanf("%f", &a.sal_agent);
                        break;
                    case 5:
                        printf("Saisir la modification du type de contact: \n");
                        scanf("%s", a.type_contact);
                        break;
                    case 6:
                        printf("Saisir la modification du contact: \n");
                        scanf("%s", a.contact);
                        break;
                    case 7:
                        printf("Saisir la modification de moyen de transport: \n");
                        scanf("%s",a.moyen_agent);
                        break;
                    
                }
	
		
		
		}
		 	fprintf(f1, "%s %s %s %s %.2f %s %s %s %s \n", a.id_agent, a.nom_agent, a.prenom_agent,a.sexe_agent, a.sal_agent, a.type_contact, a.contact,a.moyen_agent,a.park);
		 
    		}

		

		
		fclose(f);
		fclose(f1);
		
		
		if(pos==-1)
		{
		printf("l'id n'existe pas \n");
		remove(temp_agents);
		}
		
		
		
	else 	{
		remove(agents);
		rename(temp_agents, agents);
		printf("DONE\n");
		}
		
		}
		
		


		//supp agent
	
	void supp_agent(char *agents,char *temp_agents)
		{

		char c[20];
			
			int pos=-1;
		
			printf("Donner l'ID de l'agent a supprimmer: \n");
    			scanf("%s", c);
			int i,l=0;
			FILE *f = fopen(agents, "r");  
    			if (f == NULL) {
        		printf("erreur \n");
        		return;
    			}
			FILE *f1 = fopen(temp_agents, "w");
			if (f1 == NULL) {
        		printf("erreur \n");
        		return;
    			}
			agent a;
			
			while (fscanf(f, "%s %s %s %s %f %s %s %s %s", a.id_agent, a.nom_agent, a.prenom_agent,a.sexe_agent, &a.sal_agent, a.type_contact, a.contact,a.moyen_agent,a.park)!= EOF) 
			{
        		  if(strcmp(c,a.id_agent)==0)
			{
			pos=1;
			}
			if(strcmp(c,a.id_agent)!=0)	
							{
				fprintf(f1, "%s %s %s %s %.2f %s %s %s %s \n", a.id_agent, a.nom_agent, a.prenom_agent,a.sexe_agent, a.sal_agent, a.type_contact, a.contact,a.moyen_agent,a.park);
    							}

				}
			
			
			fclose(f);
			fclose(f1);
			if(pos==1)
			{
			remove(agents);
			rename(temp_agents,agents);
			printf("DONE\n");
			}
			
			
			else
			{
			printf("l'id n'existe pas \n");
			remove(temp_agents);
			}
			
		

			
		
			}
		//affichage_res
	
	void affichage_res(char *reservations)
		{
			reservation r ;
			int j1,m1,a1;
			int trouve=0;	
			printf("donner le jour\n");
			scanf("%d",&j1);
			printf("donner le mois\n");
			scanf("%d",&m1);
			printf("donner l'annee\n");
			scanf("%d",&a1);
		
			FILE *f = fopen(reservations, "r");
			  
    				if (f == NULL) 
			{
        		printf("erreur \n");
        		return;
    			}
			
			while (fscanf(f, "%s %s %s %d %d %d", r.id_citoyen, r.id_parking, r.service_c,&r.date_res.j, &r.date_res.m, &r.date_res.a) !=EOF) 
					{
					if(r.date_res.j==j1 && r.date_res.m==m1 && r.date_res.a==a1)
					{
        				printf("%s %s %s %d %d %d \n", r.id_citoyen, r.id_parking, r.service_c,r.date_res.j, r.date_res.m, r.date_res.a);
					trouve=1; 
					}
    					}
			if(trouve==0)
			printf("aucune reservation dans cette date\n");

			fclose(f);
		


			
		}


void chercher_agent(char *agents,agent *a)
{
	char x[50];
	FILE *f=fopen(agents,"r");
			if (f == NULL) 
			{
        		printf("erreur \n");
        		return;
    			}
	printf("donner l'id de l'agent a chercher \n");
	scanf("%s",x);
	while(fscanf(f,"%s %s %s %s %f %s %s %s %s", a->id_agent, a->nom_agent, a->prenom_agent,a->sexe_agent, &a->sal_agent, a->type_contact, a->contact,a->moyen_agent,a->park) !=EOF) 
	{if(strcmp(x,a->id_agent)==0)
		{
		printf("%s %s %s %s %f %s %s %s %s \n", a->id_agent, a->nom_agent, a->prenom_agent,a->sexe_agent, a->sal_agent, a->type_contact, a->contact,a->moyen_agent,a->park);
		break;
		}
			
		}

}







		

		
		
		
		
		
		
		

	
































   



















































