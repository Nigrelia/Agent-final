#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "agent2.h"

int main() {
	
    agent a;
    int c;

    do {
        printf("Menu:\n");
        printf("1 - Ajout d'un agent\n");
        printf("2 - Affichage de la liste des agents\n");
        printf("3 - Modification des info d'un agent\n");
        printf("4 - Suppression d'un agent\n");
	printf("5 - afficher les reservations dans une date \n");
	printf("6 - afficher les infos d'un agent \n");  
        printf("Donner votre choix: \n");
        scanf("%d", &c);

        

        switch (c) {
		
            case 1:
                ajout_agent("agents.txt");
		
                break;
            case 2:
                affichage_agent(&a, "agents.txt");
		
                break;
            case 3:
                mod_agent("agents.txt","temp_agents.txt");
		
                break;
            case 4:
                supp_agent("agents.txt","temps_agents.txt");
		
                break;
		case 5:
                affichage_res("reservations.txt");
                break;
	case 6 :
	chercher_agent("agents.txt",&a);
	break;
	default :
	printf("choix invalide \n");
	break;
        }
}while(c >1 || c <6); 
    


    return 0;
}

