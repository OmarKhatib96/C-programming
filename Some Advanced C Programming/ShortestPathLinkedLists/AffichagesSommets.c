#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "listeAdjacence.h"
#include "AffichagesSommets.h"







void AfficherListe(Liste *liste){

    if (liste == NULL)
    {
        exit(EXIT_FAILURE);
    }

   Sommet2 *actuel =liste->premier;

    while (actuel->suivant!= NULL)
    {	
	Sommet*actuel2=actuel->voisins->premier;
		
		while(actuel2->suivant!=NULL){

			printf("Le sommet %d est distant de %d de %d unités\n",actuel2->numero,actuel->numero,actuel2->distance);
		 	actuel2 = actuel2->suivant;
        }
       

	actuel=actuel->suivant;
}




    }


