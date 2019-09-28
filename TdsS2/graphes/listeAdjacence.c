#include <stdlib.h>
#include <stdio.h>



#include "file.h"

#include "listeAdjacence.h"

Liste *initialisation()
{
    Liste *liste = malloc(sizeof(*liste));
    Sommet*sommet = malloc(sizeof(*sommet));

    if (liste == NULL || sommet == NULL)
    {
        exit(EXIT_FAILURE);
    }

    sommet->suivant = NULL;
    liste->premier = sommet;

    return liste;
}










