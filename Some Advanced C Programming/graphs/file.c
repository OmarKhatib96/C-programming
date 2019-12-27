



#include <stdlib.h>
#include <stdio.h>

#include "file.h"


















void Enfilement(File *file, int nvNombre)
{
    Sommet1 *nouveau = malloc(sizeof(*nouveau));
    if (file == NULL || nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }

    nouveau->numero = nvNombre;
    nouveau->suivant = NULL;

    if (file->premier != NULL) /* La file n'est pas vide */
    {
        /* On se positionne à la fin de la file */
        Sommet1 *elementActuel = file->premier;
        while (elementActuel->suivant != NULL)
        {
            elementActuel = elementActuel->suivant;
        }
        elementActuel->suivant = nouveau;
    }
    else /* La file est vide, notre élément est le premier */
    {
        file->premier = nouveau;
    }
}




int Defilement(File *file)
{
    if (file == NULL)
    {
        exit(EXIT_FAILURE);
    }

  int nombreDefile=0;

    /* On vérifie s'il y a quelque chose à défiler */
    if (file->premier != NULL)
    {
        Sommet1 *elementDefile = file->premier;

        nombreDefile = elementDefile->numero;
       file->premier = elementDefile->suivant;
        free(elementDefile);
    }

    return  nombreDefile;
}

File *initialisation2(void)
{
    File *file = malloc(sizeof(*file));
    file->premier = NULL;

    return file;
}








void Afficherf(File *file)
{
    if (file == NULL)
    {
        exit(EXIT_FAILURE);
    }

    Sommet1 *sommet1 = file->premier;

    while (sommet1 != NULL)
    {
        printf("%d ", sommet1->numero);
        sommet1 = sommet1->suivant;
    }

    printf("\n");
}














