#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "InsertionClef.h"
#include "StructureDonnees.h"
Clef * insertion(Liste * liste,int clef,char mot[40])
{
        /* Création du nouvel élément */
    Clef *nouveau = malloc(sizeof(Clef));
    if (liste== NULL || nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }
    nouveau->clef=clef;
    strcpy(nouveau->mot,mot);
    /* Insertion de l'élément au début de la liste */
    nouveau->suivant = liste->premier;
    liste->premier = nouveau;
    return nouveau;
}




