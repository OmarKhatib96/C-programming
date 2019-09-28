#include <stdlib.h>
#include <stdio.h>





#include "StructureDonnees.h"

Liste * initialisation()
{
    Liste  *liste=malloc(sizeof(*liste));
    Clef *clef = malloc(sizeof(*clef));

    if ( clef == NULL)
    {
        exit(EXIT_FAILURE);
    }

    clef->suivant = NULL;

    liste->premier = clef;
    return liste;
}










