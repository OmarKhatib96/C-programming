#include <stdlib.h>
#include <stdio.h>


#include "listeAdjacence.h"
#include "insertionSommet.h"
Sommet* insertion(Liste *liste, int i)
{
        /* Cr�ation du nouvel �l�ment */
    Sommet *nouveau = malloc(sizeof(*nouveau));
    if (liste == NULL || nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }
    nouveau->numero=i;


    /* Insertion de l'�l�ment au d�but de la liste */
    nouveau->suivant = liste->premier;
    liste->premier = nouveau;
    return nouveau;
}

void insertion2(Sommet*sommetAModifier,int j,int compteurs){

  sommetAModifier->voisins[compteurs]=j;

}



