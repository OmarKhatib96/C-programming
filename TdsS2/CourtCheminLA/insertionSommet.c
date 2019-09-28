#include <stdlib.h>
#include <stdio.h>


#include "listeAdjacence.h"
#include "insertionSommet.h"
Sommet2* insertion(Liste *liste, int i)
{
        /* Création du nouvel élément */



    Sommet2 *nouveau = malloc(sizeof(*nouveau));
    if (liste == NULL || nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }
    nouveau->numero=i;


    /* Insertion de l'élément au début de la liste */
    nouveau->suivant = liste->premier;
    liste->premier = nouveau;



    return nouveau;
}

Sommet* insertion2(Sommet2 *sommetAModifier,int distance,int j){
Sommet *nouveau2=malloc(sizeof(nouveau2));

    if (sommetAModifier == NULL || nouveau2 == NULL)
	exit(EXIT_FAILURE);

  if (sommetAModifier->numero==j)
	distance=0;
	nouveau2->numero=j;
	nouveau2->distance=distance;
       nouveau2->suivant =sommetAModifier->voisins->premier;
	sommetAModifier->voisins->premier=nouveau2;



	return nouveau2;


}



