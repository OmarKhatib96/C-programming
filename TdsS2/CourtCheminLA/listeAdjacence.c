#include <stdlib.h>
#include <stdio.h>



#include "file.h"

#include "listeAdjacence.h"

Liste *initialisation()//liste des sommets
{
    Liste *liste = malloc(sizeof(liste));
    Sommet2*sommet = malloc(sizeof(sommet));
   

    if (liste == NULL || sommet == NULL)
    {
        exit(EXIT_FAILURE);
    }

    sommet->suivant = NULL;
    liste->premier = sommet;

    return liste;
}

Liste2 *initialisation3(){
	Liste2 *liste2=malloc(sizeof(liste2));
	Sommet *sommet2 = malloc(sizeof(sommet2));
    if (liste2 == NULL || sommet2 == NULL)
    {
        exit(EXIT_FAILURE);
    }

    sommet2->suivant = NULL;
    liste2->premier = sommet2;

    return liste2;	

	}

Sommet2 *ParcoursListe(Liste * liste,int i){

	if (liste == NULL)
    {
        exit(EXIT_FAILURE);
    }

   Sommet2 *actuel = liste->premier;

    while (actuel ->suivant!= NULL)
    {
	
	if(actuel->numero==i)
		return actuel;
       else{
	actuel=actuel->suivant;



   }

}

	return NULL;
}









