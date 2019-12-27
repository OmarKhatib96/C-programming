#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "listeAdjacence.h"
#include "AffichagesSommets.h"
#include "file.h"



void AfficherListe(Liste *liste,int nbr_sommets){
    int i=0;
    if (liste == NULL)
    {
        exit(EXIT_FAILURE);
    }

   Sommet *actuel = liste->premier;

    while (actuel != NULL)
    {

        printf("Les voisins du sommet %d sont les sommets:  \n ", actuel->numero);
        for(i=1;i<nbr_sommets+1;i++){
            if(actuel->voisins[i-1]>0  && actuel->voisins[i-1]<nbr_sommets+1){
            printf("%d" ,actuel->voisins[i-1]);
        printf("\n");}
       

}
 actuel = actuel->suivant;
    }

}
